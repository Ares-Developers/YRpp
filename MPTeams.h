#pragma once

// these classes handle alliances between players, eg Team:A B C D in the frontend

class MPTeam
{
public:
	//Destructor
	virtual ~MPTeam() RX;
	virtual bool IsTeamIncluded(int idx) R0;
	virtual bool SetPlayerTeam(int idxPlayer) R0;

	void AddToList(HWND hWnd)
		{ JMP_THIS(0x5D8D10); }

protected:
	//Constructor
	MPTeam(wchar_t **title, int idx)
		{ JMP_THIS(0x5D8C50); }

	MPTeam(noinit_t)
	{ }


	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	wchar_t* Title;
	int Index;
};

class MPCombatTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPCombatTeam() RX;

protected:
	//Constructor
	MPCombatTeam()
		: MPTeam(noinit_t())
	{ }
};


class MPSiegeDefenderTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPSiegeDefenderTeam() RX;

protected:
	//Constructor
	MPSiegeDefenderTeam()
		: MPTeam(noinit_t())
	{ JMP_THIS(0x5CAE10); }
};


class MPSiegeAttackerTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPSiegeAttackerTeam() RX

	//Constructor
	MPSiegeAttackerTeam()
		: MPTeam(noinit_t())
	{ JMP_THIS(0x5CAEB0); }
};


class MPObserverTeam : public MPTeam
{
public:
	//Destructor
	virtual ~MPObserverTeam() RX

	//Constructor
	MPObserverTeam()
		: MPTeam(noinit_t())
	{ JMP_THIS(0x5C9470); }
};
