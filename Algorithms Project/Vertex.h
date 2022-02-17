#pragma once
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <iomanip>
#include <chrono>
#include <fstream>
enum class InitType{null = -2,infinity=-1,junk=-3}; //Vertex status
/* What the file does:
 ----------------------
  A stracture that represent a vertex in graph.
*/

class Vertex
{
private:
	int _VertexSerialNumber;
	Vertex* _next;
	Vertex* _prev;
public:

	Vertex(int VertexNum = static_cast<int>(InitType::junk), Vertex* next=nullptr, Vertex* prev=nullptr):
		_VertexSerialNumber(VertexNum),_next(next),_prev(prev){}

	Vertex* getNext()const{ return _next; }	//Get the next vertex in line
	//output: vertex

	Vertex* getPrev()const{ return _prev; } //Get the previous vertex in line
	//output: vertex

	void setNext(Vertex* nextOne) { _next = nextOne; } //Set the next vertrex in line
	//input: vertex

	void setPrev(Vertex* beforeOne) { _prev = beforeOne;} //Set the previous vertrex in line
	//input: vertex

	int GetVertexNumber()const { return _VertexSerialNumber; } //Get the vertex's number
	//output : number of vertex.

	bool setVertex(int newVertexNumber, Vertex* next, Vertex* prev) { _VertexSerialNumber = newVertexNumber; _next = next; _prev = prev; return true;} //Set Number of vertex.
	//input: details of a vertex, output: true if the action succueded.
};
