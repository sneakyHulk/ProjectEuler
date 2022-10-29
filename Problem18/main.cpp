#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>
#include <limits>
#include <stack>
#include <tuple>

/*
 * 0
 * 1 2
 * 3 4 5
 * 6 7 8 9
 * 10 11 12 13 14
 */

class edge {
public:
    int from;
    int to;
    int weight;
};

class adjacent {
public:
    int vertex;
    int weight;
};

class DAG {
public:
    static auto fill() {
        std::vector<edge> edges;
        std::ifstream in;
        in.open("triangle.txt");

        int k = 0;
        for (int i = 0; i < 14; ++i) {
            for (int j = 0; j <= i; ++j) {
                int weight;
                in >> weight;
                edges.push_back({k, k + i + 1, weight});
                edges.push_back({k, k + i + 2, weight});
                k++;
            }
        }
        for (int i = k; i < k + 15; ++i) {
            int weight;
            in >> weight;
            edges.push_back({i, k + 15, weight});
        }
        unsigned int num_nodes = k + 15 + 1;

        return std::make_tuple(edges, num_nodes);
    }

    static std::vector<std::vector<adjacent>> create_adjacency_list(std::vector<edge> edges, unsigned int num_nodes) {
        std::vector<std::vector<adjacent>> adjacency_list(num_nodes);
        for (int i = 0; i < edges.size(); ++i) {
            adjacency_list[edges[i].from].push_back({edges[i].to, edges[i].weight});
        }

        return adjacency_list;
    }

    static std::stack<int> topoligical_sort(std::vector<std::vector<adjacent>> const& adjacency_list, unsigned int num_nodes) {
        std::vector<bool> visited(num_nodes, false);
        std::stack<int> st;

        for (int i = 0; i < num_nodes; ++i) {
            if (!visited[i]) {
                _topoligical_sort(i, adjacency_list, visited, st);
            }
        }

        return st;
    }

private:
    static void _topoligical_sort(int node, std::vector<std::vector<adjacent>> const &adjacency_list,
                           std::vector<bool> &visited, std::stack<int> &st) {
        visited[node] = true;

        for (auto const& it: adjacency_list[node]) {
            if (!visited[it.vertex]) {
                _topoligical_sort(it.vertex, adjacency_list, visited, st);
            }
        }

        st.push(node);
    }

public:
    static std::vector<int> shortest_distance(std::vector<std::vector<adjacent>> const& adjacency_list, std::stack<int> st, unsigned int num_nodes) {
        std::vector<int> distances(num_nodes, std::numeric_limits<int>::max());

        distances[0] = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();

            for (auto const& it: adjacency_list[node]) {
                if (distances[node] + it.weight < distances[it.vertex]) {
                    distances[it.vertex] = it.weight + distances[node];
                }
            }
        }

        return distances;
    }

    static std::vector<int> greatest_distance(std::vector<std::vector<adjacent>> const& adjacency_list, std::stack<int> st, unsigned int num_nodes) {
        std::vector<int> distances(num_nodes, std::numeric_limits<int>::min());

        distances[0] = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();

            for (auto const& it: adjacency_list[node]) {
                if (distances[node] + it.weight > distances[it.vertex]) {
                    distances[it.vertex] = it.weight + distances[node];
                }
            }
        }

        return distances;
    }
};

int main() {
    DAG dg;

    auto [edges, num_nodes] = dg.fill();
    auto adjacency_list = dg.create_adjacency_list(edges, num_nodes);
    auto st = dg.topoligical_sort(adjacency_list, num_nodes);
    auto greatest_distance = dg.greatest_distance(adjacency_list, st, num_nodes);

    std::cout << greatest_distance[greatest_distance.size() - 1] << std::endl;

    return 0;
}