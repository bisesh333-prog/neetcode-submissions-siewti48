class Solution {
public:
    int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)q.push({0,{i,j}});
            }
        }
        while(!q.empty()){
            int l=q.front().first;
            int x=q.front().second.first, y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==INT_MAX){ 
                    grid[nx][ny]=l+1;
                    q.push({l+1,{nx,ny}});
                }
            }
        }
        return;
    }
};
