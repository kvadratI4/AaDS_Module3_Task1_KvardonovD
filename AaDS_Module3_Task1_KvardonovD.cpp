#include <iostream>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

int main()
{
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    // ListGraph
    std::cout << "ListGraph" << std::endl;
    listGraph.mainBFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    listGraph.mainDFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << "--------" << std::endl;

    // MatrixGraph
    MatrixGraph matrix_graph(listGraph);
    std::cout << "MatrixGraph" << std::endl;
    matrix_graph.mainBFS(matrix_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    matrix_graph.mainDFS(matrix_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << "--------" << std::endl;

    // ArcGraph
    ArcGraph arc_graph(matrix_graph);
    std::cout << "ArcGraph" << std::endl;
    arc_graph.mainBFS(arc_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    arc_graph.mainDFS(arc_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << "--------" << std::endl;

    // SetGraph
    SetGraph set_graph(arc_graph);
    std::cout << "SetGraph" << std::endl;
    set_graph.mainBFS(set_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    set_graph.mainDFS(set_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl << "--------" << std::endl;

	return 0;
}