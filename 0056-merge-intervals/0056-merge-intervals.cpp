class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        vector<vector<int>> ans;
        ans.reserve(arr.size());
        int i=0,j;
        while(i<arr.size()){
            j=i+1;
            int end=arr[i][1];
            while(j<arr.size()&&arr[j][0]<=end){
                end=max(end,arr[j][1]);
                ++j;
            }
            ans.push_back({arr[i][0],end});
            i=j;
        }
        return ans;
    }
};