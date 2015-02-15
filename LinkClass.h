#pragma once

#include <GeneralDefinitions.h>

//Abstract class for a node in a linked list (not to confuse with GenericNode, which is the same, just templated)
class LinkClass
{
public:
	//Destructor
	virtual ~LinkClass()
		{ JMP_THIS(0x5565A0); }

	//LinkClass
	virtual LinkClass* GetNext()
		{ return Next; }

	virtual LinkClass* GetPrevious()
		{ return Previous; }

	virtual LinkClass* AddBeforeMe(LinkClass* pLink)	//adds pLink to the list, one node before this
														//returns first node of the list
		{
			IsolateFromList();

			Next = pLink->Next;
			Previous = pLink;

			pLink->Next = this;

			if(Next) {
				Next->Previous = this;
			}

			return GetFirst();
		}

	virtual LinkClass* PutAtEndOf(LinkClass* pLink)	//puts this at the end of the list pLink is in
													//returns first node of that list
		{
			IsolateFromList();

			LinkClass* pLast = pLink->GetLast();

			pLast->Next = this;
			Previous = pLast;
			Next = nullptr;

			return GetFirst();
		}

	virtual LinkClass* PutAtBeginningOf(LinkClass* pLink)	//puts this at the beginning of the list pLink is in
														//returns first node of that list (this)
		{
			IsolateFromList();

			LinkClass* pFirst = pLink->GetFirst();

			pFirst->Previous = this;
			Next = pFirst;
			Previous = nullptr;

			return this;
		}

	virtual LinkClass* GetFirst()	//finds the first node in the list
		{
			LinkClass* p = this;

			while(p->Previous) {
				p = p->Previous;

				if(p == this) {
					return this;
				}
			}
			return p;
		}

	virtual LinkClass* GetLast()	//finds the last node in the list
		{
			LinkClass* p = this;

			while(p->Next) {
				p = p->Next;

				if(p == this) {
					return this;
				}
			}
			return p;
		}

	virtual void Isolate()	//removes this from the list
		{
			Next = nullptr;
			Previous = nullptr;
		}

	virtual LinkClass* IsolateFromList()	//removes this from the list
											//returns first node if possible
		{
			LinkClass* pFirst = GetFirst();
			LinkClass* pLast = GetLast();

			if(Next) {
				Next->Previous = Previous;
			}

			if(Previous) {
				Previous->Next = Next;
			}

			Previous = nullptr;
			Next = nullptr;

			if(pFirst != this) {
				return pFirst;
			} else if(pLast && pLast != this) {
				return pLast->GetFirst();
			} else {
				return nullptr;
			}
		}

	//Properties

public:

	LinkClass* Next;
	LinkClass* Previous;
};
