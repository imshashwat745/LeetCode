class Solution {
public:
    int bestClosingTime(string s) {
        vector<int> penalty(s.size()+1,0);
        int curr=0;
        for(int i=0;i<s.size();++i){
            penalty[i]=curr;
            if(s[i]=='N')++curr;
        }
        // Imp Condition
        penalty[s.size()]=curr;
        curr=0;
        int ans=s.size();
        for(int i=s.size()-1;i>-1;--i){
            if(s[i]=='Y')++curr;
            penalty[i]+=curr;
            if(penalty[ans]>=penalty[i])ans=i;
        }
        return ans;
    }
};