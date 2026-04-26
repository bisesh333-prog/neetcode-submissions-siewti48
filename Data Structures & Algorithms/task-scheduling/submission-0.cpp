class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> arr(26,0);
        for(auto task:tasks){
            arr[task-'A']++;
        }
        int maxf = *max_element(arr.begin(),arr.end()), maxCount=0;
        for(auto it:arr){
            if(it==maxf) maxCount++;
        }
        int time = (n+1)*(maxf-1)+maxCount;
        return max((int)tasks.size(),time);
    }
};
