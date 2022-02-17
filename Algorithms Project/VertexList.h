#pragma once
#include "Vertex.h"
/* What the file does:
 ----------------------
A stracture that represents a vertex list.
*/
class VertexList
{
private:
	Vertex* _head, *_tail;
	int vertexListNumber;

	bool isEmptyList()const { return _head == nullptr && _tail == nullptr; }
	Vertex* createVertex(Vertex* prev, Vertex* next, int vertexNumber)const;
public:
	VertexList(Vertex* newHead = nullptr, Vertex* newTail = nullptr, int ThevertexListNumber= static_cast<int>(InitType::junk)):_head(newHead), 
		_tail(newTail),vertexListNumber(ThevertexListNumber){} //Ctor
	VertexList(const VertexList&) = delete; //Copy ctor
	~VertexList();//Dtor

	const VertexList& operator=(const VertexList&) = delete;
	
	void addNodeToTheEndOfList(int v); //Add node to the end of a vertex list
	//input: an int representing the node's num

	void findVertexAndDisconnectFromEdge(int v); //Find the vertex that the user asked to disconnect from vertex list.
	//input: an int representing the node's num

	Vertex* getVertex(int lookforThis)const; //Returns a demanded vertex. Returns nullptr if it does not exist.
	//input: an int representing the node's num. output: vertex.

	void printList(int listNumber)const; //Prints a vertexList.
	//input: an int representing the vertex list's num.

	Vertex* getHead()const { return _head; } //Returns the first vertex in a vertexList.
	//output: vertex.

	void setVertexListNumber(int num) { vertexListNumber = num; } //Sets the right number of a vertexList.
	//input:num of vertexList

	int getVertexListNumber()const { return vertexListNumber; } //Get the number of a vertexList.
	//output: num of vertexList.
};