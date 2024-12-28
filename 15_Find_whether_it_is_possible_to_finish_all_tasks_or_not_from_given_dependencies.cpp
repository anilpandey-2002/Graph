#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> make_graph(int numTasks, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
{
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}

bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
    vector<bool> onpath(numTasks, false), visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}

int main()
{
    int numTasks = 4;
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    cout << (canFinish(numTasks, prerequisites) ? "Possible to finish all tasks" : "Impossible to finish all tasks");
    return 0;
}
