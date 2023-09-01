class Solution {
public:
// [5,5,5,5]-imp test case ,dont be too greedy,be greedy
    int minimumRounds(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x:arr){
            ++mp[x];
        }
        for(auto x:mp){
            if(x.second<2)return -1;
            ans+=ceil((1.0*x.second)/3);
        }
        return ans;
    }
};