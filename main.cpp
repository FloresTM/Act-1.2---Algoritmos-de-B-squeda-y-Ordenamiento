// =================================================================
//
// File: main.cpp
// Author: Sebastian Flores Lemus - A01709229
// Date: 03/09/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

using std::ifstream;
using std::ofstream;
using std::vector;
using std::cin;

int main(int argc, char* argv[]) {

  int n, q, k, s; 
  
  // variables auxiliares
  int auxiliar_uno,auxiliar_dos,auxiliar_tres;

  // creamos los vectores
  vector<int> vector_unsorted, vector_sorted;

  // lectura y creacion de archivos
  ifstream archivo(argv[1]); 
  ofstream archivo2(argv[2]);

  archivo >> n;

  for(int i = 0; i< n; i++){
    archivo >> q;
    vector_unsorted.push_back(q); // se guardan los datos
  }

  vector_sorted = vector_unsorted;
  auxiliar_uno = bubbleSort(vector_sorted);
  
  vector_sorted = vector_unsorted;  // lo desordenamos para volverlo a llamar

  auxiliar_dos = selectionSort(vector_sorted);
  
  vector_sorted = vector_unsorted; // lo desordenamos para volverlo a llamar

  auxiliar_tres = insertionSort(vector_sorted);

  archivo2 << auxiliar_uno << " " << auxiliar_dos << " " << auxiliar_tres << endl << endl;

  std::pair <int, int> result;

  archivo >> k;

  for(int i = 0; i < k; i++){
    archivo >> s;
    result = sequentialSearch(vector_sorted,s);
    archivo2 << result.first << " " << result.second << " "; 

    result = binarySearch(vector_sorted, s);
    archivo2 << result.second << endl;
  }

  archivo.close();
  archivo2.close();
  
	return 0;
}
