class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> tempv;
        backtrack(s,0,"", tempv);
        return ans;
    }
    void backtrack(string s, int i, string temps, vector<string> &tempv){
        if(i==s.size()){
            if(temps==""){
                ans.push_back(tempv);
            }
            return;
        }
        temps+=s[i];
        if(is_palindrome(temps)){
            tempv.push_back(temps);
            backtrack(s, i+1, "", tempv);
            tempv.pop_back();
        }

        backtrack(s,i+1, temps, tempv);
    }
    bool is_palindrome(string s){
        string t=s;
        reverse(s.begin(),s.end());
        return t==s;
    }
};
