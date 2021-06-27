# include <iostream>
# include <thread>
# include <string>
# include <chrono>

using namespace std;

void saludo(string nombre, int retardo, int veces) {
    for(int i=1; i<=veces; i++) {
        cout << "Soy " + nombre + "\n";
        this_thread::sleep_for(chrono::milliseconds(retardo));
    }
}

int main(int argc, char* argv[]) {
    const int N = 3;
    thread P[N];

    P[0] = thread(&saludo, "Aurora", 100, 10);
    P[1] = thread(&saludo, "Baltasar", 150, 15),
    P[2] = thread(&saludo, "Carmen", 300, 5);

    P[0].join();
    P[1].join();
    P[2].join();
    
    // alternativamente, podíamos haber ejecutado
    // for (int i=0; i<N; i++)
    //     P[i].join();

    cout << "Fin\n";
    return 0;
}
