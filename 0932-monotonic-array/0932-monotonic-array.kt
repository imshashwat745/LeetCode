class Solution {
    fun isMonotonic(nums: IntArray): Boolean {
        if(nums.size <= 1)return true
        var i=1
        var inc=0
        while(i<nums.size){
            if(nums[i]>nums[i-1]){
                if(inc==1)return false
                inc=2
            }
            if(nums[i]<nums[i-1]){
                if(inc==2)return false
                inc=1
            }
            ++i
        }
        return true
    }
}