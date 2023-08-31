class Solution {
public:
    int minimizeSum(vector<int>& arr) {
        if(arr.size()<=3)return 0;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=arr[n-1]-arr[2];
        ans=min(ans,arr[n-2]-arr[1]);
        ans=min(ans,arr[n-3]-arr[0]);
        return ans;
    }
};