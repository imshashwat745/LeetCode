class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int idx=m+n-1,i=m-1,j=n-1;
        while(idx>-1&&j>-1&&i>-1){
            if(arr1[i]>arr2[j]){
                arr1[idx--]=arr1[i--];
            }else arr1[idx--]=arr2[j--];
        }
        while(j>-1)arr1[idx--]=arr2[j--];
    }
};