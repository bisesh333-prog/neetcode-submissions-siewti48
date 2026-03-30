class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            int j=i+1, k= n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
