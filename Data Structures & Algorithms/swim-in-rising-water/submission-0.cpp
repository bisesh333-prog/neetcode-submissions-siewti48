class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =grid.size();
        set<pair<int,int>> vis;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        pq.push({grid[0][0], 0, 0});
        vis.insert({0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int t=curr[0], x=curr[1], y=curr[2];
            if(x==n-1&&y==n-1){
                return t;
            }
            for(auto d: dir){
                int nx=x+d[0], ny=y+d[1];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis.count({nx,ny})){
                    vis.insert({nx,ny});
                    pq.push({max(t,grid[nx][ny]), nx, ny});
                }
            }
        }
        return n*n;
    }
};
