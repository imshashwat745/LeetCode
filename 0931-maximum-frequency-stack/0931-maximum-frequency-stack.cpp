class FreqStack {
private:
    unordered_map<int,int> mp;
    priority_queue<vector<int>> pq;
    int timestamp;
public:
    FreqStack() {
        timestamp=0;
    }
    
    void push(int val) {
        ++mp[val];
        pq.push({mp[val],timestamp,val});
        ++timestamp;
    }
    
    int pop() {
        if(pq.empty())return -1;
        int val=pq.top()[2];
        --mp[val];
        pq.pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */