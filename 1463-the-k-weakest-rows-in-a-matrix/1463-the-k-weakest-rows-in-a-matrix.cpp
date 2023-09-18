class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
        int i,m=mat.size(),n=mat[0].size();
        priority_queue<pair<int,int>> pq;
        for(i=0;i<m;++i){
            int f=0,l=n-1,ans=0;
            while(f<=l){
                int mid=f+((l-f)>>1);
                if(mat[i][mid]==1){
                    ans=mid+1;
                    f=mid+1;
                }else l=mid-1;
            }
            if(pq.size()==k&&pq.top().first>ans)pq.pop();
            if(pq.size()<k)pq.push({ans,i});
        }
        vector<int> ans(k);
        i=k-1;
        while(!pq.empty()){
            ans[i--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};