class Solution {
private:
    int help(int n){
        int ans=0;
        while(n){
            if(n&1)++ans;
            n=n>>1;
        }
        return ans;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& arr, int k) {
        int ans=0;
        for(int x=0;x<arr.size();++x){
            if(help(x)==k)ans+=arr[x];
        }
        return ans;
    }
};