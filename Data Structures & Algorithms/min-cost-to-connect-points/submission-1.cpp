class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i][j]=dist;
                adj[j][i]=dist;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n);
        int res=0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr]=1;
            res+=wt;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    pq.push({adj[curr][i],i});
                }
            }
        }
        return res;
    }
};
