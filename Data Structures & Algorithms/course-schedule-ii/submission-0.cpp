class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegrees[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int c= q.front();
            q.pop();
            ans.push_back(c);
            for(auto it: adj[c]){
                indegrees[it]--;
                if(indegrees[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses){
            reverse(ans.begin(),ans.end());
            return ans;
        }
        else return {};
    }
};
