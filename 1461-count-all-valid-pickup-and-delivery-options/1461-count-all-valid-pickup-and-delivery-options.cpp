class Solution {
private:
    int modu = 1e9+7;
    #define ll long long
    ll help(ll n){
        if(n==1)return 1;
        return (((help(n-1)*(2*n-1))%modu)*n)%modu;
    }
public:
    int countOrders(int n) {
        return help(n);
    }
};