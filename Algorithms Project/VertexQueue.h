#pragma once
#include "QNode.h"
/* What the file does:
 ----------------------
 A stracture that represents a queue of vertexes.
*/
class VertexQueue
{
private:
	QNode* _head, * _tail;
	void MakeEmpty();
public:
	VertexQueue():_head(nullptr),_tail(nullptr){}	//Ctor
	~VertexQueue() { MakeEmpty();}					//Dtor
	
	bool IsEmpty()const{ return (_head ==nullptr && _tail==nullptr);}
	//output: true if the queue is empty

	QNode* Front()const;
	//output: the front vertex currently at the queue (vertex list)

	void EnQueue(VertexList* add);
	//input: the vertex list of a graph that should be checked by the BFS algorithem
	
	QNode DeQueue();
	//output: the current front vertex list.
};