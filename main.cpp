#include <iostream>
 
#include "queue.h"
#include "queue.cpp"
 
using namespace std;
 
int main()
{
	Queue<int> queue_1;
	Queue<int> queue_2;
	queue_1.push(1);
	queue_1.push(2);
	queue_1.push(3);
	queue_2.push(4);
	queue_2.push(5);
	queue_2.push(6);
    
	int element;
	int pos;
 
	cout<< "Cola A:";
	queue_1.print();
	cout<<"\n";
	cout<< "Cola B:";
	queue_2.print();


	cout << "Agrega un elemento a A: " << endl;
	cin >> element;
	queue_1.push(element);
	queue_1.print();
 
	cout << "Busca un elemento en A: " << endl;
	cin >> element;
	int r= queue_1.search(element);
	if(r != 0)
	{	
		cout<<"El dato se encuentra en la posición: " << queue_1.search(element)<<"\n";
	}


	cout << "Función pop:" << "\n";
	queue_1.pop();
	queue_1.print();	


	cout << "Colas A y B concatenadas: " << endl;
	queue_1.concat(queue_2);
	queue_1.print();

	cout<<"A + B:  ";
	Queue <int> c;
	c= queue_1+queue_2;
	c.print();


	cout<<"A - B:  ";
	Queue <int> d;
	d= queue_1-queue_2;
	d.print();
 
 
	queue_1.del_all();
	queue_1.print();
 
	return 0;
}
