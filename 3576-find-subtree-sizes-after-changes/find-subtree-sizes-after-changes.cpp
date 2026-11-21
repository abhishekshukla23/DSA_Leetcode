
class Solution {
public:
    vector<int> ans;

    void dfs1(int node, vector<vector<int>>& adj, string& s,
              vector<int>& last, vector<int>& newParent) {

        int c = s[node] - 'a';
        int prev = last[c];

        if (prev != -1) {
            newParent[node] = prev;
        }

        last[c] = node;

        for (int child : adj[node]) {
            dfs1(child, adj, s, last, newParent);
        }

        last[c] = prev;
    }

    int dfs2(int node, vector<vector<int>>& adj) {
        int size = 1;

        for (int child : adj[node]) {
            size += dfs2(child, adj);
        }

        ans[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Find new parents
        vector<int> newParent = parent;
        vector<int> last(26, -1);

        dfs1(0, adj, s, last, newParent);

        // Build modified tree
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        ans.assign(n, 0);

        dfs2(0, newAdj);

        return ans;
    }
};
