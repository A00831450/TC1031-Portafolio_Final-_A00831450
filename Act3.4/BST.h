#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <vector>

#include "ipAccess.h"
#include "Node.h"

using namespace std;

class BST
{
	private:
		Node *root;
		vector<ipAccess> listaTop;
	public:
		BST(){
			root = nullptr;
		}
		~BST(){
			destroy(root);
		}
		
		void destroy(Node *node){
			if(node != nullptr){
				destroy(node->getLeft());
				destroy(node->getRight());
				delete node;
			}
		}
		
		void beginInorden()
		{
			// pasra la raiz
			inorden(root);
		}
		void inorden(Node *tree)
		{
			if(tree != NULL)
			{
				inorden(tree->getLeft());
				cout<<tree->getData();
				cout<<"   "<<tree->getIp()<<endl;
				inorden(tree->getRight());
			}
		}
		
		bool search(int data){
			Node *current = root;
			while(current != nullptr){
				if(current->getData() == data){
					return true;
				}
				
				current = ((data < current->getData())? current->getLeft() : current->getRight());
			}
			return false;
		}
		
		void insert(int data, string ip){
			Node *current = root;
			Node *father = nullptr;
			
			while(current != nullptr){
				if(current->getData() == data)
				{
					
				}
				father = current;
				current = (current->getData() > data)? current->getLeft() : current->getRight();
			}
			
			if(father == nullptr){
				root = new Node(data,ip);
				//listaTop.push_back(data);
				listaTop.push_back(ipAccess(data,ip,ip));
			}else{
				if(father->getData() > data)
				{
					father->setLeft(new Node(data,ip));
					//listaTop.push_back(data);
					listaTop.push_back(ipAccess(data,ip,ip));
					//listaCinco(data,ip);
				}
				else
				{
					father->setRight(new Node(data,ip));
					//listaTop.push_back(data);
					listaTop.push_back(ipAccess(data,ip,ip));
					//listaCinco(data,ip);
				}
			}
		}
		
		void listaCinco()
		{
			ordenaMerge(listaTop,0,listaTop.size()-1);
		}
	void merge(vector<ipAccess>& a, int inicio, int mitad, int fin){
		int i = inicio, j = mitad + 1, k = 0;
		vector<ipAccess> aux(fin - inicio + 1);
		
		while (i <= mitad && j <= fin){
			if (a[i].getAccess() < a[j].getAccess()){
				aux[k] = a[i];
				i++;
			} else {
				aux[k] = a[j];
				j++;
			}
			k++;		
		}
		
	    while (i <= mitad)
	    {
	        aux[k] = a[i];
	        k++;
	        i++;
	    }
	    
	    while (j <= fin)
	    {
	        aux[k] = a[j];
	        k++;
	        j++;
	    }
	
	    for (i = inicio; i <= fin; i++){
	        a[i] = aux[i - inicio];
	    }
	    
	}
	
	void ordenaMerge(vector<ipAccess>& a, int inicio, int fin){
		
		int mitad;
		if(inicio < fin){
			
			mitad = (inicio + (fin - 1)) / 2;
			ordenaMerge(a,inicio,mitad);
			ordenaMerge(a,mitad+1,fin);
			merge(a,inicio,mitad,fin);
			
		}
	}
		
		void printListaCinco()
		{
			listaCinco();
			for(int i = listaTop.size()- 1; i > listaTop.size()-6; i--)
			{
				cout<<"Accesos: "<<listaTop[i].getAccess()<<" IP: "<<listaTop[i].getIp()<<endl;
			}
		}
		
		int howManyChildren(Node *node){
			int number = 0;
			if(node->getLeft() != nullptr){
				number++;
			}
			if(node->getRight() != nullptr){
				number++;
			}
			return number;
		}
};

#endif
