#include<iostream>
#include "player.h"
using namespace std;
template<class T>

class Node
{
	T data;
	Node* next;
	
	public:
		Node(T);
		T getData();
		Node<T>* getNext();
		void setData(T);
		void setNext(Node*);	
};
