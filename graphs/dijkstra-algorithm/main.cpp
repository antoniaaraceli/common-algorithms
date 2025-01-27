/*
    El algoritmo de Dijkstra es un algoritmo de recorrido de grafos que encuentra el camino más corto entre dos nodos en un grafo.  
    Tiempo de ejecución: O(|V|log|V| + |E|)
    * Para este ejemplo se uso el diagrama example.jpg
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definición de infinito INF como 999
#define INF 999
// Variable globales:  V = número de vétices, src = nodo inicial, cost[][] = arreglo con las distancias a cada nodo
int V, src, cost[100][100];
// Inicialización de array de distancias
int dist[100];
// Array para marcar los nodos que ya se han visitado
bool visited[100] = {0};
// Array para representar los parent nodes
int parent[100];


// Función de inicialización
void init(){
    for(int i = 0; i < V; i++){
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0;
}

// Función para calcular el nodo más cercano
int getNearest(){
    int minValue = INF;
    int minNode = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i] && dist[i] < minValue){
            minValue = dist[i];
            minNode = i;
        }
    }
    return minNode;
}


// Función de Algoritmo de Dijkstra
void dijkstra(){
    for(int i = 0; i < V - 1; i++){
        int nearest = getNearest();
        visited[nearest] = true;
        for(int adj = 0; adj < V; adj++){
            if(cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj]){
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

// Mostramos resultado
void display(){
    cout << "Node\tCost\tPath" << endl;
    for(int i = 0; i < V; i++){
        cout << i << "\t" << dist[i] << "\t";
        vector<int> path;
        int parNode = i;
        while (parNode != src) {
            path.push_back(parNode);
            parNode = parent[parNode];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        for(int node : path){
            cout << node << " ";
        }
        cout << endl;
    }
}

int main(void){
    // Tomamos el número de vétices y calculamos la distancia -> cost[][]
    cout << "Ingresa el número de nodos: ";
    cin >> V;
    cout << "\nIngresa la matriz de costos (usa " << INF << " para infinito):\n";
    for(int i=0; i < V; i++){
        for(int j=0; j < V; j++){
            cin>> cost[i][j];
        }
    }
    cout << "\nIngresa el nodo inicial: ";
    cin >> src;

    init();
    dijkstra();
    display();

    return 0;
}

/* Representación de las métricas de costos del grafo ejemplo
0 4 999 999 999 999 999 8 999
4 0 8 999 999 999 999 11 999
999 8 0 7 999 4 999 999 2
999 999 7 0 9 14 999 999 999
999 999 999 9 0 10 999 999 999
999 999 4 14 10 0 2 999 999
999 999 999 999 999 2 0 1 6
8 11 999 999 999 999 1 0 7
999 999 2 999 999 999 6 7 0
*/
