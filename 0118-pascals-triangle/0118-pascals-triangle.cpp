class Solution {
public:
    vector<vector<int>> generate(int k) {
        vector<vector<int>> res;
        vector<int> ans={1};
        while(k--){
            res.push_back(ans);
            vector<int> prev=ans;
            ans.clear();
            int no=0;
            for(auto i:prev){
                ans.push_back(no+i);
                no=i;
            }
            ans.push_back(no);
        }
        return res;
    }
};