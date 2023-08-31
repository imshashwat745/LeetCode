class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size()!=nums2.size())return -1;
        long long remainingInc=0;
        long long remainingDec=0;
        int n=nums1.size();
        for(int i=0;i<n;++i){
            if(nums1[i] == nums2[i])continue;
            else if(nums2[i]>nums1[i]){
                int diff=nums2[i]-nums1[i];
                if(k == 0 || diff % k)return -1;
                remainingDec+=1ll*(diff/k);
            }
            else{
                int diff=nums1[i]-nums2[i];
                if(k == 0 || diff % k)return -1;
                remainingInc+=1ll*(diff/k);
            }
        }
        if(remainingInc == remainingDec)return remainingInc;
        return -1;
    }
};