class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int arr[2001]={0};
        vector<vector<int>> v(10001);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]+1000]++;
        }
        for(int i=0;i<2001;i++){
            v[arr[i]].push_back(i);
        }
        for(int i=10000;i>0;i--){
            while(k>0&&v[i].size()){
                ans.push_back(v[i][v[i].size()-1]-1000);
                v[i].pop_back();
                k--;
            }
            if(k<=0) break;
        }
        return ans;
    }
};
