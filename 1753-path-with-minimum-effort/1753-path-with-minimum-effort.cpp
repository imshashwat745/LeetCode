class Solution {
private:
    bool bound(int i,int j,int m,int n){
        return i>-1&&j>-1&&i<m&&j<n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        using vi=vector<int>;
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        pq.push({0,0,0});
        int ans=0;
        while(!pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            int wt=pq.top()[0];
            pq.pop();
            if(vis[i][j])continue;
            vis[i][j]=true;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int idx=0;idx<4;++idx){
                int x=dx[idx]+i,y=dy[idx]+j;
                if(!bound(x,y,m,n))continue;
                if(vis[x][y])continue;
                int cost=abs(arr[i][j]-arr[x][y]);
                if(dist[x][y]>max(wt,cost)){
                    dist[x][y]=max(wt,cost);
                    pq.push({max(wt,cost),x,y});
                }
            }
        }
        return dist[m-1][n-1];
    }
};