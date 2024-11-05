    /*
	    Topological Sort is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge 
		u->v, vertex u comes before vertex v before ordering.
	*/
	void dfs(int node, vector<int> adj[],stack<int>&st,vector<int>&vis){
	    vis[node]=1;
	    for (auto it:adj[node]){
	        if (!vis[it])
	        dfs(it,adj,st,vis);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    vector<int>ans;
	    for (int i=0;i<V;i++){
	        if (!vis[i])
	        dfs(i,adj,st,vis);
	    }
	    while(!st.empty()){
	        int node=st.top();
	        st.pop();
	        ans.push_back(node);
	    }
	    return ans;
	}

    /*
       TC: O(V+E)+O(V)
       SC: O(3V)
    */