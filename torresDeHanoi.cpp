/*
    Hola bienvenido a este programa!

    Este programa permite resolver el problema de las torres de Hanoi. 

    Integrantes:
        1116783-Whisman Lorenzo
        1116842-Jose Reyes
        1105307-Jose Sol
        1114056-Jose Florentino
        1116176-Manuel Guzman
        1115997-Winston Pichardo
        1087257-Jorge Jimenez

        Fecha: 2/10/2023

*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Torre {
private:
    vector<int> discos;

public:
    void push(int disk) {
        discos.push_back(disk); 
    }

    int pop() {
        int top = discos.back(); // Disco en la parte superior de la torre
        discos.pop_back(); // Saca el disco en la parte superior de la torre
        return top; 
    }

    bool estaVacia() {
        return discos.empty();
    }

    void mostrar() {
        for (int i = discos.size() - 1; i >= 0; --i) {
            cout << " " << discos[i] << " "; 
        }
        cout << endl;
    }
};

void moverDisco(Torre& origen, Torre& target) {
    if (!origen.estaVacia()) {
        int disk = origen.pop(); // Saca un disco de la torre de origen.
        target.push(disk); // Coloca el disco en la torre de destino.
    }
}

int hanoi(int n, Torre& origen, Torre& aux, Torre& destino) {
    if (n == 0) {
        return 0; // Si hay 0 discos no hay discos para mover.
    }
    int movimientos = 0;

    // Mover n-1 discos de la fuente a la torre auxiliar usando la torre objetivo como auxiliar
    movimientos += hanoi(n - 1, origen, destino, aux);

    // Mover el disco más grande de la fuente a la torre objetivo
    moverDisco(origen, destino);
    
    movimientos++;

    cout << "Torre A:";
    origen.mostrar();
    cout << "Torre B:";
    aux.mostrar();
    cout << "Torre C:";
    destino.mostrar();
    cout << endl;

    // Mover n-1 discos de la torre auxiliar a la torre objetivo usando la fuente como auxiliar
    movimientos += hanoi(n - 1, aux, origen, destino);

    return movimientos; 
}

int obtenerIntValido() {
    int number;
    while (!(cin >> number)) {
        cout << "\nEntrada inválida: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

bool continuar() {
    string ans;
    cin >> ans;
    for (char& c : ans) {
        c = tolower(c);
    }
    if (ans != "s" && ans != "n") {
        do {
            cout << "Opción inválida.\n";
            cin >> ans;
        } while (ans != "s" && ans != "n");
    }
    return ans == "s";
}

int main() {
    cout << "Ingrese el número de anillos: ";
    int n = obtenerIntValido();

    Torre origen, aux, destino;

    for (int i = n; i >= 1; --i) {
        origen.push(i); // Agrega n discos a la torre de origen.
    }

    cout << "Estado inicial de las torres:" << endl;
    cout << "Torre A:";
    origen.mostrar();
    cout << "Torre B:";
    aux.mostrar();
    cout << "Torre C:";
    destino.mostrar();
    cout << endl;

    int totalMovimientos = hanoi(n, origen, aux, destino);

    cout << "¡Juego completado en " << totalMovimientos << " movimientos!" << endl;

    // correr algoritmo nuevamente
    cout << "¿Desea ver otra solucion? (s/n): ";
    if (continuar()) {
        main();
    }

    return 0;
}
