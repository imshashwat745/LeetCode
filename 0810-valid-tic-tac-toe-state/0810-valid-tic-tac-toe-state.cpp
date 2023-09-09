class Solution {
private:
    bool win(vector<string> &arr,char ch){
        if(arr[0][0]==ch&&arr[1][1]==ch&&arr[2][2]==ch)return true;
        if(arr[0][2]==ch&&arr[1][1]==ch&&arr[2][0]==ch)return true;
        for(int i=0;i<3;++i){
            if(arr[i][0]==ch&&arr[i][1]==ch&&arr[i][2]==ch)return true;
            if(arr[0][i]==ch&&arr[1][i]==ch&&arr[2][i]==ch)return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& arr) {
        int X=0,O=0;
        for(int i=0;i<arr.size();++i){
            for(auto ch:arr[i]){
                if(ch=='X')++X;
                else if(ch=='O')++O;
            }
        }
        int diff=X-O;
        if(diff!=0&&diff!=1)return false;
        if(win(arr,'O')&&diff!=0)return false;
        if(win(arr,'X')&&diff!=1)return false;
        if(win(arr,'O')&&win(arr,'X'))return false;
        return true;
    }
};