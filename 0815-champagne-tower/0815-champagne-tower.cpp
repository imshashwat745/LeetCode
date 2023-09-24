class Solution {
public:
    double champagneTower(int poured, int qr, int qc) {
        queue<vector<int>> q;
        vector<vector<double>> mp(101,vector<double>(101,0));
        vector<vector<bool>> vis(101,vector<bool>(101,false));
        q.push({0,0});
        vis[0][0]=true;
        mp[0][0]=poured;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            q.pop();
            if(mp[i][j]<=1||i==99)continue;
            double curr=((mp[i][j]-1)*1.0)/2;
            if(!vis[i+1][j]){
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(!vis[i+1][j+1]){
                q.push({i+1,j+1});
                vis[i+1][j+1]=true;
            }
            mp[i+1][j]+=curr;
            mp[i+1][j+1]+=curr;
        }
        return min(mp[qr][qc],1.0);
    }
};