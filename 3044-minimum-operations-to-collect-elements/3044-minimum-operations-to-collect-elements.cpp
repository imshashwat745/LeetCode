class Solution {
public:
    int minOperations(vector<int>& arr, int k) {
        unordered_set<int> st;
        int ans=0;
        for(int i=arr.size()-1;i>-1;--i){
            if(arr[i]<=k&&arr[i]>=1)st.insert(arr[i]);
            ++ans;
            if(st.size()==k)return ans;
        }
        return -1;
    }
};