#pragma once
#include <iostream>
using namespace std;

class GraphMatrix {
public:
	bool** adjMatrix;
	int numVertices =0;
	GraphMatrix(int numVertices=0); //constructor to set size of matrix
	void addEdge(int i, int j); //marks the edge true in matrix
	void removeEdge(int i, int j); //removes the edge at provided position
	bool isEdge(int i, int j); //checks if edge exits or not, then returns
	void print();
};

GraphMatrix::GraphMatrix(int numVertice)
{
	numVertices = numVertice;
	adjMatrix = new bool* [numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		adjMatrix[i] = new bool[numVertices];
	}
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			 adjMatrix[i][j] = false;
		}
	}
}

void GraphMatrix::addEdge(int i, int j)
{
	adjMatrix[i][j] = true;
	adjMatrix[j][i] = true;
}

void GraphMatrix::removeEdge(int i, int j)
{
	adjMatrix[i][j] = false;
	adjMatrix[j][i] = false;
}

bool GraphMatrix::isEdge(int i, int j)
{
	if (adjMatrix[i][j] == 1)
	{
		return true;
	}
	return false;
}

void GraphMatrix::print()
{
	cout << numVertices << endl;
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			if(adjMatrix[i][j] ==  true)
			{ 
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
			// cout << boolalpha << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}