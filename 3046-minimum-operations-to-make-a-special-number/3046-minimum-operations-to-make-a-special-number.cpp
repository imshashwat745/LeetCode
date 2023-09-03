class Solution {
public:
    int minimumOperations(string s) {
        int i=s.size()-1,ans=s.size();
        unordered_map<int,int> mp;
        while(i>-1){
            int ch=s[i]-48;
            if(ch==5){
                if(mp.find(0)!=mp.end()){
                    int curr=(mp[0]-i-1)+(s.size()-mp[0]-1);
                    ans=min(ans,curr);
                }
                mp[ch]=i;
            }
            else if(ch==0){
                if(mp.find(0)!=mp.end()){
                    int curr=(mp[0]-i-1)+(s.size()-mp[0]-1);
                    ans=min(ans,curr);
                }
                int curr=s.size()-1;
                ans=min(ans,curr);// for case like 10
                mp[ch]=i;
            }
            else if(ch==2||ch==7){
                if(mp.find(5)!=mp.end()){
                    int curr=(mp[5]-i-1)+(s.size()-mp[5]-1);
                    ans=min(ans,curr);
                }
                mp[ch]=i;
            }
            --i;
        }
        return ans;
    }
};