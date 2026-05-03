class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> vis(n+1, 0);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        int res=0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr]=1;
            res=max(res,wt);
            for(auto it: adj[curr]){
                if(!vis[it.first]){
                    pq.push({wt+it.second, it.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) return -1;
        }
        return res;
    }
};
