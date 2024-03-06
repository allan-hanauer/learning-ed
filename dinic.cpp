#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, capacity, flow, rev_index;
};

class Dinic {
private:
    int V;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> iter;

    bool bfs(int source, int sink) {
        level.assign(V, -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const Edge& e : graph[u]) {
                if (level[e.to] < 0 && e.flow < e.capacity) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] >= 0;
    }
    int dfs(int u, int sink, int flow) {
        if (u == sink)
            return flow;

        for (int& i = iter[u]; i < graph[u].size(); ++i) {
            Edge& e = graph[u][i];
            if (e.capacity > e.flow && level[u] < level[e.to]) {
                int d = dfs(e.to, sink, min(flow, e.capacity - e.flow));
                if (d > 0) {
                    e.flow += d;
                    graph[e.to][e.rev_index].flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int vertices) : V(vertices), graph(vertices), level(vertices), iter(vertices) {}

    void add_edge(int from, int to, int capacity) {
        Edge forward_edge = {to, capacity, 0, static_cast<int>(graph[to].size())};
        Edge backward_edge = {from, 0, 0, static_cast<int>(graph[from].size())};
        graph[from].push_back(forward_edge);
        graph[to].push_back(backward_edge);
    }
    int max_flow(int source, int sink) {
        int max_flow = 0;
        while (bfs(source, sink)) {
            iter.assign(V, 0);
            int flow;
            while ((flow = dfs(source, sink, INT_MAX)) > 0) {
                max_flow += flow;
            }
        }
        return max_flow;
    }
};

int main() {
    int V, E;
    cout << "Digite o numero de vertices e arestas: ";
    cin >> V >> E;

    Dinic dinic(V);

    cout << "Digite as arestas e suas capacidades (origem destino capacidade):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }

    int source, sink;
    cout << "Digite o vertice de origem e o vertice de destino: ";
    cin >> source >> sink;

    int max_flow = dinic.max_flow(source, sink);
    cout << "Fluxo maximo da fonte para o destino: " << max_flow << endl;

    return 0;
}

