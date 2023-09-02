class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> prefSumMat(mat);
        int i,j,m=mat.size(),n=mat[0].size();
        for(i=0;i<m;++i){
            for(j=1;j<n;++j){
                prefSumMat[i][j]+=prefSumMat[i][j-1];
            }
        }
        for(i=1;i<m;++i){
            for(j=0;j<n;++j){
                prefSumMat[i][j]+=prefSumMat[i-1][j];
            }
        }

        vector<vector<int>> ans(m,vector<int>(n));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                int i_limit=min(m-1,i+k);
                int j_limit=min(n-1,j+k);
                ans[i][j]=prefSumMat[i_limit][j_limit];
                short count=0;
                if(j-k-1>=0){
                    ans[i][j]-=prefSumMat[i_limit][j-k-1];
                    ++count;
                }
                if(i-k-1>=0){
                    ans[i][j]-=prefSumMat[i-k-1][j_limit];
                    ++count;
                }
                if(count==2){
                    ans[i][j]+=prefSumMat[i-k-1][j-k-1];
                }
            }
        }
        return ans;
    }
};