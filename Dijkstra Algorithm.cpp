// tc -> O(E logV)
// using set
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,1e9);
        dist[S]=0;
        
        set<pair<int,int>> s;
        s.insert({0,S});
        
        while(!s.empty()) {
            auto it = *(s.begin());
            
            int wt = it.first;
            int node = it.second;
            
            s.erase(it);
            
            for(auto itr : adj[node]) {
                int adjNode = itr[0];
                int adjWt = itr[1];
                
                if(wt + adjWt < dist[adjNode]) {
                    if(dist[adjNode]!= 1e9) {
                        s.erase({dist[adjNode],adjNode});  // important
                        
                    }
                    s.insert({wt+adjWt, adjNode});
                    dist[adjNode] = wt+adjWt;
                }
            }
        }
        return dist;
    }
};




// using priority queue
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V,1e9);
        dist[S]=0;
        
        pq.push({0, S});
        
        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for( auto it: adj[node]) {
                int adjNode = it[0];
                int adjWt = it[1];
                
                if(wt + adjWt < dist[adjNode]) {
                    dist[adjNode] = wt + adjWt;
                    pq.push({wt + adjWt, adjNode});
                }
            }
        }
        
        return dist;
    }
};
