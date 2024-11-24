#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void dfs(int node,
         const vector<vector<int>> &graph,
         vector<bool> &visited,
         vector<int> &component,
         const vector<int> &colors)
{
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component, colors);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> colors(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
    }

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int totalRecolor = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, graph, visited, component, colors);

            unordered_map<int, int> colorCount;
            for (int node : component) {
                colorCount[colors[node]]++;
            }

            int maxColorCount = 0;
            for (const auto &[color, count] : colorCount) {
                maxColorCount = max(maxColorCount, count);
            }

            totalRecolor += component.size() - maxColorCount;
        }
    }

    cout << totalRecolor << endl;
    return 0;
}
