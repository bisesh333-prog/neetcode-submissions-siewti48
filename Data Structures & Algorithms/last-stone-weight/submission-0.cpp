class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int p1 = pq.top();
            pq.pop();
            int p2 = pq.top();
            pq.pop();
            if(p1!=p2){
                pq.push(p1-p2);
            }
        }
        if(!pq.empty()) return pq.top();
        else return 0;
        }
};
