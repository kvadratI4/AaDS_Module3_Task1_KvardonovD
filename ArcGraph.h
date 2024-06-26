#pragma once
#include <vector>
#include <utility>
#include "IGraph.h"
class ArcGraph : public IGraph
{
public:
	ArcGraph(int numVertices);
	ArcGraph(const IGraph& graph);
	~ArcGraph();

	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;
private:
	std::vector<std::pair<int, int>> graph_edges;
	int vertex_count;
};

