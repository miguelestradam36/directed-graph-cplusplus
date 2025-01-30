#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Estructura de datos para almacenar un borde de graph
struct Edge {
    int src, dest;
};

// Una clase para representar un objeto graph
class Graph
{
public:
    // numero de vertices
    int V;
    // un vector de vectores para representar una lista de adyacencia
    vector<vector<int>> adjList;

    // Constructor de graph
    Graph(vector<Edge> const& edges, int n)
    {
        // guardando numero de vertices
        this->V = n;
        // cambiar el tama�o del vector para contener `n` elementos de tipo `vector<int>`
        adjList.resize(n);

        // agrega bordes al grafo no dirigido
        for (auto& edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
    //Imprime grafo
    void print_graph() {
        for (int i = 0; i < V; i++) {
            std::cout << "Grafo-> el vertice: " << i << " esta conectado con: ";
            for (int j : this->adjList[i]) {
                std::cout << " " << j;
            }
            std::cout << endl;
        }
    }
    // Realiza DFS en el graph y devuelve verdadero si se encuentra alg�n borde posterior en el graph
    bool DFS(int v, vector<bool>& discovered, int parent)
    {
        // marca el nodo actual como descubierto
        discovered[v] = true;

        // hacer para cada borde (v, w)
        for (int w : this->adjList[v])
        {
            // si `w` no se descubre
            if (!discovered[w])
            {
                if (DFS(w, discovered, v)) {
                    return true;
                }
            }

            // si se descubre `w` y `w` no es un padre
            else if (w != parent)
            {
                // encontramos un back-edge (ciclo)
                return true;
            }
        }

        // No se encontraron bordes posteriores en el graph
        return false;
    }
};


#include <iostream>
#include <vector>
#include <queue>
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

            // n�mero total de nodos en el graph (0 a 5)
            int n = 6;

            // construye un graph a partir de los bordes dados
            Graph graph(edges, n);

            // para realizar un seguimiento de si se descubre un v�rtice o no
            vector<bool> discovered(n);
            //mostrar grafo
            graph.print_graph();
            // Realizar recorrido DFS desde el primer v�rtice
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

            // n�mero total de nodos en el graph (0 a 11)
            int n = 12;

            // construye un graph a partir de los bordes dados
            Graph graph(edges, n);

            // para realizar un seguimiento de si se descubre un v�rtice o no
            vector<bool> discovered(n);
            //mostrar grafo
            graph.print_graph();
            // Realizar recorrido DFS desde el primer v�rtice
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