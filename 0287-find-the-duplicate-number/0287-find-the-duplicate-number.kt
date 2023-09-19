class Solution {
    fun findDuplicate(nums: IntArray): Int {
        var mp=HashMap<Int,Int>()
        for(num in nums){
            var c:Int=0
            c=mp.getOrDefault(num,0)+1
            mp.put(num,c)
        }
        for((k,v) in mp){
            if(v>1)return k
        }
        return -1
    }
}