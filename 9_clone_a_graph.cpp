
unordered_map<Node *, Node *> mp;

Node *cloneGraph(Node *node)
{
    if (node && !mp[node])
    {
        mp[node] = new Node(node->val);
        for (auto i : node->neighbors)
        {
            mp[node]->neighbors.push_back(cloneGraph(i));
        }
    }
    return mp[node];
}