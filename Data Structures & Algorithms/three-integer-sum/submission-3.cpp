class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0,j=1,k=nums.size()-1;
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        while(i<j&&j<k){
            int l=j,m=k;
            while(l<m){
                if(nums[i]+nums[l]+nums[m]==0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[m]);
                    st.insert(v);
                }
                if(nums[i]+nums[l]+nums[m]>0) m--;
                else l++;
            }
            i++;
            j++;
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};


