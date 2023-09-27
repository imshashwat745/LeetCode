class Solution {
    fun smallestSubsequence(s: String): String {
        var st=Stack<Char>()
        var mp=HashMap<Char,Int>()
        var found=HashSet<Char>()
        for(i in s){
            mp.put(i,mp.getOrDefault(i,0)+1)
        }
        for(i in s){
            if(found.contains(i)){
                mp.put(i,mp.getOrDefault(i,0)-1)
                continue
            }
            while(st.isEmpty()==false&&mp.getOrDefault(st.peek(),0)>=1&&st.peek()>i){
                found.remove(st.peek())
                st.pop()
            }
            if(!found.contains(i)){
                st.push(i)
                found.add(i)
            }
            mp.put(i,mp.getOrDefault(i,0)-1)
        }
        var ans=""
        while(!st.isEmpty()){
            ans+=st.peek()
            st.pop()
        }
        return ans.reversed()
    }
}