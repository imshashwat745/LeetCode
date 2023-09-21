class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> curr;
        curr.reserve(arr.size());
        int ans=1;
        for(auto x:arr){
            int idx=lower_bound(curr.begin(),curr.end(),x)-curr.begin();
            if(idx>=curr.size()){
                curr.push_back(x);
            }
            else curr[idx]=x;
            ans=max(ans,idx+1);
        }
        return ans;
    }
};