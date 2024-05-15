#include "ListGraph.h"

ListGraph::ListGraph(int numVertices)
	:adjacencyList(numVertices)
{
}

ListGraph::ListGraph(const IGraph& graph)
{
	for (int i = 0; i < graph.VerticesCount(); i++)
	{
		adjacencyList[i] = graph.GetNextVertices(i);
	}
}

ListGraph::~ListGraph()
{
}

void ListGraph::AddEdge(int from, int to)
{
	assert(0 <= from && from < adjacencyList.size());
	assert(0 <= to && to < adjacencyList.size());

	adjacencyList[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
	return adjacencyList.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
	assert(0 <= vertex && vertex < adjacencyList.size());
	return adjacencyList[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
	assert(0 <= vertex && vertex < adjacencyList.size());

	std::vector<int> prev_vertices;
	for (int from = 0; from < adjacencyList.size(); from++)
	{
		for (int to : adjacencyList[from])
		{
			if (to == vertex)
				prev_vertices.push_back(from);
		}
	}

	return prev_vertices;
}
