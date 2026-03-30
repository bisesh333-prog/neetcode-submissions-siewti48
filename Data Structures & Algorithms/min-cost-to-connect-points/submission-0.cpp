class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vis(n, 0);

        using T = pair<int,int>; // {cost, node}
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0, 0}); // {cost, index}
        int ans = 0;

        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;   // ✅ important

            vis[u] = 1;             // ✅ mark here
            ans += dist;

            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int dis = abs(points[u][0] - points[v][0]) +
                              abs(points[u][1] - points[v][1]);
                    pq.push({dis, v});
                }
            }
        }

        return ans;
    }
};