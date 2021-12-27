#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) {
    vertices_sets.resize(vertices_count);
}

SetGraph::SetGraph(const IGraph &graph) {
    for (int parent = 0; parent < graph.VerticesCount(); ++parent) {
        std::vector<int> children = graph.GetNextVertices(parent);
        for (int child: children)
            AddEdge(parent, child);
    }
}

SetGraph::~SetGraph() {
    vertices_sets.clear();
}

void SetGraph::AddEdge(int from, int to) {
    vertices_sets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices_sets.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (auto &child : vertices_sets[vertex]) {
        result.push_back(child);
    }
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < vertices_sets.size(); ++parent)
    {
        if (vertices_sets[parent].find(vertex) != vertices_sets[parent].end())
            result.push_back(parent);
    }
    return result;
}


