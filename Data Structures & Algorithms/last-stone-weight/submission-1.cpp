class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone:stones) pq.push(stone);
        while(!pq.empty()){
            if(pq.size()==1) return pq.top();
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int s3 = abs(s1-s2);
            if(s3>0) pq.push(s3);
        }
        return 0;
    }
};
