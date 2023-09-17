class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) {
        unordered_map<int,unordered_map<int,int>> mp;
        for(auto x:arr){
            ++mp[x[0]][x[1]];
        }
        
        long long ans=0;
        for(auto x:arr){
            int i=x[0],j=x[1];
            for(int idx=0;idx<=k;++idx){
                int req_x=i^idx;
                int req_y=j^(k-idx);
                if(mp.find(req_x)==mp.end()||mp[req_x].find(req_y)==mp[req_x].end())continue;
                if(i==req_x&&j==req_y)--ans;
                ans+=mp[req_x][req_y];
            }
        }
        return ans/2;
    }
};