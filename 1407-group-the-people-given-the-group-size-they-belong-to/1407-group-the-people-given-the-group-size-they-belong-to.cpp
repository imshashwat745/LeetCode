class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
        vector<vector<int>> arr(grp.size());
        for(int i=0;i<grp.size();++i){
            arr[i]={grp[i],i};
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int i=0;
        while(i<arr.size()){
            int j=i;
            while(j<arr.size()&&j-i+1<=arr[i][0]&&arr[j][0]==arr[i][0])++j;
            if(j-i<arr[i][0])return {};
            vector<int> curr;
            for(int k=i;k<j;++k)curr.push_back(arr[k][1]);
            ans.push_back(curr);
            i=j;
        }
        return ans;
    }
};