class Solution {
public:
    int numberOfPoints(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int ans=0;
        int curr=0;
        for(int i=0;i<arr.size();++i){
            ans+=(arr[i][1]-arr[i][0]+1);
            if(curr>=arr[i][0]){
                int subtract=min(curr-arr[i][0]+1,arr[i][1]-arr[i][0]+1);
                ans-=subtract;
            }
            curr=max(curr,arr[i][1]);
        }
        return ans;
    }
};