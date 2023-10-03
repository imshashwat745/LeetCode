class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x:arr)++mp[x];
        for(auto x:mp)ans+=(x.second*(x.second-1))/2;
        return ans;
    }
};