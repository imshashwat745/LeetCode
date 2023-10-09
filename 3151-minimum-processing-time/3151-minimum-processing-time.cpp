class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& arr) {
        sort(p.begin(),p.end());
        sort(arr.begin(),arr.end(),greater<int>());
        int ans=0;
        for(int i=0;i<p.size();++i){
            ans=max(ans,p[i]+arr[4*i]);
            ans=max(ans,p[i]+arr[4*i+1]);
            ans=max(ans,p[i]+arr[4*i+2]);
            ans=max(ans,p[i]+arr[4*i+3]);
        }
        return ans;
    }
};