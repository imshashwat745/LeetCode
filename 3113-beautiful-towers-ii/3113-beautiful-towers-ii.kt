class Solution {
    fun leftSmaller(arr: List<Int>): List<Int>{
        var st=Stack<Int>()
        var ans=ArrayList<Int>()
        st.push(-1)
        var i=0
        while(i<arr.size){
            while(st.size>1&&arr[st.peek()]>arr[i])st.pop()
            ans.add(st.peek())
            st.push(i)
            ++i
        }
        return ans
    }
    fun rightSmaller(arr: List<Int>): List<Int>{
        var st=Stack<Int>()
        var ans=ArrayList<Int>()
        st.push(arr.size)
        var i=arr.size-1
        while(i>-1){
            while(st.size>1&&arr[st.peek()]>arr[i])st.pop()
            ans.add(st.peek())
            st.push(i)
            --i
        }
        return ans.reversed()
    }
    fun maximumSumOfHeights(arr: List<Int>): Long {
        var l=leftSmaller(arr)
        var r=rightSmaller(arr)
        var ls=Array<Long>(arr.size){0}
        var rs=Array<Long>(arr.size){0}
        var i=0
        while(i<arr.size){
            ls[i]=(1L)*(i-l[i])*arr[i]
            if(l[i]!=-1)ls[i]+=ls[l[i]]
            ++i;
        }
        i=arr.size-1
        while(i>-1){
            rs[i]=(1L)*(r[i]-i)*arr[i]
            if(r[i]!=arr.size)rs[i]+=rs[r[i]]
            --i;
        }
        var ans: Long=0
        i=0
        while(i<arr.size){
            ans=max(ans,ls[i]+rs[i]-arr[i])
            ++i
        }
        return ans
    }
}