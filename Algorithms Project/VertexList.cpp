#include "VertexList.h"

void VertexList::addNodeToTheEndOfList(int v)
{
	Vertex* addToEnd=createVertex(nullptr, nullptr, v);
	if (isEmptyList())//if the list is empty
	{
		_head =_tail = addToEnd;
	}
	else
	{
		_tail->setNext(addToEnd);
		addToEnd->setPrev(_tail);
		_tail = addToEnd;
	}
}

void VertexList::findVertexAndDisconnectFromEdge(int v)
{
	Vertex* VerToDelete=this->getVertex(v);
	if (!VerToDelete)//try to delete a vertex that does not exist
	{
		cout << "invalid input " << endl;
		exit(1);
	}

	if (VerToDelete ==_head)//we are going to delete the head
	{
		if (_head->getNext() == nullptr)
		{
			delete _head;
			_head = _tail = nullptr;
		}
		//delete and update the list is empty (and the tail as well)
		else
		{
			_head = _head->getNext();
			_head->setPrev(nullptr);
			delete VerToDelete;
		}
		return;
	}

	if (VerToDelete == _tail)//we are going to delete the tail
	{	
		_tail=_tail->getPrev();
		 _tail->setNext(nullptr);
		delete VerToDelete;
		return;
	}
	//else
	Vertex* prev = VerToDelete->getPrev();
	Vertex* next = VerToDelete->getNext();
	prev->setNext(next);
	next->setPrev(prev);
	delete VerToDelete;
	return;
}

Vertex* VertexList::createVertex(Vertex* prev, Vertex* next, int vertexNumber)const
{
	Vertex* newVertex = new Vertex(vertexNumber, next,prev);
	assert(newVertex);
	return newVertex;
}

Vertex* VertexList::getVertex(int lookforThis)const//returns nullptr if it does not exist;
{
	if (this->isEmptyList())//if list is empty
		return nullptr;

		Vertex* curr = _head;
		while (curr)
		{
			if (curr->GetVertexNumber() == lookforThis)
				return curr;
			curr = curr->getNext();
		}
		return curr;
}

VertexList::~VertexList()
{
	for (Vertex* ptr=_head;_head;ptr=_head)
	{
		_head = _head->getNext();
			delete ptr;
	}
}

void VertexList::printList(int listNumber)const
{
	Vertex* curr = _head;
	while (curr)
	{
		cout << "\t" << listNumber << "\t" << curr->GetVertexNumber() << endl;
		curr = curr->getNext();
	}
}
