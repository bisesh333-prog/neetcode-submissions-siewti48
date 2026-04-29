class Solution {
public:
    int dx[4]={0,0,-1,1}, dy[4]={1,-1,0,0};
    void markPacific(vector<vector<int>>& heights, int n, int m, vector<vector<int>> &island){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n, vector<int> (m, 0));
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first, y= q.front().second;
                    q.pop();
                    if(x==0||y==0){
                        island[i][j]++;
                        break;
                    }
                    for(int d=0;d<4;d++){
                        int nx = x+dx[d], ny = y+dy[d];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&heights[nx][ny]<=heights[x][y]&&!vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                    
                }
            }
        }
        return;
    }
    void markAtlantic(vector<vector<int>>& heights, int n, int m, vector<vector<int>> &island){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n, vector<int> (m, 0));
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first, y= q.front().second;
                    q.pop();
                    if(x==n-1||y==m-1){
                        island[i][j]++;
                        break;
                    }
                    for(int d=0;d<4;d++){
                        int nx = x+dx[d], ny = y+dy[d];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m&&heights[nx][ny]<=heights[x][y]&&!vis[nx][ny]){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                    
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        vector<vector<int>> island(n, vector<int>(m,0));
        markPacific(heights, n, m, island);
        markAtlantic(heights, n, m, island);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(island[i][j]==2){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
