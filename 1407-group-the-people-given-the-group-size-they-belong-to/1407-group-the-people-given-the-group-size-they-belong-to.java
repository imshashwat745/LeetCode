class Solution {
    public List<List<Integer>> groupThePeople(int[] arr) {
        Map<Integer,List<Integer>> mp=new HashMap<>();
        for(int i=0;i<arr.length;++i){
            List<Integer> currList=mp.getOrDefault(arr[i],new ArrayList<>());
            currList.add(i);
            mp.put(arr[i],currList);
        }
        List<List<Integer>> ans=new ArrayList<>();
        for(Map.Entry<Integer,List<Integer>> entry:mp.entrySet()){
            int requiredSize=entry.getKey();
            List<Integer> val=entry.getValue();
            List<Integer> curr=new ArrayList<>();
            for(int i=0;i<val.size();++i){
                curr.add(val.get(i));
                if(curr.size()==requiredSize){
                    ans.add(curr);
                    curr=new ArrayList<>();
                }
            }
        }
        return ans;
    }
}