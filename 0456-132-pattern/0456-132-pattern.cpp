class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        if(arr.size()<3)return false;
        int mini=arr[0],j=1,k=2;
        map<int,int> mp;
        for(k=k;k<arr.size();++k)++mp[arr[k]];
        while(j<arr.size()){
            if(j>1){
                --mp[arr[j]];
                if(mp[arr[j]]<=0)mp.erase(arr[j]);
            }
            if(mini>arr[j]){
                mini=arr[j];
                ++j;
                continue;
            }
            auto it=mp.upper_bound(mini);
            if(it!=mp.end()){
                int ele=it->first;
                cout<<mini<<" "<<arr[j]<<" "<<ele<<endl;
                if(ele>mini&&ele<arr[j])return true;
            }
            

            mini=min(mini,arr[j]);
            ++j;
        }
        return false;
    }
};