#pragma once
#include "VertexList.h"
/* What the file does:
 ----------------------
  QNode represents a vertex node in the Queue
*/
class QNode
{
private:
	QNode* m_Next;
	QNode* m_Prev;
	VertexList* _VertexList;
public:
	QNode(VertexList* list=nullptr, QNode* next = nullptr, QNode* prev = nullptr) : _VertexList(list), m_Next(next), m_Prev(prev) {}//ctor
	QNode* getNext() { return m_Next; }//get the next QNode in the queue
	//output: QNode 
	QNode* getPrev() { return m_Prev; }//get the previous QNode in the queue
	//output: QNode

	void setNext(QNode* nextOne) { m_Next = nextOne; }//set the next QNode in the queue
	//input:QNode

	void setPrev(QNode* beforeOne) { m_Prev = beforeOne; }//set the previous QNode in the queue
	//input:QNode

	VertexList* GetVertexList(){ return _VertexList; }
	//output: a vertex list
};
