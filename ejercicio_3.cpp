//------------------------------------------------------------------------------
// File:   ejercicio3.cpp
// Author: Gabriel Olteanu & Hector Toral
// Date:   sept-oct 2020
// Coms:   ejercicio 3 de la práctica 1 de PSCD
//         Compilar mediante:
//           g++ ejercicio_3.cpp -o ejercicio_3 -std=c++11 -pthread
//------------------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <time.h>       /* time */
#include <iomanip>
#include <cmath>

using namespace std;

// CONSTANTES GLOBALES:
const int N = 3;            // Max numero de Threads
const int TOP = 100;        // Cota maxima del rango
const int BOTTOM = 0;       // Cota minima del rango
const int NUM_REALES = 100; // Max numero de reales que guarda el vector "reales"

void average(const double reales[], double& media) {
    media = 0;
    for (int i = 0; i < NUM_REALES; i++) {
        media += (reales[i] / NUM_REALES);
    }
}

void minmax(const double reales[], double& min, double& max) {
    min = reales[0];
    max = reales[0];
    for (int i = 0; i < NUM_REALES; i++) {
        if (reales[i] < min) min = reales[i];
        if (reales[i] > max) max = reales[i];
    }
}

void sigma(const double reales[], const double media, double& desviacion) {
    double sumatorio = 0;
    desviacion = 0;
    for (int i = 0; i < NUM_REALES; i++) {
        sumatorio += pow(reales[i] - media, 2);
    }
    desviacion = sqrt(sumatorio / (NUM_REALES-1));
}

int main(int argc, char* argv[]) {
    thread P[N];
    double reales[NUM_REALES];

    // Inicializacion del vector "reales"
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        reales[i] = (TOP - BOTTOM) * ((double)rand() / (double)RAND_MAX) + BOTTOM;
    }

    double media;
    double min, max;
    double desviacion;

    P[0] = thread(&average, reales, ref(media));            // Ponemos en marcha el hilo de media
    P[1] = thread(&minmax, reales, ref(min), ref(max));     // Ponemos en marcha el hilo de minmax
    P[0].join();    //me bloqueo hasta que se calcule la media
    P[2] = thread(&sigma, reales, media, ref(desviacion));  // Ponemos en marcha el hilo de la desviacion tipica
    P[1].join();    //me bloqueo hasta que se calcule minmax 
    P[2].join();    //me bloqueo hasta que se calcule la desviacion tipica

    cout << "=======RESULTADOS=======\n";
    cout << "MEDIA = " + to_string(media) + "\n";
    cout << "MIN   = " + to_string(min) + "\n";
    cout << "MAX   = " + to_string(max) + "\n";
    cout << "SIGMA = " + to_string(desviacion) + "\n";
    
    return 0;
}