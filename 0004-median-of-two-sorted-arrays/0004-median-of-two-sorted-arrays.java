class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length>nums2.length)
            return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.length,n2=nums2.length,f=0,l=n1,mid=f+(l-f)/2;
        int req=(n1+n2)/2;
        if(((n1+n2)&1)!=0)
            ++req;
        while(f<=l){
            int f1=(mid-1)==-1?Integer.MIN_VALUE:nums1[mid-1];
            int f2=mid==n1?Integer.MAX_VALUE:nums1[mid];
            int idx=req-((mid-1)+1)-1;
            int s1=idx==-1?Integer.MIN_VALUE:nums2[idx];
            int s2=(idx+1)==n2?Integer.MAX_VALUE:nums2[idx+1];
            if(f1>s2){
                l=mid-1;
            }
            else if(s1>f2){
                f=mid+1;
            }
            else{
               // System.out.println(req);
                if(((n1+n2)&1)!=0)
                    return Math.max(f1,s1);
                double val1=Math.max(f1,s1);
                double val2=Math.min(f2,s2);
                // System.out.println(f2);
                // System.out.println(s1);
                // System.out.println(s2);
                return (val1+val2)/2;
            }
            mid=f+(l-f)/2;
        }
        return -1;
    }
}