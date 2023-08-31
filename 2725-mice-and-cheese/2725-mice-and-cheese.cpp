struct sks{
    int r1,r2;
};
class Solution {
private:
    static bool cmp(sks a,sks b){
        return (a.r1-a.r2)>(b.r1-b.r2);
    }
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size(),i;
        sks arr[n];
        for(i=0;i<n;++i){
            arr[i].r1=reward1[i];
            arr[i].r2=reward2[i];
        }
        sort(arr,arr+n,cmp);
        int ans=0;
        for(int i=0;i<n;++i){
           if(i<k)ans+=arr[i].r1;
           else ans+=arr[i].r2;
        }
        return ans;
    }
};