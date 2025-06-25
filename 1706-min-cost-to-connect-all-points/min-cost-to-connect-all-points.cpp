class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        vector<bool> visited(n, false);
        int edges_used = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while(edges_used < n){
            auto [cost, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            min_cost += cost;
            edges_used++;

            for(int v=0; v<n; v++){
                if(!visited[v]){
                    int dist = abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    pq.push({dist, v});
                }
            }
        }

        return min_cost;
    }
};