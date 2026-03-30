class Solution {
public:
    unordered_map<string, vector<string>> m;
    int bfs(string node, string end, unordered_map<string,int> &vis){
        vis[node]=1;
        queue<pair<string,int>> q;
        q.push({node,1});
        while(!q.empty()){
            string curr = q.front().first;
            int count = q.front().second;
            q.pop();
            if(curr==end){
                return count;
            }
            for(auto it: m[curr]){
                if(!vis[it]){
                    q.push({it,count+1});
                    vis[it]=1;
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        wordList.push_back(beginWord);
        int n = wordList.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(wordList[i]==endWord){
                    flag = true;
                }
                int c = 0;
for(int k = 0; k < wordList[i].size(); k++){
    if(wordList[i][k] != wordList[j][k]){
        c++;
        if(c > 1) break;
    }
}
                if(c==1){
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if (!flag) return 0;
        unordered_map<string,int> vis;
        return bfs(beginWord, endWord, vis);
    }
};
