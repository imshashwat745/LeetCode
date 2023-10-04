class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        if(arr.size()<=2)return arr[0];
        int slow=arr[0],fast=arr[arr[0]];
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[arr[fast]];
        }
        slow=0;
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }
        return slow;
    }
};