class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx=abs(fx-sx);
        int dy=abs(fy-sy);
        if(max(dx,dy)==0&&t==1)return false;
        return max(dx,dy)<=t;
    }
};