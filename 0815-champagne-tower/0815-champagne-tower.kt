import java.util.LinkedList
import java.util.Queue
class Solution {
    fun champagneTower(poured: Int, qr: Int, qc: Int): Double {
        val q: Queue<List<Int>> = LinkedList()
        val mp: Array<Array<Double>> = Array(101){Array(101){0.0}}
        val vis=Array(101){Array(101){false}}
        q.offer(listOf(0,0))
        mp[0][0]=poured.toDouble()
        vis[0][0]=true
        while(!q.isEmpty()){
            var i=q.peek()[0]
            var j=q.peek()[1]
            q.remove()
            if(mp[i][j]<=1||i==99)continue
            var curr:Double=((mp[i][j]-1)*1.0)/2;
            if(!vis[i+1][j]){
                q.offer(listOf(i+1,j));
                vis[i+1][j]=true;
            }
            if(!vis[i+1][j+1]){
                q.offer(listOf(i+1,j+1));
                vis[i+1][j+1]=true;
            }
            mp[i+1][j]+=curr;
            mp[i+1][j+1]+=curr;
        }
        return min(mp[qr][qc],1.0)
    }
}