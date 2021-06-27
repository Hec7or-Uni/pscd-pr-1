# include <iostream>
# include <thread>
# include <string>
# include <chrono>
# include <time.h>       /* time */

using namespace std;

void saludo(int id, int retardo, int veces) {
    for(int i = 1; i <= veces; i++) {
        cout << "Soy " + to_string(id) + "\n";
        this_thread::sleep_for(chrono::milliseconds(retardo));
    }
}

int main() {
    const int N = 10;
    thread P[N];

    srand(time(NULL));
    for (int id = 1; id <= N; id++) {
        // GENERACION DE DATOS 
        int retardo = rand() % 200 + 100;
        int veces   = rand() % 10 + 5;
        
        P[id] = thread(&saludo, id, retardo, veces);
    }
    
    for (int i = 1; i <= N; i++)
        P[i].join();

    return 0;
}
