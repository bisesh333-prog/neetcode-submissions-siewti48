class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int bfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=2;
        int c = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int l=0;l<4;l++){
                int lx = x + dx[l];
                int ly = y + dy[l];
                if(lx>=0&&lx<n&&ly>=0&&ly<m&&grid[lx][ly]==1){
                    grid[lx][ly]=2;
                    c++;
                    q.push({lx,ly});
                }
            }
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans = max(ans,bfs(i,j,n,m,grid));
                }
            }
        }
        return ans;
    }
};
