
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> ans;

    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto j : adj[curr])
        {
            if (!vis[j])
            {
                q.push(j);
                vis[j] = 1;
            }
        }
    }

    return ans;
}
