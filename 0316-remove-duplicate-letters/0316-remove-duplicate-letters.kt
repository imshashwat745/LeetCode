class Solution {
    fun removeDuplicateLetters(s: String): String {
        var mp=Array<Int>(26){0}
        var found=Array<Boolean>(26){false}
        for(ch in s){
            ++mp[ch.toInt()-97]
        }
        var st=Stack<Char>()
        var ans:String=""
        for(ch in s){
            val x=ch.toInt()-97
            // if(mp[x]==1){
            //     st.push(ch)
            //     found[x]=true
            //     continue
            // }
            while(st.size>0&&st.peek()>ch&&mp[st.peek().toInt()-97]>=1&&
            found[x]==false){
                found[st.peek().toInt()-97]=false
                st.pop()
            }
            if(found[x]==false)st.push(ch)
            --mp[x]
            found[x]=true
        }
        while(st.size>0){
            ans+=st.peek()
            st.pop()
        }
        return ans.reversed()
    }
}