
bool checkCycle(int curr, vector<int> &vis, vector<int> adj[])
{
    vis[curr] = 1;

    queue<pair<int, int>> q;
    q.push({curr, -1});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (auto i : adj[p.first])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, p.first});
            }
            else if (i != p.second)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, vis, adj))
                return true;
        }
    }
    return false;
}
