class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0,j=1,k=nums.size()-1;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        while(i<nums.size()){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1]) j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
            i++;
            while(nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};


