class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> arr;
        for(int i=0;i<n;i++){
            arr[nums[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr.count(target-nums[i])&&arr[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(arr[target-nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};
