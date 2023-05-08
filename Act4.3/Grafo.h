#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include "Arista.h"

using namespace std;

template <class T>
class Grafo
{
	private:
		vector<vector<Arista<T>>> listaAdj;
        vector<T> vertices;
        vector<pair<int,string>> fanV;
        int numVertices;
        int findIdx(T vertice);
        
	public:
		Grafo()
		{
			numVertices = 0;
		}
		
        Grafo(vector<T> vertices)
        {
        	this->vertices = vertices;
        	numVertices = vertices.size();
        	vector<Arista<T>> aris;
		    for (int i=0; i<numVertices; i++) 
		    {
		        listaAdj.push_back(aris);
		    }
		}
		
        void insert(Arista<T> aris)
        {
        	int idxOrigen = findIdx(aris.origen);
        	if (idxOrigen == -1) 
		    {
		        // El vértice no existe
		        // Insertamos el nuevo vértice en la lista de vértices
		        vertices.push_back(aris.origen);
		        idxOrigen = numVertices;
		        numVertices++;
		        vector<Arista<T>> aris;
		        listaAdj.push_back(aris);  
		    }
		    // Buscamos el índice donde se encuentra el vértice destino
		    int idxDestino = findIdx(aris.destino);
		    // Validamos si el vértice existe
		    if (idxDestino == -1) 
		    {
		        // El vértice no existe
		        // Insertamos el nuevo vértice en la lista de vértices
		        vertices.push_back(aris.destino);
		        idxDestino = numVertices;
		        numVertices++;
		        vector<Arista<T>> aris;
		        listaAdj.push_back(aris);  
		    }
		    listaAdj[idxOrigen].push_back(aris);
		    
		}
		
        //void remove(Arista<T> aris);
        //void bfs(T vertex);
        //void dfs(T vertex);
        void loadGraph(int n, int m);
        void mayorCinco();
        void bootMaster();
};

template <class T>
void Grafo<T>::loadGraph(int n, int m)
{
	cout<<"Numero de Vertices: "<<n<<endl;
	cout<<"Numero de Movimientos: "<<m<<endl;
	
	for (int i=0; i<numVertices; i++) 
    {
        cout << "Fan out: "<<listaAdj[i].size()<<" "<<vertices[i] << " -> ";
        fanV.push_back(make_pair(listaAdj[i].size(),vertices[i]));
        for (auto arista : listaAdj[i]) 
        {
            cout<<"["<<arista.getDestino()<<"] ";
        }
        cout << endl;
    }
    sort(fanV.begin(), fanV.end());
}

template <class T>
int Grafo<T>::findIdx(T vertice)
{
    auto it = find(vertices.begin(), vertices.end(), vertice);
    if (it != vertices.end()) 
    {
        int index = it - vertices.begin();
        return index;
    } 
    else 
    {
        return -1;
    }
}

template <class T>
void Grafo<T>::mayorCinco()
{
	cout<<"\nLos Nodos con mayor Fan-Out Son: "<<endl;
	for(int i = fanV.size()-1; i > fanV.size()-6; i--)
	{
		cout<<fanV[i].first<<" "<<fanV[i].second<<endl;
	}
}

template <class T>
void Grafo<T>::bootMaster()
{
	int master = fanV[fanV.size()-1].first;
	cout<<"\nLos posibles ips del boot master son: "<<endl;
	int i = fanV.size()-1;
	while(master == fanV[i].first)
	{	
		cout<<"Ip: "<<fanV[i].second<<endl;
		i--;
	}
}
#endif
