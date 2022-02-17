#include "VertexQueue.h"

void VertexQueue::MakeEmpty()
{
	//in this implemation we dont delete the memory we allocated because 
	//delete all the elements of the Queue
	//don't forget to check allocation and etc.
	while (_head != nullptr)
	{
		DeQueue();
	}
}

QNode* VertexQueue::VertexQueue::Front()const
{
	if (IsEmpty())
	{
		cout << "invalid input " << endl;
		exit(1);
	}
	return _head;
}

void VertexQueue::EnQueue(VertexList* add)
{
	QNode* newVertex= new QNode(add);
	assert(newVertex);
	if (IsEmpty())
	{
		_head = _tail = newVertex;
	}
	else
	{
		_tail->setNext(newVertex);
		newVertex->setPrev(_tail);
		_tail = newVertex;
	}
}
QNode VertexQueue::DeQueue()
{
	if (IsEmpty())
	{
		cout << "invalid input " << endl;
		exit(1);
    }
	QNode tempHead(*_head);
	QNode* PointerToHead = _head;
	if(_head!=_tail)
	{
		_head = _head->getNext();
		_head->setPrev(nullptr);
	}
	if (_head == _tail)//in case we will have an empty queue in the end
	{
		_tail = _head = nullptr;
	}
	delete PointerToHead;
	return tempHead;
}
