#ifndef HELPER_OTHER_H
#define HELPER_OTHER_H

#include <cmath>
#include <vector>
#include <algorithm>

#include <ObjectClass.h>
#include <GeneralDefinitions.h>
#include <CellSpread.h>
#include <MapClass.h>

#define MID(x) \
	((((x) / 256) * 256) + 128 )

#define XCMP(a, b, v) \
	((v) < 0) ? ((a) >= MID(b)) : (MID(b) >= (a))

#define SCALE(x, v) \
	((v) < 0) ? (MID(x)) : (MID(x))

class XY : public CoordStruct {
public:
	XY(int _x, int _y) {
		X = _x;
		Y = _y;
		Z = 0;
	}

	XY(CoordStruct *crd) {
		X = crd->X;
		Y = crd->Y;
		Z = 0;
	}

	bool operator< (const XY& RHS) {
		if(X > RHS.X) {
			return false;
		}
		if(X == RHS.X) {
			return Y < RHS.Y;
		}
		return true;
	}

	void normalize() {
		X = MID(X);
		Y = MID(Y);
	}
};

class Trajectory {
	XY st;
	XY en;

	int dirX;
	int dirY;

public:
	typedef std::vector<XY> vec;

	Trajectory(XY &s, XY &e)
		: st(s), en(e)
	{
		dirX = st.X < en.X ? 1 : -1;
		dirY = st.Y < en.Y ? 1 : -1;
	}

	Trajectory(int stx, int sty, int enx, int eny)
		: st(stx, sty), en(enx, eny)
	{
		dirX = st.X < en.X ? 1 : -1;
		dirY = st.Y < en.Y ? 1 : -1;
	}

	void path(std::vector<XY> &hitCoords) {
		hitCoords.clear();

		if(MID(st.X) != MID(en.X)) {
			walkX(hitCoords);
		}

		if(MID(st.Y) != MID(en.Y)) {
			walkY(hitCoords);
		}

		std::sort(hitCoords.begin(), hitCoords.end());

		hitCoords.erase(std::unique(hitCoords.begin(), hitCoords.end()), hitCoords.end());
	}

private:
	void walkX(std::vector<XY> &hitCoords) {
		int step = dirX * 256;
		for(int step_x = SCALE(st.X, dirX); XCMP(step_x, en.X, dirX); step_x += step) {
			int step_y = st.Y + static_cast<int>(dirY * stepY(step_x));
			XY temp(step_x, step_y);
			temp.normalize();
			hitCoords.push_back(temp);
		}
	}

	void walkY(std::vector<XY> &hitCoords) {
		int step = dirY * 256;
		for(int step_y = SCALE(st.Y, dirY); XCMP(step_y, en.Y, dirY); step_y += step) {
			int step_x = st.X + static_cast<int>(dirX * stepX(step_y));
			XY temp(step_x, step_y);
			temp.normalize();
			hitCoords.push_back(temp);
		}
	}

	double _tg() {
		return (abs(en.Y - st.Y) * 1.0) / abs(en.X - st.X);
	}

	double stepX(int Y) {
		return (abs(st.Y - Y) / _tg());
	}

	double stepY(int X) {
		return (abs(st.X - X) * _tg());
	}
};

// trajectory functors
#include <Helpers/Other.h>
#include <Helpers/Iterators.h>

class CellSequenceApplicator
	: public std::unary_function<const CellClass *, void> {
	public:
		virtual void operator() (CellClass *cell) {

		}
};

class CellSequence {
	XY sta;
	XY end;

public:
	CellSequence(CoordStruct *From, CoordStruct *To)
	 : sta(From), end(To)
	{
	}

	void Apply(CellSequenceApplicator& Callback) {
		Trajectory T(sta.X, sta.Y, end.X, end.Y);

		Trajectory::vec allCells;

		T.path(allCells);

		for(Trajectory::vec::iterator i = allCells.begin(); i != allCells.end(); ++i) {
			CellClass *Cell = MapClass::Instance->GetCellAt(*i);
			Callback(Cell);
		}
	}
};

#endif
