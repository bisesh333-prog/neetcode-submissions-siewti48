class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string node) {
        while (!adj[node].empty()) {
            string next = adj[node].top();
            adj[node].pop();
            dfs(next);
        }
        result.push_back(node); // postorder
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &t : tickets) {
            adj[t[0]].push(t[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};