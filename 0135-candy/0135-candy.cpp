class Solution {
public:
    int candy(vector<int>& arr) {
        int i=1,j,n=arr.size(),ans=1,curr=1;
        while(i<n){
            // cout<<i<<" "<<ans<<" "<<curr<<endl;
            j=i;
            bool flag=false;
            //same value
            while(j<n&&arr[j]==arr[j-1]){
                ans+=1;
                ++j;
                flag=true;
            }
            if(flag){
                i=j;
                curr=1;
                continue;
            }
            //increasing
            while(j<n&&arr[j]>arr[j-1]){
                ++curr;
                ans+=curr;
                ++j;
                flag=true;
            }
            if(flag){
                i=j;
                // curr=1;
                continue;
            }
            //decreasing
            int sz=1;
            while(j<n&&arr[j]<arr[j-1]){
                --curr;
                ans+=curr;
                ++sz;
                ++j;
                flag=true;
            }
            if(curr<=0){
                // cout<<i<<" "<<j<<" "<<sz<<endl;
                curr=abs(curr)+1;
                ans+=curr*sz;
            }
            else if(curr>1){
                // cout<<ans<<endl;
                ans-=(sz-1)*(curr-1);
            }
            i=j;
            curr=1;
        }
        return ans;
    }
};