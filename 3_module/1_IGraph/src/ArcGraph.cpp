#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) {
    vertices_number = vertices_count;
}

ArcGraph::ArcGraph(const IGraph &graph) {
    for (int parent = 0; parent < graph.VerticesCount(); ++parent)
    {
        std::vector<int> children = graph.GetNextVertices(parent);
        for (int child : children)
            AddEdge(parent, child);
    }
}

ArcGraph::~ArcGraph() {
    vertices_pair.clear();
}

void ArcGraph::AddEdge(int from, int to) {
    std::pair<int,int> new_vertices_pair = std::make_pair(from,to);
    vertices_pair.push_back(new_vertices_pair);
}

int ArcGraph::VerticesCount() const {
    return vertices_number;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int parent = 0; parent < vertices_pair.size(); ++parent) {
        if (vertices_pair[parent].first == vertex)
            result.push_back(vertices_pair[parent].second);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int child = 0; child < vertices_pair.size(); ++child) {
        if (vertices_pair[child].second == vertex)
            result.push_back(vertices_pair[child].first);
    }
    return result;
}


