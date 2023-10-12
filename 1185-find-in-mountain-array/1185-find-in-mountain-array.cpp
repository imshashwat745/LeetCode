/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int bs(MountainArray &arr,int t,bool left,int f,int l){
        int ans=-1;
        while(f<=l){
            int mid=f+((l-f)>>1);
            int b=arr.get(mid);
            if(t==b){
                ans=mid;
                if(left)l=mid-1;
                else f=mid+1;
            }
            else if(t<b){
                if(left)l=mid-1;
                else f=mid+1;
            }
            else{
                if(!left)l=mid-1;
                else f=mid+1;
            }
        }
        return ans;
    }
public:
    int findInMountainArray(int t, MountainArray &arr) {
        int idx=-1,f=0,l=arr.length()-1;
        while(f<=l){
            int mid=f+((l-f)>>1);
            int a=-1,b=arr.get(mid),c=-1;
            if(mid>0)a=arr.get(mid-1);
            if(mid<arr.length())c=arr.get(mid+1);
            if(mid>0&&mid<arr.length()-1&&b>a&&b>c){
                idx=mid;
                break;
            }
            else if(mid==0||b>a)f=mid+1;
            else l=mid-1;
        }
        int ans_left=bs(arr,t,true,0,idx);
        if(ans_left!=-1)return ans_left;
        int ans_right=bs(arr,t,false,idx+1,arr.length()-1);
        return ans_right;
    }
};