
void dfs(int curr, string &ans, vector<int> &vis, vector<vector<int>> &g)
{
    vis[curr] = 1;

    for (auto i : g[curr])
    {
        if (!vis[i])
        {
            dfs(i, ans, vis, g);
        }
    }
    ans += (curr + 'a');
}

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> g(K);

    for (int i = 0; i < N - 1; i++)
    {
        string a = dict[i];
        string b = dict[i + 1];

        for (int j = 0; j < min(a.size(), b.size()); j++)
        {
            if (a[j] != b[j])
            {
                g[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }

    vector<int> vis(K, 0);
    string ans = "";

    for (int i = 0; i < K; i++)
    {
        if (!vis[i])
        {
            dfs(i, ans, vis, g);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}