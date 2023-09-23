class Solution {
    fun isPossible(s1: String,s2: String): Boolean{
        if(s2.length-s1.length!=1)return false;
        var i=0
        var j=0;
        var found=false;
        while(i<s1.length&&j<s2.length){
            if(s1[i]==s2[j]){
                ++i;
                ++j;
                continue;
            }
            if(!found){
                ++j;
                found=true;
                continue;
            }
            return false;
        }
        if(j==s2.length-1)return !found;
        // return i==s1.size()&&j==s2.size();
        return true;
    }
    fun help(arr: Array<String>, i: Int, prev: Int, dp: Array<Array<Int>>):Int{
        if(i == arr.size)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1){
            dp[i][prev+1]=max(1+help(arr,i+1,i,dp),help(arr,i+1,prev,dp));
            return dp[i][prev+1];
        }
        if(arr[i].length==arr[prev].length+1 
        && isPossible(arr[prev],arr[i])){
            dp[i][prev+1]=max(1+help(arr,i+1,i,dp),help(arr,i+1,prev,dp));
            return dp[i][prev+1];
        }
        dp[i][prev+1]=help(arr,i+1,prev,dp);
        return dp[i][prev+1]
    }
    fun longestStrChain(arr2: Array<String>): Int {
        var arr=arr2.sortedWith(compareBy { it.length }).toTypedArray()
        var dp=Array(arr.size){Array(arr.size+1){-1}};
        return help(arr,0,-1,dp);
    }
}