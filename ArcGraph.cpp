#include "ArcGraph.h"

ArcGraph::ArcGraph(int numVertices) 
: vertex_count(numVertices)
{
}

ArcGraph::ArcGraph(const IGraph& graph)
{
	vertex_count = graph.VerticesCount();
	for (int i = 0; i < vertex_count; ++i)
	{
		auto adjacency_vertexes = graph.GetNextVertices(i);
		for (int vertex : adjacency_vertexes)
			graph_edges.emplace_back(std::pair<int, int>(i, vertex));
	}
}

ArcGraph::~ArcGraph()
{
}

void ArcGraph::AddEdge(int from, int to)
{
	graph_edges.emplace_back(std::pair<int, int>(from, to));
}

int ArcGraph::VerticesCount() const
{
	return vertex_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
	std::vector<int> next_vertices;
	for (std::pair<int, int> edge : graph_edges)
	{
		if (edge.first == vertex)
			next_vertices.push_back(edge.second);
	}
	return next_vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
	std::vector<int> prev_vertices;
	for (std::pair<int, int> edge : graph_edges)
	{
		if (edge.second == vertex)
			prev_vertices.push_back(edge.first);
	}
	return prev_vertices;
}
