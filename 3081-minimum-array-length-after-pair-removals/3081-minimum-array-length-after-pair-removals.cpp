class Solution {
public:
    int minLengthAfterRemovals(vector<int>& arr) {
        
        int n=arr.size(),mid=n/2,i=mid-1,j=n-1;
        int ans=n;
        while(i>=0&&j>=mid){
           if(arr[i]<arr[j]){
               ans-=2;
               --i;
               --j;
           }
            else --i;
        }
        return ans; 
    }
};