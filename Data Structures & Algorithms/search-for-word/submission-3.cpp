class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool flag = false;
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(), col=board[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(word[0]==board[r][c]){
                    vector<vector<int>> vis(row, vector<int>(col, 0));
                    vis[r][c]=1;
                    backtrack(r, c, board, 0, word, vis, row, col);
                    if(flag) return true;
                }
            }
        }
        return flag;
    }
    void backtrack(int r, int c, vector<vector<char>>& board, int i, string word, vector<vector<int>> vis, int row, int col){
        if(i==word.size()-1){
            flag = true;
            return;
        }
        i++;
        for(int j=0;j<4;j++){
            int rx = r+dx[j], ry = c+dy[j];
            if(rx>=0&&rx<row&&ry>=0&&ry<col&&word[i]==board[rx][ry]&&!vis[rx][ry]){
                vis[rx][ry]=1;
                backtrack(rx, ry, board, i, word, vis, row, col);
                vis[rx][ry]=0;
            }
        }
        return;
    }
};
