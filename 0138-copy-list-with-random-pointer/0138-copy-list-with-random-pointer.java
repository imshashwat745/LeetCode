/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head==null)
            return null;
        Map<Node,Node> mp=new HashMap<>();
        Node head2=new Node(head.val);
        mp.put(head,head2);
        Node t=head,t2=head2;
        while(t!=null){
            Node nxt=t.next,rnd=t.random;
            if(mp.containsKey(nxt)){
                t2.next=mp.get(nxt);
            }
            else if(nxt!=null){
                Node x=new Node(nxt.val);
                t2.next=x;
                mp.put(nxt,x);
            }
            if(mp.containsKey(rnd)){
                t2.random=mp.get(rnd);
            }
            else if(rnd!=null){
                Node x=new Node(rnd.val);
                t2.random=x;
                mp.put(rnd,x);
            }
            t=t.next;
            t2=t2.next;
        }
        return head2;
    }
}