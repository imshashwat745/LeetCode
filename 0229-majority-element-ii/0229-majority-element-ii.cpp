class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int c1=0,c2=0,el1=INT_MAX,el2=INT_MAX;
        for(auto x: arr){
            if(c1==0 && x!=el2){
                ++c1;
                el1=x;
            }else if(c2==0 && x!=el1){
                ++c2;
                el2=x;
            }
            else if(x==el1)++c1;
            else if(x==el2)++c2;
            else{
                --c1;
                --c2;
            }
        }
        c1=0;c2=0;
        for(auto x: arr){
            if(x==el1)++c1;
            if(x==el2)++c2;
        }
        int n=arr.size();
        vector<int> ans;
        if(c1>n/3)ans.push_back(el1);
        if(c2>n/3)ans.push_back(el2);
        return ans;
    }
};