class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0), v2(26,0);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }
        int l=0, len=0;
        for(int r=0;r<s2.size();r++){
            if(v1[s2[r]-'a']!=0){
                v2[s2[r]-'a']++;
                while(v2[s2[r]-'a']>v1[s2[r]-'a']){
                    v2[s2[l]-'a']--;
                    l++;
                }
                len = r-l+1;
                if(len == s1.size()){
                    return true;
                }
            }
            else{
                fill(v2.begin(), v2.end(), 0);
                l=r+1;
            }
        }
        return false;
    }
};
