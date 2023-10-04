class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int i,j,m=arr.size(),n=arr[0].size();
        bool row_0=false,col_0=false;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                    if(i==0){
                        row_0=true;
                    }
                    if(j==0){
                        col_0=true;
                    }
                }
            }
        }
        for(i=1;i<m;++i){
            for(j=1;j<n;++j){
                if(arr[0][j]==0||arr[i][0]==0)arr[i][j]=0;
            }
        }
        if(row_0)for(i=0;i<n;++i)arr[0][i]=0;
        if(col_0)for(i=0;i<m;++i)arr[i][0]=0;
    }
};