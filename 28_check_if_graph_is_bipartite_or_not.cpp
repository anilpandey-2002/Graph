
bool dfs(int curr, int parent, vector<int> &color, vector<int> adj[])
{
    color[curr] = 1 - color[parent];

    for (int i : adj[curr])
    {
        if (color[i] == -1)
        {
            color[i] = 1 - color[curr];
            if (!dfs(i, curr, color, adj))
                return false;
        }
        else if (color[i] == color[curr] && i != parent)
            return false;
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, -1, color, adj))
                return false;
        }
    }
    return true;
}