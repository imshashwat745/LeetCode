class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int i,j,n=arr.size();
        for(i=0;i<n;++i){
            for(j=i+1;j<n;++j){
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(i=0;i<n;++i){
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};