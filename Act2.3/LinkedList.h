#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "Node.h"

using namespace std;

template<class T>
class LinkedList
{
	private:
		Node<T> *head;
		Node<T> *tail;
		int size;
	public:
		LinkedList();
		~LinkedList();
		void deleteAll();
		void addFirst(T data, T dia, T hora, T ip, T razon);
		void create(T data, T dia, T hora, T ip, T razon);
		void printAll();
		
		bool isEmpty();
		void printRange(T inicio, T final);

		
		void mergeSorting(Node<T>** hea);
		void findMiddle(Node<T>* cur, Node<T>** first, Node<T>** second);
		Node<T>* mergeBoth(Node<T>* first, Node<T>* second);
		Node<T>* mergeSort(Node<T>* hea);
		void beginMerge();
};

template<class T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;

}

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	deleteAll();
}

template <class T>
void LinkedList<T>::deleteAll()
{
	Node<T> *current = head;
	while(head != nullptr)
	{
		head = head->getNext();
		delete current;
		current = head;
	}
	size = 0;
}

//Se agrega el primer elemento
template <class T>
void LinkedList<T>::addFirst(T data, T dia, T hora, T ip, T razon)
{
	//incrementar tamano
	size++;
	//poner head con el nuevo Node creado
	head = new Node<T>(data, dia, hora, ip, razon, size);
	tail = head;
}

//agregar un elemento segun el tamano de la lista
template <class T>
void LinkedList<T>::create(T data, T dia, T hora, T ip, T razon)
{
	Node<T> *current = head;
	Node<T> *currPrev = tail;
	if( size == 0)
	{
		//llamar la funcion de agrear el primer elemento
		addFirst(data, dia, hora, ip, razon);
		return;
	}
	
	// Mientras el siguiente no sea igual a null recorrer current al siguiente elemento
	while(current->getNext() != nullptr)
	{
		// recorriendo el current hasta el elemento final
		currPrev = current;
		current = current->getNext();
	}
	
	// crear un nuevo elemento y ligar el siguiente elemento con el elemento de current
	currPrev = current;
	current->setNext(new Node<T>(data, dia, hora, ip, razon, size));
	
	///incrementar size
	size++;
	// Se realiza una pasada mas de current para poder poner el correcto idx
	// si no se fuera a hacer este paso, el ultimo elemento tendria un idx de null y romperia el codigo
	current = current->getNext();
	current->setIdx(size);
}


template <class T>
void LinkedList<T>::printAll()
{
	//para el printall defino temp para el tamano y head
	int tot = size;
	Node<T> *temp = head;
	ofstream out("Ordenado.txt");

	if(tot == 0)
	{
		cout<<"La lista esta vacia!"<<endl;
		return;
	}
	
	while(tot != 0)
	{
		out<<temp->getData()<<" ";
		out<<temp->getDia()<<" ";
		out<<temp->getHora()<<" ";
		out<<temp->getIp()<<" ";
		out<<temp->getRazon()<<endl;
		temp = temp->getNext();
		tot--;
	}
}

template <class T>
void LinkedList<T>::printRange(T inicio, T final)
{
	Node<T> *current = head;
	Node<T> *prev = nullptr;
	string tempInicio = inicio;
	string tempFinal = final;
	
	tempInicio.erase(remove(tempInicio.begin(), tempInicio.end()-6,'.'), tempInicio.end());
	tempFinal.erase(remove(tempFinal.begin(), tempFinal.end()-6,'.'), tempFinal.end());
	
	if(stoll(tempInicio) > stoll(tempFinal))
	{
		string t = inicio;
		inicio = final;
		final = t;
	}
		
	// Paso 4  
	ofstream out("Rangos.txt");
	
	while(current->getIp().compare(inicio) != 0)
	{
		// Si se fuera a llegar hasta final de la lista y todavia no se encuentra el dato
		if(current->getNext() == nullptr)
		{
			cout<<"\nEl elemento no se encontro"<<endl;
			return;
		}
		current = current->getNext();
		prev = current->getPrev();
	}
	
	while(current->getIp().compare(final) != 0)
	{
		cout<<current->getData()<<" ";
		cout<<current->getDia()<<" ";
		cout<<current->getHora()<<" ";
		cout<<current->getIp()<<" ";
		cout<<current->getRazon()<<endl;
		out<<current->getData()<<" ";
		out<<current->getDia()<<" ";
		out<<current->getHora()<<" ";
		out<<current->getIp()<<" ";
		out<<current->getRazon()<<endl;
		current = current->getNext();
	}
	
	cout<<current->getData()<<" ";
	cout<<current->getDia()<<" ";
	cout<<current->getHora()<<" ";
	cout<<current->getIp()<<" ";
	cout<<current->getRazon()<<endl;
	out<<current->getData()<<" ";
	out<<current->getDia()<<" ";
	out<<current->getHora()<<" ";
	out<<current->getIp()<<" ";
	out<<current->getRazon()<<endl;
}

template <class T>
void LinkedList<T>::findMiddle(Node<T>* cur, Node<T>** first, Node<T>** second)
{
	Node<T>* fast;
	Node<T>* slow;
	slow = cur;
	fast = cur->getNext();
	
	while(fast != nullptr)
	{
		fast = fast->getNext();
		if(fast != nullptr)
		{
			slow = slow->getNext();
			fast = fast->getNext();
		}
	}
	
	*first = cur;
	*second = slow->getNext();
	slow->setNext(nullptr); 
}

template <class T>
Node<T>* LinkedList<T>::mergeBoth(Node<T>* first, Node<T>* second)
{
	Node<T>* answer = nullptr;
	
	if(!first)
	{
		return second;
	}
	else if(!second)
	{
		return first;
	}
	
	if(first->getIpVal() <= second->getIpVal())
	{
		answer = first;
		answer->setNext(mergeBoth(first->getNext(),second));
	}
	else
	{
		answer = second;
		answer->setNext(mergeBoth(first,second->getNext()));
	}
	return answer;
}

template <class T>
void LinkedList<T>::mergeSorting(Node<T>** hea){
	Node<T>* cur = *hea;
	Node<T>* first;
	Node<T>* second;
	if(!cur or !cur->getNext())return;
	
	findMiddle(cur,&first,&second);
	
	mergeSorting(&first);
	mergeSorting(&second);
	*hea = mergeBoth(first,second);
}

template <class T>
Node<T>* LinkedList<T>::mergeSort(Node<T>* hea)
{
	mergeSorting(&hea);
	return hea;
}

template <class T>
void LinkedList<T>::beginMerge()
{
	mergeSort(head);
}

#endif
