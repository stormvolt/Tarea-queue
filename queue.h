#ifndef QUEUE_H
#define QUEUE_H
 

#include <iostream>
#include "node.h"
#include "node.cpp"
 
using namespace std;
 
template <class T>
 
class Queue
{
	private:
		Node<T> *m_head;
		int m_num_nodes;

	public:
	        Queue();
	        ~Queue();
 
		void push(T);
		void pop();
		void concat(Queue);
		void del_all();
		void del_by_position(int);
		void fill_by_user(int);
		void nointersection(Queue);
		int search(T);
		void print();
		 

};
 
#endif // QUEUE_H
