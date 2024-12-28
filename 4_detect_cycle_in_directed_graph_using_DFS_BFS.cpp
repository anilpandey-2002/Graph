
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> inDeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto k : adj[i])
        {
            inDeg[k]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (inDeg[i] == 0)
            q.push(i);
    }

    int cnt = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cnt++;

        for (auto i : adj[curr])
        {
            inDeg[i]--;
            if (inDeg[i] == 0)
                q.push(i);
        }
    }

    if (cnt == V)
        return false;
    return true;
}