#include <iostream>
#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void bfs(const IGraph& graph, void(*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            q.push(vertex);

            while (!q.empty()) {

                int v = q.front();
                q.pop();
                callback(v);

                std::vector<int> children = graph.GetNextVertices(v);
                for (auto& child : children) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
    }
}

int main() {

    std::cout << "----ListGraph-----" << std::endl;

    IGraph *list_graph = new ListGraph(7);
    list_graph->AddEdge(0,1);
    list_graph->AddEdge(1,5);
    list_graph->AddEdge(6,0);
    list_graph->AddEdge(1,2);
    list_graph->AddEdge(2,3);
    list_graph->AddEdge(3,4);
    list_graph->AddEdge(4,2);

    bfs(*list_graph, [](int v) {
        std::cout << v << std::endl;
    });

    delete list_graph;

    std::cout << "----MatrixGraph-----" << std::endl;

    IGraph *matrix_graph = new MatrixGraph(7);
    matrix_graph->AddEdge(0,1);
    matrix_graph->AddEdge(1,5);
    matrix_graph->AddEdge(6,0);
    matrix_graph->AddEdge(1,2);
    matrix_graph->AddEdge(2,3);
    matrix_graph->AddEdge(3,4);
    matrix_graph->AddEdge(4,2);

    bfs(*matrix_graph, [](int v) {
        std::cout << v << std::endl;
    });

    delete matrix_graph;

    std::cout << "----SetGraph-----" << std::endl;

    IGraph *set_graph = new SetGraph(7);
    set_graph->AddEdge(0,1);
    set_graph->AddEdge(1,5);
    set_graph->AddEdge(6,0);
    set_graph->AddEdge(1,2);
    set_graph->AddEdge(2,3);
    set_graph->AddEdge(3,4);
    set_graph->AddEdge(4,2);

    bfs(*set_graph, [](int v) {
        std::cout << v << std::endl;
    });

    delete set_graph;

    std::cout << "----ArcGraph-----" << std::endl;

    IGraph *arc_graph = new ArcGraph(7);
    arc_graph->AddEdge(0,1);
    arc_graph->AddEdge(1,5);
    arc_graph->AddEdge(6,0);
    arc_graph->AddEdge(1,2);
    arc_graph->AddEdge(2,3);
    arc_graph->AddEdge(3,4);
    arc_graph->AddEdge(4,2);

    bfs(*arc_graph, [](int v) {
        std::cout << v << std::endl;
    });

    delete arc_graph;

    return 0;
}
