
bool isValid(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
    {
        return true;
    }
    return false;
}

struct cell
{
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
    {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<cell> q;
    q.push(cell(KnightPos[0], KnightPos[1], 0));

    cell t;
    int x, y;

    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));

    vis[KnightPos[0]][KnightPos[1]] = true;

    while (!q.empty())
    {
        t = q.front();
        q.pop();

        if (t.x == TargetPos[0] && t.y == TargetPos[1])
            return t.dis;

        for (int i = 0; i < 8; i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isValid(x, y, N) && !vis[x][y])
            {
                vis[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}