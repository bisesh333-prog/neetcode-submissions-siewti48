class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<wordList.size();i++){
            for(int j=i;j<wordList.size();j++){
                int c=0;
                for(int k=0;k<wordList[i].size();k++){
                    if(wordList[i][k]==wordList[j][k]) continue;
                    else{
                        c++;
                        if(c>1) break;
                    }
                }
                if(c<2){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<pair<int, string>> q;
        q.push({1,beginWord});
        unordered_map<string,int> vis;
        vis[beginWord]=1;
        while(!q.empty()){
            int l = q.front().first;
            string curr = q.front().second;
            q.pop();
            if(curr==endWord) return l;
            for(auto it: mp[curr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({l+1, it});
                }
            }
        }
        return 0;
    }
};
