class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        int c(0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i, adj, vis);
            }
        }
        return c;
    }
};
