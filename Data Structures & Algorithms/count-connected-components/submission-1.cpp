class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(adj, i, vis);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &adj, int node, vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, vis);
            }
        }
        return;
    }
};
