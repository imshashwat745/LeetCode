class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        vector<int> curr;
        curr.reserve(arr.size());
        int i=0,ans=1;
        for(int i=0;i<arr.size();++i){
            int ch=arr[i][1];
            int idx=lower_bound(curr.begin(),curr.end(),ch)-curr.begin();
            if(idx>=curr.size()){
                curr.push_back(ch);
            }
            else curr[idx]=ch;
            ans=max(ans,idx+1);
        }
        return ans;
    }
};