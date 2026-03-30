class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c=0, l=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
            }
            else{
                l=l*nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(c>1){
                ans.push_back(0);
                }
                else{
                    ans.push_back(l);
                }
            }
            else{
                if(c){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(l/nums[i]);
                }
            }
        }
        return ans;
    }
};
