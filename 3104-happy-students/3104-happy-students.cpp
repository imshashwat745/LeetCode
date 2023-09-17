class Solution {
public:
    int countWays(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=0,n=arr.size();
        if(n==0||arr[0]>0)++ans;
        for(int i=0;i<n;++i){
            if(i+1>arr[i]){
                if(i==n-1||i+1<arr[i+1])++ans;
            }
        }
        return ans;
    }
};