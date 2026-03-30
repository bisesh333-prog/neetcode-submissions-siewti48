class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if(l==r) return nums[l];
            int mid = l + (r-l)/2;
            if(nums[mid]>=nums[l]&&nums[mid]<=nums[r]){
                return nums[l];
            }
            else if(nums[mid]>nums[r]){
                if(r-l==1) return nums[r];
                l=mid;
            }
            else if(nums[mid]<nums[l]){
                if(r-l==1) return nums[mid];
                r=mid;
            }
        }
    }
};
