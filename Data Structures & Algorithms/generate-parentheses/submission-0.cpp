class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        helper(n,s,0);
        return ans;
    }
    void helper(int n, string &s, int c){
        if(n==0&&c==0){
            ans.push_back(s);
            return;
        }
        if(n!=0){
            s+='(';
            helper(n-1, s, c+1);
            s.pop_back();
        }
        if(c!=0){
            s+=')';
            helper(n,s,c-1);
            s.pop_back();
        }
    }
};
