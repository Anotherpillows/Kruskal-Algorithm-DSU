# Kruskal's Algorithm Implementation (C++)

Este proyecto implementa el algoritmo de **Kruskal** para encontrar el Árbol Abarcador de Costo Mínimo (MST) de un grafo pesado y no dirigido. 

## Características Técnicas
- **Estructura de Datos**: Implementación de un sistema de conjuntos disjuntos (**DSU - Disjoint Set Union**) utilizando listas enlazadas.
- **Optimización**: Se utiliza la técnica de **Union by Size** para mantener los árboles balanceados, garantizando una mayor eficiencia en las operaciones de combinación.
- **Modularidad**: El código está organizado en tres partes:
  - `Graph.h`: Definición de la interfaz y estructuras.
  - `Graph.cpp`: Implementación de la lógica del algoritmo.
  - `Kruskal.cpp`: Punto de entrada y gestión de entrada de usuario.
- **C++ Moderno**: Uso de *range-based for loops*, *auto* y *const-correctness*.

## Cómo Compilar y Ejecutar
Para compilar el proyecto en Linux/Unix, utilizá el siguiente comando en la terminal:

```bash
g++ Graph.cpp Kruskal.cpp -o kruskal_app
./kruskal_app
