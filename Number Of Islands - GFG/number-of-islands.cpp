//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

 class dsu{
      public:
      int *rank;
      int *parent;
      dsu(int n){
          rank=new int[n];
          parent=new int[n];
          int i;
          for(i=0;i<n;++i){
              rank[i]=0;
              parent[i]=i;
          }
      }
      int find(int n){
          //with path compression
          if(n==parent[n])return n;
          return parent[n]=find(parent[n]);
      }
      void set_union(int x,int y){
          int a=find(x);
          int b=find(y);
		  if(x==y)return;
          if(rank[a]>rank[b])parent[b]=a;
          else if(rank[b]>rank[a])parent[a]=b;
          else{
              parent[b]=a;
              ++rank[a];
          }
      }
  };

class Solution {
  public:
  int calcVal(int i,int j,int m,int n){
      int val=0;
      val+=(i*n);
      val+=j;
      return val;
  }
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &arr) {
        // code here
        dsu ob(m*n);
        int i,j,c=0;
        vector<int> ans(arr.size(),0);
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(i=0;i<arr.size();++i){
            int ii=arr[i][0],jj=arr[i][1];
            if(mat[ii][jj]==1){
                ans[i]=c;
                continue;
            }
            ++c;
            // cout<<ii<<" "<<jj<<endl;
            mat[ii][jj]=1;
            int curr=calcVal(ii,jj,m,n);
            //up
            if(ii>0&&mat[ii-1][jj]==1){
                // cout<<"Up"<<endl;
                int x=calcVal(ii-1,jj,m,n);
                if(ob.find(curr)!=ob.find(x)){
                    // cout<<"Here "<<c<<endl;
                    ob.set_union(curr,x);
                    --c;
                }
            }
            //down
            if(ii<m-1&&mat[ii+1][jj]==1){
                int x=calcVal(ii+1,jj,m,n);
                if(ob.find(curr)!=ob.find(x)){
                    ob.set_union(curr,x);
                    --c;
                }
            }
            //left
            if(jj>0&&mat[ii][jj-1]==1){
                int x=calcVal(ii,jj-1,m,n);
                if(ob.find(curr)!=ob.find(x)){
                    ob.set_union(curr,x);
                    --c;
                }
            }
            //right
            if(jj<n-1&&mat[ii][jj+1]==1){
                int x=calcVal(ii,jj+1,m,n);
                if(ob.find(curr)!=ob.find(x)){
                    ob.set_union(curr,x);
                    --c;
                }
            }
            ans[i]=c;
            // cout<<"----------------------------------------------"<<endl;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends