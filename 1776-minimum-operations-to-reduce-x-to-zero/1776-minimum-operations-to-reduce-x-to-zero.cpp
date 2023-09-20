class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int req=accumulate(arr.begin(),arr.end(),0)-x;
        if(req<0)return -1;
        if(req==0)return arr.size();
        int ans=-1;
        int i=0,j=0,curr=0;
        while(j<arr.size()){
            curr+=arr[j];
            while(i<j&&curr>req){
                curr-=arr[i];
                ++i;
            }
            if(curr==req){
                ans=max(ans,j-i+1);
            }
            ++j;
        }
        if(ans==-1)return -1;
        return arr.size()-ans;
    }
};