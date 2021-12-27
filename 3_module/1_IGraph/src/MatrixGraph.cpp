#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count) {
    vertices_matrix.resize(vertices_count);

    for (int parent = 0; parent < vertices_matrix.size(); ++parent) {
        vertices_matrix[parent].resize(vertices_count, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
    for (int parent = 0; parent < graph.VerticesCount(); ++parent) {
        std::vector<int> children = graph.GetNextVertices(parent);
        for (int child: children)
            AddEdge(parent, child);
    }
}

MatrixGraph::~MatrixGraph() {
    vertices_matrix.clear();
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices_matrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return vertices_matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int child = 0; child < vertices_matrix.size(); ++child) {
        if (vertices_matrix[vertex][child] == 1) {
            result.push_back(child);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int child = 0; child < vertices_matrix.size(); ++child) {
        if (vertices_matrix[child][vertex] == 1) {
            result.push_back(child);
        }
    }
    return result;
}

