class Solution {
public:
    int numIdenticalPairs(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0,ans=0;
        while(i<arr.size()){
            int j=i+1;
            while(j<arr.size()&&arr[j]==arr[i])++j;
            ans+=((j-i)*(j-i-1))/2;
            i=j;
        }
        return ans;
    }
};