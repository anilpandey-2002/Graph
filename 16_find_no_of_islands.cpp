
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

bool isValid(int x, int y, int row, int col, vector<vector<char>> &grid)
{
    if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1')
        return true;
    return false;
}

void dfs(int x, int y, vector<vector<char>> &grid, int row, int col)
{
    grid[x][y] = '0';

    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (isValid(xx, yy, row, col, grid))
        {
            dfs(xx, yy, grid, row, col);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    int cnt = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {

                cnt++;
                dfs(i, j, grid, row, col);
            }
        }
    }

    return cnt;
}