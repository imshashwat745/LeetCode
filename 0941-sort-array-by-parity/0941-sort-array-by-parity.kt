class Solution {
    fun sortArrayByParity(nums: IntArray): IntArray {
        var even=0
        var odd=0
        while(even<nums.size && odd<nums.size){
            if(nums[even] and 1 == 1){
                ++even
                continue
            }
            else if(nums[odd] and 1 == 0){
                ++odd
                continue
            }
            else if(odd>even){
                ++even
                continue
            }
            var t=nums[odd]
            nums[odd]=nums[even]
            nums[even]=t
            ++odd
            ++even
        }
        return nums
    }
}