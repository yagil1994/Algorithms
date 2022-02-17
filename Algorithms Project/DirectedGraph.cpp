#include "DirectedGraph.h"
#include <iostream>

DirectedGraph::DirectedGraph(int amountOfVertexesOnGraph, bool isEmptyGraph, bool getInputFromUser ) :_arraySize(amountOfVertexesOnGraph),_isEmptyGraph(isEmptyGraph),_d(nullptr),_p(nullptr)
{
	_NeighborsList = new VertexList[amountOfVertexesOnGraph];
	assert(_NeighborsList);
	_d = new int[_arraySize];
	assert(_d);
	_p = new int[_arraySize];
		assert(_p);	
		for (int i = 1; i <= amountOfVertexesOnGraph; i++)
		{
			_NeighborsList[i - 1].setVertexListNumber(i);
		}
		if(getInputFromUser)
			ReadGraph();
}
void DirectedGraph::AddEdge(int u, int v)
{
	if (!isValidVertex(u)||!isValidVertex(v))
	{
		cout << "invalid input " << endl;
		exit(1);
	}
	_NeighborsList[u - 1].addNodeToTheEndOfList(v);
}
const VertexList& DirectedGraph::GetAdjList(int u)
{
	if (!isValidVertex(u))
	{
		cout << "invalid input " << endl;
		exit(1);
	}
		return _NeighborsList[u - 1];
}

void DirectedGraph::RemoveEdge(int u, int v)
{
	if (!isValidVertex(u) || !isValidVertex(v))
	{
		cout << "invalid input " << endl;
		exit(1);
	}
		_NeighborsList[u - 1].findVertexAndDisconnectFromEdge(v);
}

void DirectedGraph::PrintGraph()const
{
	cout << endl;
	if (isEmpty())
	{
		cout << "invalid input " << endl;
		exit(1);
	}
	for (int i = 1; i <= _arraySize; i++)
	{
		_NeighborsList[i - 1].printList(i);
	}
}

void DirectedGraph::ReadGraph()
{
	if (!_isEmptyGraph)//in case we are going to get input of edges   ***check it's fine***
	{
		int u, v;	
		cin >> u;
		while (!cin.fail())
		{
			cin >> v;
			if (!cin.fail())
			{
				AddEdge(u, v);
			}
			else
			{
				cout << "invalid input" << endl;
				exit(1);
			}
		cin >> u;
		}
	}
}

bool DirectedGraph::IsAdjacent(int u, int v)const
{
	bool isTheVertexBelongsToTheGraph = true;
	if (!isValidVertex(u))
		isTheVertexBelongsToTheGraph = false;
	if (isTheVertexBelongsToTheGraph)
	{
		if(!_NeighborsList[u - 1].getVertex(v))
			isTheVertexBelongsToTheGraph = false;
	}
	return isTheVertexBelongsToTheGraph;
}

DirectedGraph DirectedGraph::buildTgraph()
{
	DirectedGraph Tgraph(_arraySize,false,false);
	for (int i = 1; i <= _arraySize; i++)
	{
		Vertex* curr = _NeighborsList[i - 1].getHead();
			while (curr)
			{
				Tgraph.AddEdge(curr->GetVertexNumber(), i);
				curr = curr->getNext();
			}
	}
	return Tgraph;
}

DirectedGraph::~DirectedGraph()
{
	delete[] _NeighborsList;
	delete[]_d;
	delete[] _p;
}

DirectedGraph::DirectedGraph(DirectedGraph const& other) :DirectedGraph(other._arraySize, false,false)//copy ctor
{
	*this = other;
}

const DirectedGraph& DirectedGraph::operator=(const DirectedGraph& other)
{	
	if (this != &other)
	{
		_arraySize = other._arraySize;
		_isEmptyGraph = other._isEmptyGraph;
		Vertex* curr = nullptr;
		for (int i = 1; i <= _arraySize; i++) 
		{
			_d[i - 1] = other._d[i - 1];
			_p[i - 1] = other._p[i - 1];
			_NeighborsList[i - 1].setVertexListNumber(other._NeighborsList[i - 1].getVertexListNumber());
			curr = other._NeighborsList[i - 1].getHead();
			while (curr)
			{
				_NeighborsList[i - 1].addNodeToTheEndOfList(curr->GetVertexNumber());
				curr = curr->getNext();
			}
		}	
	}
	return *this;
}

DirectedGraph DirectedGraph::GetOnlyAndAllTheShortestPathsFromStoT(int s, int t)
{
	if (!isValidVertex(s) || !isValidVertex(t))
	{
		cout << "invalid input " << endl;
		exit(1);
	}
	BFS(s);
	deleteEdgesThatDontMeetTheCondition();
	DirectedGraph G_T=buildTgraph();
	G_T.BFS(t);
	G_T.deleteEdgesThatDontMeetTheCondition(false);
	return G_T.buildTgraph();
}

void DirectedGraph::deleteEdgesThatDontMeetTheCondition(bool isConditionA)
{
	if (isConditionA)
	{
		for (int i = 1; i <= _arraySize; i++)
		{
			int u = i;
			Vertex* v = this->_NeighborsList[u - 1].getHead();
			Vertex* next = nullptr;
			while (v)
			{
				int currVserial = v->GetVertexNumber();
				next = v->getNext();
				if (_d[currVserial - 1] != (_d[u - 1] + 1))
				{
					RemoveEdge(u, currVserial);
				}
				v = next;
			}
		}
	}
	else
	{
		for (int i = 1; i <=_arraySize; i++)
		{
			if (_d[i - 1] == static_cast<int>(InitType::infinity))
			{
				this->removeList(i);
			}		
		}
	}
}

void DirectedGraph::BFS(int s)
{
	if (!isValidVertex(s))
	{
		cout << "invalid input " << endl;
		exit(1);
	}

	VertexQueue Q;
	int amountOfVertexesOnGraph = _arraySize;

	for (int i = 0; i < _arraySize; i++)//init
	{
		_p[i] = static_cast<int>(InitType::null);
		_d[i] = static_cast<int>(InitType::infinity);
	}
	Q.EnQueue(&_NeighborsList[s - 1]);
	_d[s-1] = 0;
	while (!Q.IsEmpty())
	{
		 QNode u = Q.DeQueue();
		 int uVertexNumber = u.GetVertexList()->getVertexListNumber();
		 Vertex* CurrNeighbor = u.GetVertexList()->getHead();
		 while(CurrNeighbor)
		 {
			 if (_d[CurrNeighbor->GetVertexNumber() - 1] == static_cast<int>(InitType::infinity))
			 {
				 _d[CurrNeighbor->GetVertexNumber() - 1] = _d[uVertexNumber - 1] + 1;
				 _p[CurrNeighbor->GetVertexNumber() - 1] = uVertexNumber;
				 int vSerialNumber = CurrNeighbor->GetVertexNumber();
				 Q.EnQueue(&_NeighborsList[vSerialNumber - 1]);
			 }
			 CurrNeighbor = CurrNeighbor->getNext();
		 }
	}
}
void DirectedGraph::removeList(int listNumber)
{
	Vertex* curr = _NeighborsList[listNumber - 1].getHead();
	while (curr)
	{
		Vertex* next = curr->getNext();
		 RemoveEdge(listNumber, curr->GetVertexNumber());
		 curr = next;
	}
}
void DirectedGraph::runAlgorithmAndPrintResult(DirectedGraph& input, int s, int t)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	DirectedGraph res=input.GetOnlyAndAllTheShortestPathsFromStoT(s,t);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile(stdout);
	if (!myfile)
	{
		cout << "can not open file " << endl;
	}
	res.PrintGraph();
	myfile <<endl<< "Time taken by function GetOnlyAndAllTheShortestPathsFromStoT is : " << fixed << time_taken << setprecision(9) <<
		" sec" << endl << endl << endl;
	myfile.close();
}