class Solution {
public:
    int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    void bfs(int i, int j, int n, int m, vector<vector<char>>& board){
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first, y= q.front().second;
            q.pop();
            for(int l=0;l<4;l++){
                int lx = x+dx[l], ly = y+dy[l];
                if(lx>=0&&lx<n&&ly>=0&&ly<m&&board[lx][ly]=='O'){
                    board[lx][ly]='P';
                    q.push({lx,ly});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0]='P';
                bfs(i,0, n, m, board);
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='P';
                bfs(i,m-1, n, m, board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                board[0][i]='P';
                bfs(0,i, n, m, board);
            }
            if(board[n-1][i]=='O'){
                board[n-1][i]='P';
                bfs(n-1,i, n, m, board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='P') board[i][j]='O';
            }
        }
    }
};
