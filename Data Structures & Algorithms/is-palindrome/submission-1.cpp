class Solution {
public:
    bool checkAlpha(char c){
        if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')){
            return true;
        }
        else{
            return false;
        }
    }
    bool isPalindrome(string s) {
        int l =0, r= s.size()-1;
        while(l<r){
            if(tolower(s[l])==tolower(s[r])){
                l++;
                r--;
            }
            else if(!checkAlpha(s[l])&&!checkAlpha(s[r])){
                l++;
                r--;
            }
            else if(!checkAlpha(s[l])){
                l++;
            }
            else if(!checkAlpha(s[r])){
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
