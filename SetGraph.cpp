#include "SetGraph.h"

SetGraph::SetGraph(int numVertices) 
: adjacencyLists(numVertices)
{
}

SetGraph::SetGraph(const IGraph& graph)
{
	adjacencyLists.resize(graph.VerticesCount());

	for (int i = 0; i < graph.VerticesCount(); ++i)
	{
		for (int next_vertex : graph.GetNextVertices(i))
		{
			adjacencyLists[i].insert(next_vertex);
		}
	}
}

SetGraph::~SetGraph()
{
}

void SetGraph::AddEdge(int from, int to)
{
	adjacencyLists[from].insert(to);
}

int SetGraph::VerticesCount() const
{
	return adjacencyLists.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
	std::vector<int> next_vertices;
	for (int adjacency_vertex : adjacencyLists[vertex])
	{
		next_vertices.emplace_back(adjacency_vertex);
	}

	return next_vertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> prev_vertices;
	for (int i = 0; i < adjacencyLists.size(); ++i)
	{
		if (adjacencyLists[i].find(vertex) 
			!= adjacencyLists[i].end())
			prev_vertices.emplace_back(i);
	}
	return prev_vertices;
}
