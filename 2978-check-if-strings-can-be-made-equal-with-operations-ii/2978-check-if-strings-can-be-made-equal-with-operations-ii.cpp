class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26,0);
        vector<int> odd(26,0);
        for(int i=0;i<s1.size();++i){
            if(i&1){
                ++odd[s1[i]-97];
                --odd[s2[i]-97];
            }
            else{
                ++even[s1[i]-97];
                --even[s2[i]-97];
            }
        }
        for(int i=0;i<26;++i){
            if(odd[i]!=0||even[i]!=0)return false;
        }
        return true;
    }
};