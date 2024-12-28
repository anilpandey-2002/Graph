
vector<int> diffByOneLetter(string curr, vector<int> &vis, vector<string> &wordList)
{
    vector<int> idx;

    for (int i = 0; i < wordList.size(); i++)
    {
        if (!vis[i])
        {
            int c = 0;
            int cnt = 0;
            while (c < curr.size())
            {
                if (curr[c] != wordList[i][c])
                    cnt++;
                c++;
            }
            if (cnt == 1)
            {
                idx.push_back(i);
                vis[i] = 1;
            }
        }
    }

    return idx;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    vector<int> vis(wordList.size(), 0);

    queue<string> q;
    q.push(beginWord);

    int level = 1;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            string curr = q.front();
            q.pop();

            if (curr == endWord)
            {
                return level;
            }

            vector<int> idx = diffByOneLetter(curr, vis, wordList);

            for (auto i : idx)
                q.push(wordList[i]);
        }

        level++;
    }

    return 0;
}