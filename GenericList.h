//General linked list class

#ifndef GENLIST_H
#define GENLIST_H

#include <YRPPCore.h>

class GenericNode
{
public:
	//Destructor
	virtual ~GenericNode() RX;

	//Constructor
	GenericNode()
		JMP_THIS(0x40E320);

	//Properties
	PROPERTY(GenericNode*, Next);
	PROPERTY(GenericNode*, Previous);
};

template <typename T> class Node : public GenericNode
{
public:
	//Destructor
	virtual ~Node() RX;

	//Constructor
	Node()
		JMP_THIS(0x40E320);
};

class GenericList
{
public:
	//Destructor
	virtual ~GenericList() RX;

	//Constructor
	GenericList()
		JMP_THIS(0x52ACE0);

	//Properties
	PROPERTY_STRUCT(GenericNode, First);
	PROPERTY_STRUCT(GenericNode, Last);
};

template <typename T> class List : public GenericList
{
public:
	//Destructor
	virtual ~List() RX;

	//Constructor
	List()
		JMP_THIS(0x52ACE0);
};

#endif
