#include "queue.h"
 
using namespace std;
 
// Constructor por defecto
template<typename T>
Queue<T>::Queue()
{
	m_num_nodes = 0;
	m_head = NULL;
}



// Destructor 
template<typename T>
Queue<T>::~Queue()
{
}


 
// Insertar nuevo elemento
template<typename T>
void Queue<T>::push(T data_)
{
	Node<T> *new_node = new Node<T> (data_);
	Node<T> *temp = m_head;
	if (!m_head)
	{
		m_head = new_node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	m_num_nodes++;
}
 
 
// Concatenar a otra Cola
template<typename T>
void Queue<T>::concat(Queue queue)
{
	Node<T> *temp2 = queue.m_head;
	while (temp2)
	{
		push(temp2->data);
		temp2 = temp2->next;
	}
}
 

// Eliminar todos los nodos
template<typename T>
void Queue<T>::del_all()
{
	m_head->delete_all();
	m_head = 0;
}

 



// Eliminar por posición del nodo
template<typename T>
void Queue<T>::del_by_position(int pos)
{
	Node<T> *temp = m_head;
	Node<T> *temp1 = temp->next;
	if (pos < 1 || pos > m_num_nodes)
	{
		cout << "Fuera de rango " << endl;
	}
	else if (pos == 1)
	{
		m_head = temp->next;
	}
	else
	{
		for (int i = 2; i <= pos; i++)
		{
			if (i == pos)
			{
				Node<T> *aux_node = temp1;
				temp->next = temp1->next;
				delete aux_node;
				m_num_nodes--;
			}
			temp = temp->next;
			temp1 = temp1->next;
		}
	}
}


// Eliminar por posición del nodo
template<typename T>
void Queue<T>::pop()
{
	del_by_position(1);
}


// Llenar la Cola por teclado
template<typename T>
void Queue<T>::fill_by_user(int dim)
{
	T element;
	for (int i = 0; i < dim; i++)
	{
		cout << "Ingresa el elemento " << i + 1 << endl;
		cin >> element;
		push(element);
	}
}
 

 
// Usado por el método intersección
template<typename T>
void insert_sort(T a[], int size)
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i-1; j>= 0 && a[j+1] < a[j]; j--)
		{
			temp = a[j+1];
			a[j+1] = a[j];
			a[j] = temp;
		}
	}
}


// Elimir números que coinciden en 2 Queues
template<typename T>
void Queue<T>::nointersection(Queue<T> queue_2)
{
	Node<T> *temp = m_head;
	Node<T> *temp2 = queue_2.m_head;
	// Creo otra Queuea
	Queue intersection_queue;
	int num_nodes_2 = queue_2.m_num_nodes;
	int num_inter = 0;
	// Creo 2 vectores dinámicos
	T *v1 = new T[m_num_nodes];
	T *v2 = new T[num_nodes_2];
	// Lleno los vectores v1 y v2 con los datas de la queuea original y segunda queuea respectivamente
	int i = 0;
	while (temp)
	{
		v1[i] = temp->data;
		temp = temp->next;
		i++;
	}
	int j = 0;
	while (temp2)
	{
		v2[j] = temp2->data;
		temp2 = temp2->next;
		j++;
	}
	// Ordeno los vectores
	insert_sort(v1, m_num_nodes);
	insert_sort(v2, num_nodes_2);
	// Índice del 1er vector (v1)
	int v1_i = 0;
	// Índice del 2do vector (v2)
	int v2_i = 0;
	// Mientras no haya terminado de recorrer ambas Queues:
	while (v1_i < m_num_nodes && v2_i < num_nodes_2)
	{
		if (v1[v1_i] == v2[v2_i])
		{
			intersection_queue.push(v1[v1_i]);
			v1_i++;
			v2_i++;
			num_inter++;
		}
		else if (v1[v1_i] < v2[v2_i])
		{
			v1_i++;
		}
		else
		{
			v2_i++;
		}
	}
	// Solo si hay alguna intersección, la elimino
	if (num_inter > 0)
	{
		Node<T> *temp3 = intersection_queue.m_head;
		T *v3 = new T[intersection_queue.m_num_nodes];
		int h = 0;
		while (temp3)
		{
			v3[h] = temp3->data;
			temp3 = temp3->next;
			h++;
		}
		for(int u=0; u<intersection_queue.m_num_nodes ; u++ )
		{
			int borrar=search(v3[u]);	
			del_by_position(borrar);
		}
	} 
}




 
// Imprimir la cola
template<typename T>
void Queue<T>::print()
{
	Node<T> *temp = m_head;
	if (!m_head)
	{
		cout << "La Cola está vacía " << endl;
	}
	else
	{
		while (temp)
		{
			temp->print();
			if (!temp->next)
			{
				cout << "NULL";
			}
			temp = temp->next;
		}
	}
	cout << endl << endl;
}


// Buscar el dato de un nodo
template<typename T>
int Queue<T>::search(T data_)
{
	Node<T> *temp = m_head;
	int cont = 1;
	int cont2 = 0;
	while (temp)
	{
		if (temp->data == data_)
		{
			return cont;			
			cont2++;
		}
		temp = temp->next;
		cont++;
	}
	if (cont2 == 0)
	{
		cout << "No existe el dato " << "\n";
		return 0;
	}
	cout << endl << endl;
}




// Sobrecarga del operador +
template<typename T>
Queue<T> operator+ (Queue<T> a, Queue<T> b)
{
	Queue<T> c;
 	c.concat(a);
	c.concat(b);
	return c;
}


// Sobrecarga del operador -
template<typename T>
Queue<T> operator- (Queue<T> a, Queue<T> b)
{
	Queue<T> c;
	c.concat(a);
 	c.nointersection(b);
	return c;
}

