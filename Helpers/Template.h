#ifndef HELPER_TEMPLATE_H
#define HELPER_TEMPLATE_H

#include <Syringe.h>

#include <ObjectClass.h>
#include <GeneralDefinitions.h>
#include <CellSpread.h>
#include <MapClass.h>
#include <functional>
#include <hash_map>

// here be dragons(plenty)


// return functors

template<typename T>
class retfunc {
protected:
	REGISTERS *R;
	DWORD retAddr;
public:
	retfunc(REGISTERS *r, DWORD addr) : R(r), retAddr(addr) {};
	int operator()( T Result ) {
		R->set_EAX((DWORD)Result);
		return retAddr;
	}
};

template<typename T>
class retfunc_fixed : public retfunc<T> {
protected:
	T Result;
public:
	retfunc_fixed(REGISTERS *r, DWORD addr, T res) : retfunc(r, addr), Result(res) {};
	int operator()() {
		R->set_EAX((DWORD)Result);
		return retAddr;
	}
};


// invalid pointers

template<typename T1, typename T2>
void AnnounceInvalidPointerMap(stdext::hash_map<T1, T2> &map, void *ptr) {
	stdext::hash_map<T1, T2>::iterator i = map.find(reinterpret_cast<T1>(ptr));
	if(i != map.end()) {
		map.erase(i);
	}

	for(i = map.begin(); i != map.end(); ++i) {
		if(ptr == ((void *)(i->second))) {
			map.erase(i->first);
		}
	}
}

template<typename T1>
void AnnounceInvalidPointer(T1 elem, void *ptr) {
	if(ptr == (void *)elem) {
		elem = NULL;
	}
}


// cell spread functors

class CellSpreadApplicator
	: public std::binary_function<const ObjectClass *, const CellStruct *, void> {
	public:
		virtual void operator() (ObjectClass *obj, CellStruct *origin) {
		
		}
};

class CellSpreadIterator {
protected:
	CellStruct *origin;
	DWORD radius;
	DWORD position;
	CellSpreadApplicator callback;
	
	public:
		CellSpreadIterator(CellSpreadApplicator &_callback, CellStruct *_origin, DWORD _radius) 
			: callback(_callback), origin(_origin), radius(_radius), position(0)
			{ }

		void Apply() {
			DWORD countCells = CellSpread::NumCells(radius);

			for(; position < countCells; ++position) {
				CellStruct tmpCell = CellSpread::GetCell(position);
				tmpCell += *origin;
				if(MapClass::Global()->CellExists(&tmpCell)) {
					CellClass *c = MapClass::Global()->GetCellAt(&tmpCell);
					for(ObjectClass *curObj = c->GetContent(); curObj; curObj = curObj->NextObject) {
						callback(curObj, origin);
					}
				}
			}
		}

};


// trajectory functors

#include <Helpers\Other.h>
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
			CellClass *Cell = MapClass::Global()->GetCellAt(&*i);
			Callback(Cell);
		}
	}
};

#endif
