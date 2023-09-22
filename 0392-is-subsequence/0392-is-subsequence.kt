class Solution {
    fun isSubsequence(s: String, t: String): Boolean {
        var i=0
        var j=0
        if(s.length>t.length)return false
        while(i<s.length && j<t.length){
            if(s[i] == t[j]){
                ++i
            }
            ++j
        }
        return i==s.length
    }
}