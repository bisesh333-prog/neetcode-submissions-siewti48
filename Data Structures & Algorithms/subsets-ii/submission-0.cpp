class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        backtrack(nums, 0, tmp);
        return ans;
    }
    void backtrack(vector<int>& nums, int i, vector<int> tmp){
        if(i==nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        backtrack(nums,i+1,tmp);
        tmp.pop_back();
        while(i+1<nums.size()&&nums[i+1]==nums[i])i++;
        backtrack(nums,i+1,tmp);
    }
};
