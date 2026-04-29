class Solution {
public:
    int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int l=-1;
        while(!q.empty()){
            int siz = q.size();
            l++;
            for(int i=0; i<siz;i++){
                int x = q.front().first, y=q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int nx = x+dx[d], ny=y+dy[d];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(l==-1) return 0;
        return l;
    }
};
