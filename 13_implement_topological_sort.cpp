
void dfs(int curr, stack<int> &s, vector<int> &vis, vector<int> adj[])
{
    vis[curr] = 1;

    for (auto i : adj[curr])
    {
        if (!vis[i])
        {
            dfs(i, s, vis, adj);
        }
    }

    s.push(curr);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, s, vis, adj);
        }
    }

    vector<int> sorted;
    while (!s.empty())
    {
        sorted.push_back(s.top());
        s.pop();
    }
    return sorted;
}
