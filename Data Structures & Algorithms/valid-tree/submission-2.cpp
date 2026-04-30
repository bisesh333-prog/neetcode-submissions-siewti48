class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int l=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                l++;
                if(dfs(adj, i, -1, vis)) return false;
            }
        }
        if(l>1) return false;
        return true;
    }
    bool dfs(vector<vector<int>>& adj, int node, int parent, vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(adj, it, node, vis)) return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        // vis[node]=0;
        return false;
    }
};
