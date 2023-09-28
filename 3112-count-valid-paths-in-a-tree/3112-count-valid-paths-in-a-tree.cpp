class Solution {
private:
    long long ans;
    vector<bool> seive(int n){
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=0;i*i<=n;++i){
            if(!prime[i])continue;
            for(int j=i*i;j<=n;j+=i)prime[j]=false;
        }
        return prime;
    }
    pair<int,int> help(vector<int> adj[],vector<bool> &prime,int v,int par,int cur){
        if(prime[v])++cur;
        int zero=0;
        int one=0;
        vector<pair<int,int>> curr;
        curr.reserve(adj[v].size());
        int idx=0;
        for(int i=0;i<adj[v].size();++i){
            if(par==adj[v][i])continue;
            curr.push_back(help(adj,prime,adj[v][i],v,cur));
            zero+=curr[idx].first;
            one+=curr[idx].second;
            ++idx;
        }
        long long z=0;
        for(int i=0;i<curr.size();++i){
            if(prime[v]){
                ans+=1ll*curr[i].first;
                z+=1ll*(zero-curr[i].first)*curr[i].first;
            }else{
                ans+=1ll*curr[i].second;
                z+=1ll*(zero-curr[i].first)*curr[i].second;
                z+=1ll*(one-curr[i].second)*curr[i].first;
            }
        }
        z/=2;
        ans+=z;
        if(prime[v]){
            return {0,zero+1};
        }
        return {zero+1,one};
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<bool> prime=seive(n);
        vector<int> adj[n+1];
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        ans=0;
        help(adj,prime,1,-1,0);
        return ans;
    }
};