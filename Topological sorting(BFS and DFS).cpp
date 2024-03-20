// using BFS
// It has to be directed acyclic graph

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++) {
	        for(int j=0;j<adj[i].size();j++) {
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    
	    for(int i=0;i<V;i++) {
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    while(!q.empty()) {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it]==0) {
	                q.push(it);
	            }
	            
	        }
	        
	        
	        
	    }
	    return ans;
	}
};


// Using DFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node,vector<int> &vis ,stack<int> &st,vector<int> adj[]) {
	    vis[node]=1;
	    
	    for(auto it: adj[node]) {
	        if(!vis[it]) {
	            dfs(it, vis, st, adj);
	        }
	    }
	    st.push(node);
	    
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> vis(V,0);
	   
	   stack<int> st;
	   for(int i=0;i<V;i++,adj) {
	       if(!vis[i]) {
	           dfs(i,vis,st,adj);
	       }
	   }
	   vector<int> ans;
	   
	   while(!st.empty()) {
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   
	   return ans;
	}
};



