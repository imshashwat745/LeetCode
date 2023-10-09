class Solution {
private:
    int help(vector<int> &arr,int t,bool findFirst){
        int f=0,l=arr.size()-1,ans=-1;
        while(f<=l){
            int mid=f+((l-f)>>1);
            if(arr[mid]==t){
                ans=mid;
                if(findFirst)l=mid-1;
                else f=mid+1;
            }
            else if(t<arr[mid])l=mid-1;
            else f=mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {help(nums,target,true),help(nums,target,false)};
    }
};