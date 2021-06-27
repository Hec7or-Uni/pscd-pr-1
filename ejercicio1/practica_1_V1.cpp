# include <iostream>
# include <thread>
# include <string>
# include <chrono>

using namespace std;

void saludo(string nombre, int retardo, int veces) {
    for(int i=1; i<=veces; i++) {
        cout << "Soy " << nombre << endl;
        this_thread::sleep_for(chrono::milliseconds(retardo));
    }
}

int main(int argc, char* argv[]) {
    thread th_1(&saludo, "Aurora", 100, 10);
    thread th_2(&saludo, "Baltasar", 150, 15);
    thread th_3(&saludo, "Carmen", 300, 5);

    th_1.join();
    th_2.join();
    th_3.join();

    cout << "Fin\n";
    return 0;
}
