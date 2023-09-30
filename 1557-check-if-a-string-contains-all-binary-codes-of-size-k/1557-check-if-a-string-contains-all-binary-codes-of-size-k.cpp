class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int i=0,j=0;
        int curr=0;
        while(j<s.size()){
            curr*=2;
            if(s[j]=='1')curr+=1;
            if(j-i+1==k){
                st.insert(curr);
                if(st.size()==1<<k)return true;
                if(s[i]=='1')curr-=(1<<(k-1));
                ++i;
            }
            ++j;
        }
        return false;
    }
};