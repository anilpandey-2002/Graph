
const int INF = 1e8;

void shortest_distance(vector<vector<int>> &matrix)
{
    int V = matrix.size();

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][k] == INF || matrix[k][j] == INF)
                    continue;
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == INF)
            {
                matrix[i][j] = -1;
            }
        }
    }
}