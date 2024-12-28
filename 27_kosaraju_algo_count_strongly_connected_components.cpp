
void dfs(int curr, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[curr] = 1;
    for (auto i : adj[curr])
    {
        if (!vis[i])
            dfs(i, st, vis, adj);
    }
    st.push(curr);
}

void revDfs(int curr, vector<int> &vis, vector<int> transpose[])
{
    vis[curr] = 1;
    for (auto it : transpose[curr])
    {
        if (!vis[it])
            revDfs(it, vis, transpose);
    }
}

int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    vector<int> transpose[V];

    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }

    int cnt = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            revDfs(node, vis, transpose);
        }
    }

    return cnt;
}