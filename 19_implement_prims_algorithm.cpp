
int spanningTree(int V, vector<vector<int>> adj[])
{
    int parent[V];
    bool mstSet[V];
    int key[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    int ans = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (vector<int> p : adj[u])
        {
            int v = p[0];
            int weight = p[1];

            if (mstSet[v] == false && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (key[i] != INT_MAX)
            ans += key[i];
    }

    return ans;
}