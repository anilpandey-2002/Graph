
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<pii> g[n + 1];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }

    cin >> source;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> distTo(n + 1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        vector<pii>::iterator it;
        for (auto it : g[curr])
        {
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > distTo[curr] + nextDist)
            {
                distTo[next] = distTo[curr] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << distTo[i] << " ";
    cout << "\n";

    return 0;
}
