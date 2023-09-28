class Solution {
    public void swap(int arr[],int i,int j){
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
    public int[] sortArrayByParity(int[] arr) {
        int even=0,odd=0,n=arr.length;
        while(true){
            while(odd<n&&((arr[odd]&1)==0))++odd;
            while(even<n&&(even<odd||((arr[even]&1)==1)))++even;
            if(odd>=n||even>=n)break;
            else swap(arr,even,odd);
        }
        return arr;
    }
}