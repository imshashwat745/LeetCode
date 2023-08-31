class Solution {
public:
    int minimumSeconds(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;++i){
            arr.push_back(arr[i]);
        }
        n*=2;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;++i){
            mp[arr[i]].push_back(i);
        }
        int ans=n/2;
        for(auto x:mp){
            int maxDiff=0;
            for(int i=1;i<x.second.size();++i){
                maxDiff=max(maxDiff,x.second[i]-x.second[i-1]);
            }
            ans=min(ans,maxDiff/2);
        }
        return ans;
    }
};