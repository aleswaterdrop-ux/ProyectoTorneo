#include <iostream>
#include "partido.h"

using namespace std;

class NodoCola {
public:
    Partido partido;
    NodoCola* siguiente;

    NodoCola(Partido p) {
        partido = p;
        siguiente = NULL;
    }
};

class ColaPartidos {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    ColaPartidos() {
        frente = NULL;
        final = NULL;
    }

    bool estaVacia() {
        return frente == NULL;
    }

    void encolar(Partido p) {
        NodoCola* nuevo = new NodoCola(p);
        if (estaVacia()) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    Partido desencolar() {
        if (estaVacia()) {
            cout << "La cola está vacía." << endl;
            return Partido();
        }

        NodoCola* aux = frente;
        Partido valor = aux->partido;
        frente = frente->siguiente;

        if (frente == NULL)
            final = NULL;

        delete aux;
        return valor;
    }

    void listarCola() {
        if (estaVacia()) {
            cout << " La cola está vacía." << endl;
            return;
        }

        NodoCola* actual = frente;
        int i = 1;
        cout << "\n=== Cola de partidos (FIFO) ===" << endl;
        while (actual != NULL) {
            cout << i << ") ";
            actual->partido.mostrarPartido();
            actual = actual->siguiente;
            i++;
        }
    }

    void limpiar() {
        while (!estaVacia()) {
            desencolar();
        }
    }
};
