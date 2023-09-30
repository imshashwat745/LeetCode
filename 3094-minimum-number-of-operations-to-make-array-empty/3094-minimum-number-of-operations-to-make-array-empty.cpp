class Solution {
public:
    int minOperations(vector<int>& arr) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto x:arr)++mp[x];
        for(auto x:mp){
            if(x.second==1)return -1;
            ans+=ceil((x.second*1.0)/3);
        }
        return ans;
    }
};