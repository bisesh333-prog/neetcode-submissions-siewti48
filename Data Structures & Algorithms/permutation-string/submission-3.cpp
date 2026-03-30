class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']++;
        }
        int l=0,arr2[26]={0};
        for(int r=0;r<s2.size();r++){
            if(!arr1[s2[r]-'a']){
                for(int i=0;i<26;i++) arr2[i]=0;
                l=r+1;
                continue;
            }
            else{
                arr2[s2[r]-'a']++;
                while(arr2[s2[r]-'a']>arr1[s2[r]-'a']){
                    arr2[s2[l]-'a']--;
                    l++;
                }
                int len=r-l+1;
                if(len==s1.size()) return true;
            }


        }
        return false;
    }
};
