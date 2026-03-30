class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            int arr[26]={0};
            for(int j=0;j<strs[i].size();j++){
                arr[strs[i][j]-'a']++;
            }
            string s="";
            for(int i=0;i<26;i++){
                s+=char(arr[i]);
            }
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
