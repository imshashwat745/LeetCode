class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> arr(n+1);
        for(int i=0;i<ranges.size();++i){
            arr[i]={max(0,i-ranges[i]),i+ranges[i]};
        }
        sort(arr.begin(),arr.end(),cmp);
        int curr=0,i=0,ans=0;
        while(i<=n&&curr<n){
            if(arr[i][0]>curr)return -1;
            int j=i;
            int maxi=arr[i][1];
            while(j<n&&arr[j][0]<=curr){
                maxi=max(arr[j][1],maxi);
                ++j;
            }
            curr=maxi;
            ++ans;
            i=j;
        }
        if(curr<n)return -1;
        return ans;
    }
};