#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Bitacora.h"

using namespace std;

template <class T>
void merge(vector<T>& a, int inicio, int mitad, int fin){
	int i = inicio, j = mitad + 1, k = 0;
	vector<T> aux(fin - inicio + 1);
	
	while (i <= mitad && j <= fin){
		if (a[i].orden < a[j].orden){
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

template <class T>
void ordenaMerge(vector<T>& a, int inicio, int fin){
	
	int mitad;
	if(inicio < fin){
		
		mitad = (inicio + (fin - 1)) / 2;
		ordenaMerge(a,inicio,mitad);
		ordenaMerge(a,mitad+1,fin);
		merge(a,inicio,mitad,fin);
		
	}
}

int busqSecuencial(vector<int> v, int n, int dato){
    for(int i = 0; i < n; i++){
        if(v[i] == dato){
            return i;
        }
    }
    return -1;
}


//A causa de que solamente se ingresa el mes y el dia, la lista de fechas puede tener un error de muestra.
//No necesariamente se regresara el dato mas reciente a base de la hora.
//Fue platicado en clase y fue determinado que se mantendra asi el algoritmo
template <class T>
int busquedaBinariaRecursiva(vector<T>& a, int min, int max, int dato)
{
	int key = (min + max)/2;
	if(dato == (a[key].orden - a[key].regionOrden()))
	{
		return key;
	}
	else if(dato < (a[key].orden - a[key].regionOrden()))
	{
		return busquedaBinariaRecursiva(a,min,key-1,dato);
	}
	else
	{
		return busquedaBinariaRecursiva(a,key + 1,max,dato);
	}
	return -1;
}

int main()
{
	ifstream in("bitacora.txt");
	
	vector<Bitacora> lista;
	string linea;
	string mes;
	int dia;
	string hora;
	string ip;
	string razon;
	
	int orden = 0;
	
	
	cout<<"Bienvenido! Favor de esperar a que se termine el ordenamiento"<<endl;
	if(in != NULL)
	{
		while(in >> mes)
		{
			in>>dia>>hora>>ip;
			getline(in, razon);
			lista.push_back(Bitacora(mes,dia,hora,ip,razon,orden));
		}
	}
	int fin = lista.size();
	ordenaMerge(lista,0,fin-1);
	
	string mesInicio;
	int diaInicio;
	
	cout<<"Cual es el mes que desea iniciar la busqueda: "<<endl;
	cin>>mesInicio;
	cout<<"Cual es el dia que desea iniciar la busqueda: "<<endl;
	cin>>diaInicio;
	
	string mesFinal;
	int diaFinal;
	
	cout<<"Cual es el mes que desea finalizar la busqueda: "<<endl;
	cin>>mesFinal;
	cout<<"Cual es el dia que desea finalizar la busqueda: "<<endl;
	cin>>diaFinal;
	
	Bitacora busquedaInicio = Bitacora(mesInicio, diaInicio, "0", "0", "0", 0);
	Bitacora busquedaFinal = Bitacora(mesFinal, diaFinal, "0", "0", "0", 0);
	
	int idxInicio = busquedaBinariaRecursiva(lista,0,fin,busquedaInicio.orden);
	int idxFinal = busquedaBinariaRecursiva(lista,0,fin,busquedaFinal.orden);
	
	for(int i = idxInicio; i <= idxFinal; i++)
	{
		lista[i].printBitacora();
	}
	
	in.close();
	// Paso 4  

	ofstream out ("Rangos.txt");
	for(int i = idxInicio; i <= idxFinal; i++)
	{
		out<<lista[i].mes<<" "<<lista[i].dia<<" "<<lista[i].hora<<" "<<lista[i].ip<<" "<<lista[i].razon<<endl;
	}
	out.close();
	
	//paso 5
	ofstream outOrdenado ("Ordenado.txt");
	for(int i = 0; i <= fin; i++)
	{
		outOrdenado<<lista[i].mes<<" "<<lista[i].dia<<" "<<lista[i].hora<<" "<<lista[i].ip<<" "<<lista[i].razon<<endl;
	}
	outOrdenado.close();
};
