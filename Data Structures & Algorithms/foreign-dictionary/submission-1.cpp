class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegrees;
        for (auto &word : words) {
            for (char c : word) {
                indegrees[c] = 0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            int j=0;
            while(j<words[i].size()&&j<words[i+1].size()){
                if(words[i][j]!=words[i+1][j]){
                    if (!adj[words[i][j]].count(words[i+1][j])) {
                        adj[words[i][j]].insert(words[i+1][j]);
                        indegrees[words[i+1][j]]++;
                    }
                    break;
                }
                j++;
            }
            if(j==words[i+1].size()&&j<words[i].size()) return "";
        }
        queue<char> q;
        for(auto it: indegrees){
            if(it.second==0){
                q.push(it.first);
            }
        }
        string ans="";
        while(!q.empty()){
            char curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]){
                indegrees[it]--;
                if(indegrees[it]==0){
                    q.push(it);
                }
            }
        }
        if (ans.size() != indegrees.size()) return "";
        return ans;
    }
};
