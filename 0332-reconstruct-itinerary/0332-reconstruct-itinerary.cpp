class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& edges) {
        /*These are the data structures to be used,
        see tech dose video*/
        unordered_map<string,multiset<string>> adj;
        stack<string> st;

        for(auto edge:edges){
            adj[edge[0]].insert(edge[1]);
        }
        
        vector<string> ans;
        st.push("JFK");
        while(!st.empty()){
            string src=st.top();
            if(adj.find(src)==adj.end()||adj[src].size()==0){
                ans.push_back(src);
                st.pop();
            }
            else{
                auto dst=adj[src].begin();
                st.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};