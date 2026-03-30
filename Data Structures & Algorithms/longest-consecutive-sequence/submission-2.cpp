class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int lmax = 0, l =0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]-1]==0&&m[nums[i]]!=1){
                m[nums[i]]--;
            }
            else if(m[nums[i]-1]==0){
                int p = nums[i];
                while(m[p]>0){
                    p++;
                    l++;
                }
                lmax = max(lmax,l);
                l=0;
            }
        }
        return lmax;
    }
};
