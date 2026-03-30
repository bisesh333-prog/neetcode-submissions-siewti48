class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > dis[node]) continue;
            for(auto it: adj[node]){
                int next = it.first;
                int dist = it.second;
                if(dis[next]>dis[node]+dist){
                    dis[next]=dis[node]+dist;
                    pq.push({dis[next],next});
                }
            }
        }
        int maxm = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;
            maxm = max(maxm, dis[i]);
        }
        return maxm;
    }
};
