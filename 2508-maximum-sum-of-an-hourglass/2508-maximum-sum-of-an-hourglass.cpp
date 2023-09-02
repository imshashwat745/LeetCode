class Solution {
public:
    int maxSum(vector<vector<int>>& arr) {
        vector<vector<int>> pref(arr);
        int i,j,m=arr.size(),n=arr[0].size();
        // pref sum on each row column wise
        for(i=0;i<m;++i){
            for(j=1;j<n;++j){
                pref[i][j]+=pref[i][j-1];
            }
        }

        int ans=0;
        for(int i=0;i<m-2;++i){
            for(j=2;j<n;++j){
                int curr=pref[i][j];
                curr+=pref[i+2][j];
                if(j-3>=0){
                    curr-=pref[i][j-3];
                    curr-=pref[i+2][j-3];
                }
                curr+=arr[i+1][j-1];
                ans=max(curr,ans);
            }
        }
        return ans;
    }
};