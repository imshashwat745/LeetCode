class Solution {
    fun findMedianSortedArrays(arr1: IntArray, arr2: IntArray): Double {
        if(arr2.size<arr1.size)return findMedianSortedArrays(arr2,arr1)
        var f:Int=0
        var l:Int=arr1.size
        var sz:Int=arr1.size+arr2.size
        var t:Int=sz/2
        while(f<=l){
            var mid:Int=f+((l-f) shr 1)
            var mid2:Int=t-mid
            if(mid2<0){
                l=mid-1
                continue
            }
            var l1:Int=Int.MIN_VALUE
            var l2:Int=Int.MIN_VALUE
            var r1:Int=Int.MAX_VALUE
            var r2:Int=Int.MAX_VALUE
            if(mid>0)l1=arr1[mid-1]
            if(mid2>0)l2=arr2[mid2-1]
            if(mid<arr1.size)r1=arr1[mid]
            if(mid2<arr2.size)r2=arr2[mid2]
            if(l2>r1){
                f=mid+1
            }else if(l1>r2){
                l=mid-1
            }
            else{
                if(sz and 1!=0)return min(r1,r2)*1.0
                return ((max(l1,l2)+min(r1,r2))*1.0)/2
            }
        }
        return -1.0
    }
}