class Solution {
public:
    int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int start, end;
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j}, 0});
                }
            }
        }
        while(!q.empty()){
            int x =q.front().first.first, y = q.front().first.second;
            int val = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int lx = x + dx[i], ly = y + dy[i];
                if(lx>=0&&ly>=0&&lx<n&&ly<m&&grid[lx][ly]==INT_MAX){
                        grid[lx][ly] = val+1;
                        q.push({{lx,ly}, val+1});
                }
            }
        }
        return;
    }
};
