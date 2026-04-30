class Solution {
public:
    int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m= board[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                bfs(board, 0, i, n, m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                bfs(board, i, 0, n, m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                bfs(board, n-1, i, n, m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                bfs(board, i, m-1, n, m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='Y')board[i][j]='O';
            }
        }
        return;
    }
    void bfs(vector<vector<char>>& board, int i, int j, int n, int m){
        board[i][j]='Y';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int x =q.front().first, y=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d], ny=y+dy[d];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]=='O'){
                    board[nx][ny]='Y';
                    q.push({nx,ny});
                }
            }
        }
        return;
    }
};
