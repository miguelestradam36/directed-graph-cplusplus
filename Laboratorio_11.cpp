#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"
int main() {
    int accion;
    do {
        //Menu de opciones
        std::cout << "--------------- MENU --------------------" << std::endl;
        std::cout << "1. Evaluar grafo sin ciclo." << std::endl;
        std::cout << "2. Evaluar grafo con ciclo." << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Numero de opcion que desea realizar: ";
        std::cin >> accion;
        if (std::cin.fail()) {
            std::cout << "No ha ingresado un numero. Esto genera un error. \nSaliendo del programa." << std::endl;
            std::cin.clear();
            break;
        }
        switch (accion) {
            //Sin Ciclo
        case 1: {
            // inicializa los bordes
            vector<Edge> edges =
            {
                {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}
            };

            // número total de nodos en el graph (0 a 5)
            int n = 6;

            // construye un graph a partir de los bordes dados
            Graph graph(edges, n);

            // para realizar un seguimiento de si se descubre un vértice o no
            vector<bool> discovered(n);
            //mostrar grafo
            graph.print_graph();
            // Realizar recorrido DFS desde el primer vértice
            if (graph.DFS(0, discovered, -1)) {
                std::cout << "Este grafo contiene un ciclo";
            }
            else {
                std::cout << "Este grafo no contiene ningun ciclo";
            }
            std::cout << "\n" << std::endl;
            break;
        }
              //Con ciclo
        case 2: {
            // inicializa los bordes
            vector<Edge> edges =
            {
                {0, 1}, {0, 6}, {0, 7},
                {1, 2}, {1, 5},
                {2, 3}, {2, 4}, 
                {7, 8}, {7, 11}, 
                {8, 9}, {8, 10}, 
                {10, 11}
            };

            // número total de nodos en el graph (0 a 11)
            int n = 12;

            // construye un graph a partir de los bordes dados
            Graph graph(edges, n);

            // para realizar un seguimiento de si se descubre un vértice o no
            vector<bool> discovered(n);
            //mostrar grafo
            graph.print_graph();
            // Realizar recorrido DFS desde el primer vértice
            if (graph.DFS(0, discovered, -1)) {
                cout << "Este grafo contiene un ciclo";
            }
            else {
                cout << "Este grafo no contiene ningun ciclo";
            }
            std::cout << "\n" << std::endl;
            break;
        }
              //Salir del programa
        case 3: {
            std::cout << "Saliendo del programa." << std::endl;

            std::cout << "\n" << std::endl;
            break;
        }
              //Opcion ingresada no valida
        default: {
            std::cout << "Por favor, ingrese un numero que se encuentre en el rango de opciones." << std::endl;
            std::cout << "\n" << std::endl;
            break;
        }
        }
    } while (accion != 3);
    return 0;
}