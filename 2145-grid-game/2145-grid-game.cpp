class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // take pref sum of first row and suffix sum of second row
        // first robot has to change row at some point
        // so there will be 2 groups left for robot 2
        // Either the right part of top row which is not traversed by robot 1
        // or the left part of bottom row which is not traversed by robot 1
        // we have to find min of both
        int n=grid[0].size();
        vector<vector<long long>> arr(2,vector<long long>(n));
        for(int i=0;i<n;++i){
            arr[0][i]=grid[0][i];
            arr[1][i]=grid[1][i];
        }
        for(int i=1;i<n;++i){
            // first row pref sum
            arr[0][i]+=arr[0][i-1];
            // second row suff sum
            arr[1][n-i-1]+=arr[1][n-i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;++i){
            long long maxFromHere=0;
            if(i<n-1){
                maxFromHere=max(maxFromHere,arr[0][n-1]-arr[0][i]);
            }
            if(i>0){
                maxFromHere=max(maxFromHere,arr[1][0]-arr[1][i]);
            }
            ans=min(ans,maxFromHere);
        }
        return ans;
    }
};