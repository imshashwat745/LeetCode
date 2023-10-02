class Solution {
    fun winnerOfGame(arr: String): Boolean {
        var alice_points=0
        var bob_points=0
        var i=0
        while(i<arr.length){
            var j=i+1
            while(j<arr.length && arr[i]==arr[j])++j
            if(j-i>=3){
                if(arr[i]=='A')alice_points+=j-i-2
                else bob_points+=j-i-2
            }
            i=j
        }
        return alice_points>bob_points
    }
}