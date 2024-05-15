#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int numVertices)
:adjacencyMatrix(numVertices, 
				 std::vector<bool>(numVertices, false))
{
}

MatrixGraph::MatrixGraph(const IGraph& graph)
{
	auto vertices_count = graph.VerticesCount();
	adjacencyMatrix = std::vector<std::vector<bool>>(vertices_count, 
						   std::vector<bool>(vertices_count, false));

	for (int i = 0; i < vertices_count; ++i)
	{
		std::vector<int> next_vertices = graph.GetNextVertices(i);

		for (int elem : next_vertices)
		{
			adjacencyMatrix[i][elem] = true;
		}
	}
}

MatrixGraph::~MatrixGraph()
{
}

void MatrixGraph::AddEdge(int from, int to)
{
	adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
	return adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
	std::vector<int> next_vertices;
	for (int i = 0; i < adjacencyMatrix.size(); ++i)
	{
		if (adjacencyMatrix[vertex][i])
			next_vertices.push_back(i);
	}

	return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> prev_vertices;

	for (int i = 0; i < adjacencyMatrix.size(); ++i)
	{
		if (adjacencyMatrix[i][vertex])
			prev_vertices.push_back(i);
	}

	return prev_vertices;
}
