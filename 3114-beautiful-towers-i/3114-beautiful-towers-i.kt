class Solution {
    fun maximumSumOfHeights(arr: List<Int>): Long {
        var i=0
        var ans:Long=0
        var maxi=0
        while(i<arr.size){
            var j=i-1
            var curr:Long=arr[i].toLong()
            var mini=arr[i]
            while(j>=0){
                mini=min(mini,arr[j])
                curr+=mini.toLong()
                --j
            }
            j=i+1
            mini=arr[i]
            while(j<arr.size){
                mini=min(mini,arr[j])
                curr+=mini.toLong()
                ++j
            }
            ans=max(ans,curr)
            ++i
        }
        return ans
    }
}