class Solution {
public:
    int dfs(vector<int> adj[],unordered_set<int> adj2[],int v,vector<bool> &vis,vector<int> &ans,int down,unordered_map<int,unordered_map<int,int>> &xx,unordered_map<int,int> &yy){
        vis[v]=true;
        ans[v]+=down;
        int res=0;
        for(auto u:adj[v]){
            if(vis[u])continue;
            int nxt=0;
            int nxt2=1;
            if(adj2[u].find(v)!=adj2[u].end()){
                nxt=1;
                nxt2=0;
            }
            int curr=nxt2+dfs(adj,adj2,u,vis,ans,down+nxt,xx,yy);
            res+=curr;
            xx[v][u]=curr;
            yy[v]+=curr;
        }
        ans[v]+=res;
        return res;
        
    }
    
    int dfs2(vector<int> adj[],unordered_set<int> adj2[],int v,vector<bool> &vis,vector<int> &ans,int down,unordered_map<int,unordered_map<int,int>> &xx,unordered_map<int,int> &yy){
        vis[v]=true;
        ans[v]+=down;
        int res=0;
        for(auto u:adj[v]){
            if(vis[u])continue;
            int nxt=yy[v]-xx[v][u];
            int nxt2=1;
            if(adj2[u].find(v)!=adj2[u].end()){
                // nxt=1;
                nxt2=0;
            }
            int curr=nxt2+dfs2(adj,adj2,u,vis,ans,down+nxt,xx,yy);
            res+=curr;
        }
        return res;
        
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        unordered_set<int> adj2[n];
        for(auto edge:edges){
            int a=edge[0],b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            adj2[b].insert(a);
        }
        vector<int> ans(n,0);
        int root=0;
        for(int i=0;i<n;++i){
            if(adj2[i].size()==0){
                root=i;
                break;
            }
        }
         vector<bool> vis(n,false);
        
        unordered_map<int,unordered_map<int,int>> xx;
        unordered_map<int,int> yy;
        dfs(adj,adj2,root,vis,ans,0,xx,yy);
        vis=vector<bool>(n,false);
        dfs2(adj,adj2,root,vis,ans,0,xx,yy);
        return ans;
    }
};