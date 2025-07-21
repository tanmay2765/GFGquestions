class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Build adjacency list and calculate in-degrees
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        
        // Build the graph from edge list
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];  // Fixed: was "edge[i][0]"
            int v = edges[i][1];  // Fixed: was "edge[i][1]"
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return result;
    }
};