#include "Header1.h"
#include "Header.h"
int main()
{
	GraphMatrix G(5);
	G.addEdge(0, 1);
	G.addEdge(2, 4);
	G.addEdge(2, 3);
	G.addEdge(1, 3);
	cout << "IS EDGE :" << G.isEdge(2, 3) << endl;;
	G.removeEdge(2, 3);
	cout << "IS EDGE :" << G.isEdge(2, 3) << endl;;
	G.print();
	cout << endl;
	Graph g(5);
	g.insertEdge (0, 2);
	g.insertEdge(2, 4);
	g.insertEdge(1, 4);
	g.insertEdge(2, 3);
	g.insertEdge(3, 4);
	g.showGraphStructure();
	g.BFS();
}