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
		: GenericNode(noinit_t())
	{ JMP_THIS(0x40E320); }

protected:
	explicit __forceinline GenericNode(noinit_t)
	{ }

	//Properties

public:

	GenericNode* Next;
	GenericNode* Previous;
};

template <typename T> class Node : public GenericNode
{
public:
	//Destructor
	virtual ~Node() RX;

	//Constructor
	Node()
		: Node(noinit_t())
	{ JMP_THIS(0x40E320); }

protected:
	explicit __forceinline Node(noinit_t)
		: GenericNode(noinit_t())
	{ }
};

class GenericList
{
public:
	//Destructor
	virtual ~GenericList() RX;

	//Constructor
	GenericList()
		: GenericList(noinit_t())
	{ JMP_THIS(0x52ACE0); }

protected:
	explicit __forceinline GenericList(noinit_t)
	{ }

	//Properties

public:

	GenericNode First;
	GenericNode Last;
};

template <typename T> class List : public GenericList
{
public:
	//Destructor
	virtual ~List() RX;

	//Constructor
	List()
		: List(noinit_t())
	{ JMP_THIS(0x52ACE0); }

protected:
	explicit __forceinline List(noinit_t)
		: GenericList(noinit_t())
	{ }
};
