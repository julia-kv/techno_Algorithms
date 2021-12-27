#include "IGraph.h"

#pragma once

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertices_count);

    MatrixGraph(const IGraph& graph);

    ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std:: vector<std::vector<int>> vertices_matrix;
};