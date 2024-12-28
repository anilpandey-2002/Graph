int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool isValid(int x, int y, int row, int col, vector<vector<int>> &vis)
{
    return x >= 0 && x < row && y >= 0 && y < col && !vis[x][y];
}

void dfs(int x, int y, int newColor, vector<vector<int>> &image, vector<vector<int>> &vis, int row, int col, int sr, int sc)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny, row, col, vis) && image[sr][sc] == image[nx][ny])
        {
            image[nx][ny] = newColor;
            dfs(nx, ny, newColor, image, vis, row, col, sr, sc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int row = image.size(), col = image[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));
    dfs(sr, sc, newColor, image, vis, row, col, sr, sc);
    image[sr][sc] = newColor;
    return image;
}
