class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0, ans=0;
        while(r<s.size()){
            if(!mp[s[r]]){
                mp[s[r]]++;
                r++;
            }
            else{
                ans=max(ans,r-l);
                mp[s[l]]--;
                l++;
            }
        }
        ans=max(ans,r-l);
        return ans;
    }
};
