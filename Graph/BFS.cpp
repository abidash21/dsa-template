    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        queue<int>q;
        vector<int>visited(V,0);
        q.push(0);
        visited[0]++;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for (auto it:adj[node]){
                if (!visited[it]){
                q.push(it);
                visited[it]++;
                }
            }
        }
        return ans;
    }

    /*
       V - Total number of vertices
       E - Total number of edges
       TC - O(V+E)
       SC - O(3N): visted array,queue,answer array
    */