class Solution {
private:
    int help(vector<int> adj[],int v,unordered_set<int> &st,int par){
        if(st.find(v)!=st.end())return 0;
        int ans=1;
        for(auto u:adj[v]){
            if(u==par)continue;
            ans+=help(adj,u,st,v);
        }
        return ans;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        unordered_set<int> st;
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(auto v:restricted)st.insert(v);
        return help(adj,0,st,-1);
    }
};