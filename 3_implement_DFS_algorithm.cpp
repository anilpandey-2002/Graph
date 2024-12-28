
void dfs(int curr, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    ans.push_back(curr);
    vis[curr] = 1;

    for (auto i : adj[curr])
    {
        if (!vis[i])
            dfs(i, adj, vis, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}
