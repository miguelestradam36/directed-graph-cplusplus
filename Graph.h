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
        // cambiar el tamaño del vector para contener `n` elementos de tipo `vector<int>`
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
    // Realiza DFS en el graph y devuelve verdadero si se encuentra algún borde posterior en el graph
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
