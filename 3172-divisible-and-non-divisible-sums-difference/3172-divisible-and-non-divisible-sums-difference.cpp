class Solution {
public:
    int differenceOfSums(int n, int m) {
        int mm=n/m;
        int total=(n*(n+1))/2;
        int nums1=((2*m+(mm-1)*m)*mm)/2;
        int nums2=total-nums1;
        return nums2-nums1;
    }
};