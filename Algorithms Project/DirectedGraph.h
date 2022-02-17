#pragma once
#include "VertexList.h"
#include "VertexQueue.h"
/* What the file does:
 ----------------------
  this is the main graph
*/
class DirectedGraph
{
private:
	VertexList* _NeighborsList;	//array of vertrex lists
	int* _d;//array of the shortest tracks from the origin vertex to any other vertex in the graph
	int* _p;// the parents indexes array for all of the vertexes
	int _arraySize;// the amount of vertexes in the graph(it will never be changed).
	bool _isEmptyGraph;// true if the graph is empty, else false.

	bool isValidVertex(int vertexNumberToCheck)const { return (vertexNumberToCheck >= 1 && vertexNumberToCheck <= _arraySize);}//checks if the vertex we got is valid
	//input:vertex Number To Check output:true if the vertex is valid, else false

	void BFS(int s);//The BFS algorithm as we leaned in class
	//input:origin vertex

	void deleteEdgesThatDontMeetTheCondition(bool isConditionA=true);// i'm explaining in the next line.
	//input: a boolean varialble-if it's true, we need to do condition of section B' of the algorithm (according to the pdf), else we do section of section D' of the algorithm.

	DirectedGraph buildTgraph();// i'm explaining in the next line.
	//output: A transpse graph of the same graph that has been used for calling the method

	void removeList(int listNumber);// i'm explaining in the next line.
	//input: a vertex number that we are going to delele all of his neighbors from his neighbors' list


	DirectedGraph GetOnlyAndAllTheShortestPathsFromStoT(int s, int t);// i'm explaining in the next line.
/*
input:an origin vertex = u.
output:
Sub-graph of the input graph, that contains all (and only all!) the shortest paths'
 from the origin vertex to the destination vertex.
*/

public:
	DirectedGraph(int amountOfVertexesOnGraph, bool isEmptyGraph = true,bool getInputFromUser=true);//ctor="MakeEmptyGraph"
	//input: amount Of Vertexes On Graph,a boolean variable that says if the graph is going to be empty,and another boolean -if it's true we are going to get input from user, else we are not going to.

	DirectedGraph(DirectedGraph const&);//copy ctor
	
	~DirectedGraph();//dtor

	void ReadGraph();//get's input from user the ctor may use it if needed.

	bool IsAdjacent(int u, int v)const;
	//input: an origin vertex=u,a destination vertex=v output:return true if the edge (u,v) belongs to the graph, else returns false.

	const VertexList& GetAdjList(int u);// i'm explaining in the next line.
	//input: a vertex output:returns a linked list of the vertex's neighbors.

	void AddEdge(int u, int v);//adds an edge to the graph.
	//input:an origin vertex=u

	void PrintGraph()const;//prints the graph
		
	void RemoveEdge(int u, int v);//removes an edge from the graph
	//input:an origin vertex=u

	bool isEmpty()const { return _isEmptyGraph; }// i'm explaining in the next line.
	//output: true if the graph is empty, else returns false.

	const DirectedGraph& operator=(const DirectedGraph&);

	static void runAlgorithmAndPrintResult(DirectedGraph& input,int s,int t);

};