class Solution {
    fun decodeAtIndex(s: String, x: Int): String {
        // First calculate total length of the string after decoding
        // Then moving backwards find keep reducing the string and K also by mod
        var len:Long=0
        var k:Long=x.toLong()
        for(i in s){
            var ch=i.toInt()-48
            if(ch>=1&&ch<=9)len*=ch
            else ++len
        }
        var i=s.length-1
        while(i>=0){
            var ch=s[i].toInt()-48
            if(k>len)k%=len
            if(ch>=1&&ch<=9){
                len/=ch
                --i
                continue
            }
            if(k==0L||k==len)return s[i].toString()
            --len
            --i;
        }
        return s[0].toString()
    }
}