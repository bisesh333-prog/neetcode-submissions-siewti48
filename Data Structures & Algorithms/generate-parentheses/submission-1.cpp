class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string tmp="";
        backtrack(n, n, tmp);
        return ans;
    }
    void backtrack(int open, int close, string tmp){
        if(open>close)return;
        if(open==0&&close==0){
            ans.push_back(tmp);
            return;
        }

        if(open>0){
            tmp+="(";
            backtrack(--open, close, tmp);
            open++;
            tmp.pop_back();
        }
        if(close>0){
        tmp+=")";
        backtrack(open, --close, tmp);
        close++;
        tmp.pop_back();
        }
    }
};
