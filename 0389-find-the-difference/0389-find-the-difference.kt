class Solution {
    fun findTheDifference(s: String, t: String): Char {
        if(t.length-s.length!=1)return '1';
        var mp=Array(26){0};
        for(x in t){
            // println(x.toInt()-97)
            ++mp[x.toInt()-97]
        }
        for(x in s){
            // println(x.toInt()-97)
            --mp[x.toInt()-97]
            if(mp[x.toInt()-97]<0)return  '1'
        }
        var i=0
        while(i<26){
            // println(mp[i])
            if(mp[i]==1)return ((i+97).toChar())
            ++i
        }
        return '1'
    }
}