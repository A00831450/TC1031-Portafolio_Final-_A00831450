#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

template<class T>
class Node
{
	private:
		T data;
		T dia;
		T hora;
		T ip;
		T razon;
		
		Node<T> *next;
		Node<T> *prev;
		int idx;
		string tempIp;
		
	public:
		Node(T data, T dia, T hora, T ip, T razon, int idx);
		Node(T data, T dia, T hora, T ip, T razon, Node<T> *next, Node<T> *prev, int idx);
		
		T getData();
		T getDia();
		T getHora();
		T getIp();
		T getRazon();
		int getIpVal();
		
		Node<T>* getNext();
		Node<T>* getPrev();
		
		void setData(T data);
		void setDia(T dia){
			this->dia = dia;
		}
		void setHora(T hora){
			this->hora = hora;
		}
		void setIp(T ip){
			this->ip = ip;
		}
		void setRazon(T razon){
			this->razon = razon;
		}
		
		
		void setNext(Node<T>* next);
		void setPrev(Node<T>* prev);
		
		int getIdx();
		void setIdx(int Idx);
};

template <class T>
Node<T>::Node(T data, T dia, T hora, T ip, T razon, int idx)
{
	this->data = data;
	this->dia = dia;
	this->hora = hora;
	this->ip = ip;
	this->razon = razon;
	this->next = nullptr; //NULL
	this->prev = nullptr;
	this->idx = idx;
}

template <class T>
Node<T>::Node(T data, T dia, T hora, T ip, T razon, Node<T> *next, Node<T> *prev, int idx)
{
	this->data = data;
	this->dia = dia;
	this->hora = hora;
	this->ip = ip;
	this->razon = razon;
	this->next = next;
	this->prev = prev;
	this->idx = idx;
}

template <class T>
T Node<T>::getData()
{
	return data;
}

template <class T>
T Node<T>::getDia()
{
	return dia;
}

template <class T>
T Node<T>::getHora()
{
	return hora;
}

template <class T>
T Node<T>::getIp()
{
	return ip;
}

template <class T>
T Node<T>::getRazon()
{
	return razon;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <class T>
Node<T>* Node<T>::getPrev()
{
	return prev;
}

template <class T>
int Node<T>::getIdx()
{
	return idx;
}

template <class T>
int Node<T>::getIpVal()
{
	this->tempIp = ip;
	this->tempIp.erase(remove(this->tempIp.begin(), this->tempIp.end()-6,'.'), this->tempIp.end());
	return stoll(tempIp);
}

template <class T>
void Node<T>::setData(T data)
{
	this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
	this-> next = next;
}

template <class T>
void Node<T>::setPrev(Node<T>* prev)
{
	this->prev = prev;
}

template <class T>
void Node<T>::setIdx(int idx)
{
	this->idx = idx;
}

#endif
