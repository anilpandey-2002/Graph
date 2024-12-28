class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int N = board.size(), target = N * N;
        vector<int> vis(target + 1, 0);
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty())
        {
            auto [pos, steps] = q.front();
            q.pop();

            if (pos == target)
                return steps;
            if (pos > target || vis[pos])
                continue;

            vis[pos] = 1;
            for (int i = 1; i <= 6 && pos + i <= target; i++)
            {
                int newPos = pos + i, r = (newPos - 1) / N, row = N - 1 - r;
                int col = (r % 2 == 0) ? (newPos - 1) % N : N - 1 - (newPos - 1) % N;
                q.push({board[row][col] == -1 ? newPos : board[row][col], steps + 1});
            }
        }
        return -1;
    }
};
