class Solution {
public:
    long long maxSum(vector<int>& arr, int m, int k) {
        long long curr=0,ans=0;
        int i=0,j=0;
        unordered_map<int,int> mp;
        while(j<arr.size()){
            ++mp[arr[j]];
            curr+=(1ll*arr[j]);
            if(j-i+1==k){
                if(mp.size()>=m&&curr>ans)ans=curr;
                --mp[arr[i]];
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                curr-=arr[i];
                ++i;
            }
            ++j;
        }
        return ans;
    }
};