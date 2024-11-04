    void dfs(int node,vector<int>adj[],vector<bool>&visited,vector<int>&ans){
        visited[node]=true;
        ans.push_back(node);
        for (auto it:adj[node]){
            if (!visited[it]){
                dfs(it,adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        int start=0;
        vector<bool>visited(V,0);
        dfs(start,adj,visited,ans);
        return ans;
    }
    /*
      V - Total number of vertices/node
      E - Total number of edges
      Time Complexity - 1. Directed Graph - O(V+E)
                        2. Undirected Graph - O(V+2E)

      
      Space Complexity - O(3N)
                         1. O(N) - visited array
                         2. O(N) - answer array
                         3. O(N) - recursive stack

                         adjacency list - O(V+E)
    */