class Solution {
private:
    string add(string &s1,string &s2){
        int i=s1.size()-1,j=s2.size()-1,carry=0;
        string ans="";
        while(i>-1&&j>-1){
            int a=s1[i]-48;
            int b=s2[j]-48;
            int s=a+b+carry;
            carry=s/10;
            s%=10;
            ans+=(char)(s+48);
            --i;
            --j;
        }
        while(j>-1){
            int s=s2[j]-48;
            s+=carry;
            carry=s/10;
            s%=10;
            ans+=(char)(s+48);
            --j;
        }
        while(i>-1){
            int s=s1[i]-48;
            s+=carry;
            carry=s/10;
            s%=10;
            ans+=(char)(s+48);
            --i;
        }
        if(carry==1)ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool help(string &s,string a,string b,int idx){
        if(idx>=s.size())return true;
        string res=add(a,b);
        int res_len=res.size();
        string actual=s.substr(idx,res_len);
        bool ans=false;
        if(actual==res)return help(s,b,res,idx+res_len);
        return false;
    }
public:
    bool isAdditiveNumber(string s) {
        if(s.size()==0)return true;
        int i,j;
        string a="";
        int limit1=s.size()-1;
        if(s[0]=='0')limit1=0;;
        for(i=0;i<=limit1;++i){
            a+=s[i];
            string b="";
            int limit2=s.size()-1;
            if(i+1<s.size()&&s[i+1]=='0')limit2=i+1;
            for(j=i+1;j<=limit2;++j){
                b+=s[j];
                if(j==s.size()-1)continue;
                if(help(s,a,b,j+1))return true;
            }
        }
        return false;
    }
};