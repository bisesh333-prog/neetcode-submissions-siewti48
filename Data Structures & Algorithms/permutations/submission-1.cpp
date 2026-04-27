class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        unordered_map<int,int> mp;
        backtrack(nums,tmp, mp);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<int> &tmp, unordered_map<int,int> &mp){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                tmp.push_back(nums[i]);
                mp[nums[i]]=1;
                backtrack(nums,tmp,mp);
                tmp.pop_back();
                mp[nums[i]]=0;
            }
        }
    }
};
