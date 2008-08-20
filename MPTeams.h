#ifndef MPTEAMS_H
#define MPTEAMS_H

// these classes handle alliances between players, eg Team:A B C D in the frontend

class MPTeam
{
public:
	//Destructor
	virtual ~MPTeam()
		{ THISCALL(0x5D8C80); }

	virtual bool IsTeamIncluded(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x5D8C90); }

	virtual bool SetPlayerTeam(int idxPlayer)
		{ PUSH_VAR32(idxPlayer); THISCALL(0x5D8CB0); }

	void AddToList(HWND hWnd)
		{ PUSH_VAR32(hWnd); THISCALL(0x5D8D10); }

	//Constructor
protected:
	MPTeam(wchar_t **title, int idx)
		{ PUSH_VAR32(idx); PUSH_VAR32(title); THISCALL(0x5D8C50); }


	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

  PROPERTY(wchar_t *, Title);
  PROPERTY(int, idx);
}

class MPCombatTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPCombatTeam()
		{ }

	virtual bool IsTeamIncluded(int idx)
		{ return MPTeam::IsTeamIncluded(idx) != 0; }

	virtual bool SetPlayerTeam(int idx)
		{ return MPTeam::SetPlayerTeam(idx) != 0; }

	//Constructor
	MPCombatTeam(int idx)
		{ SET_REG32(ECX, idx); CALL(0x5C1030); }
}


class MPSiegeDefenderTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPSiegeDefenderTeam()
		{ }

	virtual bool IsTeamIncluded(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x5CAE70); }

	//Constructor
	MPSiegeDefenderTeam()
		{ THISCALL(0x5CAE10); }
}


class MPSiegeAttackerTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPSiegeAttackerTeam()
		{ }

	//Constructor
	MPSiegeAttackerTeam()
		{ THISCALL(0x5CAEB0); }
}

#endif
