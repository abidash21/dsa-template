//dfs

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

//kahn algo

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    vector<int>ans;
	    for (int i=0;i<V;i++){
	        for (auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for (int i=0;i<V;i++){
	        if (indegree[i]==0)
	        q.push(i);
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for (auto it:adj[node]){
	            indegree[it]--;
	            if (indegree[it]==0)
	            q.push(it);
	        }
	    }
	    return ans;
	}