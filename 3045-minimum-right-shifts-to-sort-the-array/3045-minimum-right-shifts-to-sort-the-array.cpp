class Solution {
public:
    int minimumRightShifts(vector<int>& arr) {
        int mini=0,n=arr.size();
        for(int i=1;i<arr.size();++i){
            if(arr[i]<arr[mini])mini=i;
        }
        int i=(mini+1)%n;
        int prev=arr[mini];
        while(i!=mini){
            if(arr[i]<prev)return -1;
            prev=arr[i];
            ++i;
            i%=n;
        }
        if(mini==0)return 0;
        return n-mini;
    }
};