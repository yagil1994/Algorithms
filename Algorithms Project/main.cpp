//Yagil Sofer,  ID:205433808
//Amir Mizrahi, ID:311128763
#include "DirectedGraph.h"
/***************************************************************/
/*
 What the program does:
 ----------------------
	The program finds all the shortest paths' between the origin vertex to the destination vertex and only between two of them.
	In addition, it calculates the program's running time

Input:
-----
	-number of vertexes in the graph
	-origin vertex
	-destination vertex
	-edges

Output:
-----
 Sub-graph of the input graph, that contains all (and only all!) the shortest paths'
 from the origin vertex to the destination vertex.

 Data Structures:
 ----------------
	-Queue of linked lists of vertexes
	-Graph(that contains an array of linked lists of vertexes)
	-Linked list of vertexes

How to use the program:
---------------------
 The user needs to send to the program a destination vertex and origin vertex and the amount of vertexes in the graph
 and send the edges(they need to be valid)
*/
/***************************************************************/
int main()
{
	int y = 5;
	int numberOfVertex;//the amount of vertexes on the graph
	int s;//the origin vertex number
	int t;//the destination vertex number
	 cin >> numberOfVertex >> s >> t;
	if (cin.fail()||numberOfVertex < 1)	
	{
		cout << "input invalid " << endl;
		exit(1);
	}
	cin.ignore();
	DirectedGraph G(numberOfVertex,false);//false means we are going to get input into the graph it won't stay empty
	DirectedGraph::runAlgorithmAndPrintResult(G,s, t);
	return 0;
}
