class Solution {
private:
    string help(string a,string b,string c){
        int i=0,j=0;
        string ans=a;
        if(ans.find(b)==string::npos){
            bool found=false;
            for(i=b.size()-2;i>-1;--i){
                int start=ans.size()-1-i;
                if(start<0)continue;
                j=0;
                for(start=start;start<ans.size();++start){
                    if(ans[start]!=b[j++])break;
                }
                if(start==ans.size()){
                    ans+=b.substr(i+1,b.size());
                    found=true;
                    break;
                }
            }
            if(!found)ans+=b;
        }
        if(ans.find(c)==string::npos){
            bool found=false;
            for(i=c.size()-2;i>-1;--i){
                if(i==0)cout<<ans<<"--------------\n";
                int start=ans.size()-1-i;
                if(start<0)continue;
                j=0;
                for(start=start;start<ans.size();++start){
                    // cout<<"----"<<endl;
                    if(ans[start]!=c[j++])break;
                }
                if(start==ans.size()){
                    ans+=c.substr(i+1,c.size());
                    found=true;
                    break;
                }
            }
            if(!found)ans+=c;
        }
        return ans;
    }
public:
    string minimumString(string a, string b, string c) {
        string ans="";
        string curr=help(a,b,c);
        cout<<curr<<endl;
        ans=curr;
        curr=help(a,c,b);
        cout<<curr<<endl;
        if(curr.size()<ans.size()||(ans.size()==curr.size()&&curr<ans))ans=curr;
        curr=help(b,a,c);
        cout<<curr<<endl;
        if(curr.size()<ans.size()||(ans.size()==curr.size()&&curr<ans))ans=curr;
        curr=help(b,c,a);
        cout<<curr<<endl;
        if(curr.size()<ans.size()||(ans.size()==curr.size()&&curr<ans))ans=curr;
        curr=help(c,a,b);
        cout<<curr<<endl;
        if(curr.size()<ans.size()||(ans.size()==curr.size()&&curr<ans))ans=curr;
        curr=help(c,b,a);
        cout<<curr<<endl;
        if(curr.size()<ans.size()||(ans.size()==curr.size()&&curr<ans))ans=curr;
        return ans;
    }
};