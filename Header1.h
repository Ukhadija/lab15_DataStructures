#pragma once
#include <iostream>
using namespace std;
/////////////////////////////////


template <class T>
struct node
{
	T data;
	node <T>* next;

	node<T>(T d) {
		data = d;
		next = NULL;
	}
	node<T>() {
		data = 0;
		next = NULL;
	}
};

template <class T>
class Queue {
private:
	node<T>* front;
	node<T>* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	void enqueue(T d)
	{
		node<T>* temp = new node<T>(d);
		/*temp->data = d;
		temp->next = NULL;*/
		if (front == NULL || rear == NULL)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			//node<T>* temp1 = rear;
			rear->next = temp;
			//temp->next = NULL;
			rear = temp;
		}
	}

	T dequeue()
	{
		if (front == NULL || rear == NULL) {
			return NULL;
		}
		else {
			node <T>* temp = front;
			front = front->next;
			return temp->data;
		}
	}

	int Front()
	{
		return front->data;
	}

	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		return false;
	}

	void Display()
	{
		node<T>* p = front;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;

		}
		cout << endl;
	}
};


///////////////////////////////////
class Node
{
public:
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};


class AdjList
{
public:
	Node* head ;

	AdjList(int d =0)
	{
		Node* temp = new Node(d);

		head = temp;

		temp = NULL;
		delete temp;
	}

	void insertAtTail(int d)
	{
		Node* temp = new Node(d);
		
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			Node* p = head;
			while (p->next!= NULL)
			{
				p = p->next;
			}
			p->next = temp;

			temp = NULL;
			delete temp;
		}
	}


};



class Graph
{
public:
	int maxVertices; //max no of vertices in your graph
	int noOfVertices; // initially 0, increments with every call to createVertex function. So
	AdjList* list = NULL;

	Graph(int maxVertice=0)
	{
		maxVertices = maxVertice;
		noOfVertices = 0;
		list = new AdjList[maxVertices];


	}

	void insertEdge(int src, int dest)
	{
		list[src].insertAtTail(dest);
		list[dest].insertAtTail(src);
	}

	void showGraphStructure()
	{
		cout << " vertices : " << endl;
		for (int i = 0; i < maxVertices; i++)
		{
			cout << i << " ";
		}
		cout << endl;

		for (int i = 0; i < maxVertices; i++)
		{
			cout <<"adj "<< i << "->";
			Node* p = list[i].head;
			p = p->next;
			while (p!= NULL )
			{
				
				cout << p->data << "->";
				p = p->next;
			}
			cout << endl;

		}
	}

	void BFS()
	{
		cout << "BFS: \n";
		int start = 0;
		bool* checkVertices = new bool[maxVertices];
		for (int i = 0; i < maxVertices; i++)
		{
			checkVertices[i] = 0;
		}
		Queue <Node*>* q = new Queue<Node*>;
		Node* n = list[start].head;
		//cout <<start <<" ";
		if (n == NULL)
			return;
		q->enqueue(n);
		checkVertices[start] = 1;
		bool check = false;
		while (!q->isEmpty())
		{
			Node* curr = q->dequeue();
			
			if (curr != NULL)
			{
				
				start = curr->data;
				cout << start << " ";
				curr = list[start].head;
				curr = curr->next;
			}
			if (curr == NULL)
			{
				break;
			}
			if (curr != NULL)
			{
				
				while (curr != NULL)
				{
					if (checkVertices[curr->data] == 0)
					{
						
						checkVertices[curr->data] = 1;
						//cout << "fdg" << curr->data << endl;
						q->enqueue(curr);
					}
					curr = curr->next;
				}
			}

			
		}
		delete q;
	}

};

