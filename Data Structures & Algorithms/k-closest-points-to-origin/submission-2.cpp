class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            int dis = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            if(pq.size()<k) pq.push({dis,i});
            else if(dis<pq.top().first){
                pq.pop();
                pq.push({dis,i});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
