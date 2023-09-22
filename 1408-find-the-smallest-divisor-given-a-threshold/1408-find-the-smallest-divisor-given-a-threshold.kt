class Solution {
    private fun isPossible(nums: IntArray, mid: Int, t: Int): Boolean{
        var sum=0
        for(num in nums){
            sum+=ceil((num*1.0)/mid).toInt()
            if(sum>t)return false
        }
        return true
    }
    fun smallestDivisor(nums: IntArray, threshold: Int): Int {
        var maxi=0
        for(num in nums)maxi=max(maxi,num)
        var f=0
        var l=maxi
        var ans=maxi
        while(f<=l){
            var mid=f+((l-f) shr 1)
            if(isPossible(nums,mid,threshold)){
                ans=mid
                l=mid-1
            }else f=mid+1
        }
        return ans

    }
}