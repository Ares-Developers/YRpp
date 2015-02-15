//General linked list class

#pragma once

#include <YRPPCore.h>

class GenericNode
{
public:
	//Destructor
	virtual ~GenericNode() RX;

	//Constructor
	GenericNode()
		{ JMP_THIS(0x40E320); }

	//Properties

public:

	GenericNode* Next;
	GenericNode* Previous;

protected:
	GenericNode(bool) { }
};

template <typename T> class Node : public GenericNode
{
public:
	//Destructor
	virtual ~Node() RX;

	//Constructor
	Node() : GenericNode(false)
		{ JMP_THIS(0x40E320); }

protected:
	Node(bool) : GenericNode(false) { }
};

class GenericList
{
public:
	//Destructor
	virtual ~GenericList() RX;

	//Constructor
	GenericList()
		{ JMP_THIS(0x52ACE0); }

	//Properties

public:

	GenericNode First;
	GenericNode Last;

protected:
	GenericList(bool) { }
};

template <typename T> class List : public GenericList
{
public:
	//Destructor
	virtual ~List() RX;

	//Constructor
	List() : GenericList(false)
		{ JMP_THIS(0x52ACE0); }

protected:
	List(bool) : GenericList(false) { }
};
