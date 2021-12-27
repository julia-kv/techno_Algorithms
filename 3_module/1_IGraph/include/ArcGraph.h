#include "IGraph.h"

#pragma once

class ArcGraph : public IGraph {
public:
    ArcGraph(int vertices_count);

    ArcGraph(const IGraph& graph);

    ~ArcGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std:: vector<std::pair<int,int>> vertices_pair;
    int vertices_number;
};