//------------------------------------------------------------------------------
// File:   ejercicio3.cpp
// Author: Gabriel Olteanu & Hector Toral
// Date:   sept-oct 2020
// Coms:   ejercicio 2 de la práctica 1 de PSCD
//         Compilar mediante:
//           g++ ejercicio_2.cpp -o ejercicio_2 -std=c++11 -pthread
//------------------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <time.h>       /* time */

using namespace std;

void saludo(int id, int retardo, int veces) {
    for(int i = 1; i <= veces; i++) {
        cout << "Soy " + to_string(id) + "\n";
        this_thread::sleep_for(chrono::milliseconds(retardo)); // Bloqueo del Thread durante "retardo" milisegundos
    }
}

int main() {
    const int N = 10;
    thread P[N];

    srand(time(NULL));  // Inicializamos la semilla pseudoaleatoria
    for (int id = 1; id <= N; id++) {
        // GENERACION DE DATOS 
        int retardo = rand() % 200 + 100;
        int veces   = rand() % 10 + 5;
        
        P[id] = thread(&saludo, id, retardo, veces);    // P[id] se pone en marcha
    }
    
    for (int i = 1; i <= N; i++) {
        P[i].join(); // Esperamos a que el proceso "P[i]" termine
    }

    return 0;
}