class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=size(nums), mini=1e9+8;
        vector<int> l(n, 1e9+8), r(n, -1e9-8);
        for(int i=0; i<n; i++){
            if(mini<nums[i]) l[i]=mini;
            mini=min(mini, nums[i]);
        }
        set<int> s;
        for(int i=n-1; i>=0; i--){
            auto it=s.lower_bound(nums[i]);
            if(it!=begin(s)){
                it--;
                r[i]=*it;
            }
            s.insert(nums[i]);
        }
        for(int i=0; i<n; i++) if(l[i]<r[i]) return true;
        return false;
    }
};