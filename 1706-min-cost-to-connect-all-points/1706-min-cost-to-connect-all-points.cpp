class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n=points.size(),i,j;
        vector<pair<int,int>> adj[n];
        for(i=0;i<n;++i){
          for(j=i+1;j<n;++j){
            int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            adj[i].push_back({j,dist});
            adj[j].push_back({i,dist});
          }
        }
        vector<bool> vis(n,false);
        using pp=pair<int,int>;
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
          if(vis[pq.top().second]){
            pq.pop();
            continue;
          }
          int v=pq.top().second;
          int wt=pq.top().first;
          pq.top();
          vis[v]=true;
          ans+=wt;
          for(auto x:adj[v]){
            int u=x.first;
            int w=x.second;
            if(vis[u])continue;
            pq.push({w,u});
          }
        }
        return ans;
    }
};