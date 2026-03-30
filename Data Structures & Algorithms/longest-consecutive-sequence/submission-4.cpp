class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans=0;
        for(auto it:nums){
            if(mp[--it]) continue;
            int c=0;
            while(mp[++it]){
                c++;
            }
            ans=max(c,ans);
        }
        return ans;
    }
};
