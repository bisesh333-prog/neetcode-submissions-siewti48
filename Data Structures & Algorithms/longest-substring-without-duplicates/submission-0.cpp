class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> m;
        int l=0, p=0;
        for(int r=0; r<s.size(); r++){
            if(m[s[r]]==0){
                p=max(p, r-l+1);
                m[s[r]]++;
            }
            else{
                m[s[r]]++;
                while(m[s[r]]>1){
                    m[s[l]]--;
                    l++;
                }
            }

        }
        return p;
    }
};
  