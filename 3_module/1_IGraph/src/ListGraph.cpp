#include "ListGraph.h"

ListGraph::ListGraph(int vertices_count) {
    vertices.resize(vertices_count);
}

ListGraph::ListGraph(const IGraph &graph) {
    for (int parent = 0; parent < graph.VerticesCount(); ++parent) {
        std::vector<int> children = graph.GetNextVertices(parent);
        for (int child : children)
            AddEdge(parent, child);
    }
}

ListGraph::~ListGraph() {
    vertices.clear();
}

void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < vertices.size(); ++parent) {
        for (auto &child : vertices[parent]) {
            if (child == vertex) {
                result.push_back(parent);
                break;
            }
        }
    }
    return result;
}

