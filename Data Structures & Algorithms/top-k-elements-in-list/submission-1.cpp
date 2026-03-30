class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>> v(10001);
        for(auto it : m){
            v[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=10000;i>0; i--){
            while(k>0&&v[i].size()){
                ans.push_back(v[i][v[i].size()-1]);
                v[i].pop_back();
                k--;
            }
            if(k<=0) break;
        }
        return ans;
    }
};
