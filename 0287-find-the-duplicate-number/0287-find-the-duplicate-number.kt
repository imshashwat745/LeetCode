class Solution {
    fun findDuplicate(arr: IntArray): Int {
        var slow=arr[0]
        var fast=arr[arr[0]]
        while(slow!=fast){
            slow=arr[slow]
            fast=arr[arr[fast]]
        }
        slow=0
        while(slow!=fast){
            slow=arr[slow]
            fast=arr[fast]
        }
        return slow
    }
}