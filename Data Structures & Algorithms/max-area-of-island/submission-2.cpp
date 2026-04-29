class Solution {
public:
    int ans = 0;
    int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!vis[i][j]){
                    bfs(grid, i, j, vis, n, m);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &vis, int n, int m){
        vis[i][j]=1;
        queue<pair<int,int>> q;
        int l=1;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]&&!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                    l++;
                }
            }
        }
        ans=max(ans,l);
    }
};
