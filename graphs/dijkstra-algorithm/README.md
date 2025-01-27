# Algoritmo de Dijkstra

Este repositorio contiene la implementación del **Algoritmo de Dijkstra**, utilizado para encontrar el camino más corto entre un nodo inicial y los demás nodos de un grafo ponderado.

---

### Características

- **Tipo de grafo**: Dirigido o no dirigido, ponderado.
- **Complejidad temporal**: O(|V|log|V| + |E|), donde |V| es el número de vértices y |E| es el número de aristas.

---

## Instrucciones para compilar y ejecutar

### 1. Clonar el repositorio

Clona este repositorio en tu máquina local con el siguiente comando:

```bash
git clone https://github.com/antoniaaraceli/common-algorithms.git
cd common-algorithms/graphs/dijkstra-algorithm
```

### 2. Compilar el código
Usa el siguiente comando para compilar el programa con ```g++```:

```bash
g++ main.cpp -o dijkstra
```
### 3. Ejecutar el programa
Después de compilar, ejecuta el archivo generado:

```bash
./dijkstra
```

## Formato de entrada
El programa solicita los siguientes datos en este orden:

- **Número de nodos** en el grafo (entero positivo).
- **Matriz de costos**: Representa el costo de las aristas (usar 999 para representar "infinito" o ausencia de conexión).
- **Nodo fuente**: El nodo desde el cual se calcularán las distancias más cortas.

## Salida del programa
El programa imprimirá una tabla con:
- El nodo.
- El costo mínimo desde el nodo fuente.
- El camino más corto desde el nodo fuente hasta cada nodo.

### Ejemplo de salida:
```bash
Nodo:                Costo:              Camino:
0                    0                   0 
1                    3                   0 <- 1 
2                    4                   0 <- 1 <- 2 
3                    7                   0 <- 3 
```


¡Gracias por visitar este repositorio! 🚀