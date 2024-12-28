
int adjMatrix()
{
    int rows, cols;
    cin >> rows >> cols;

    int adj[rows + 1][rows + 1];

    for (int i = 0; i < rows; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}
