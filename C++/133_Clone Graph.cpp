class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        mp.clear();
        return dfs(node);
    }
private:
    map<int, UndirectedGraphNode*> mp;
    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        if (mp.find(node->label) != mp.end())
            return mp[node->label];
        UndirectedGraphNode *now = new UndirectedGraphNode(node->label);
        mp[node->label] = now;
        now->neighbors.clear();
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (node->neighbors[i] == NULL)
                now->neighbors.push_back(NULL);
            else
                now->neighbors.push_back(dfs(node->neighbors[i]));
        }
        return now;
    }
};