class Node{
public:
    Node* next;
    int key;
    int value;
    Node(int k,int v){
        key=k;
        value=v;
        next=NULL;
    }
};
class MyHashMap {
private:
    vector<Node*> mp;
    int MOD=769;
public:
    MyHashMap() {
        mp=vector<Node*>(MOD,NULL);
    }
    
    void put(int key, int value) {
        int hash=key%MOD;
        if(mp[hash]==NULL){
            mp[hash]=new Node(key,value);
            return;
        }
        Node* temp=mp[hash];
        while(temp&&temp->next){
            if(temp->key==key){
                temp->value=value;
                return;
            }
            temp=temp->next;
        }
        if(temp->key==key){
            temp->value=value;
            return;
        }
        temp->next=new Node(key,value);
    }
    
    int get(int key) {
        int hash=key%MOD;
        Node* temp=mp[hash];
        while(temp){
            if(temp->key==key){
                return temp->value;
            }
            temp=temp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash=key%MOD;
        if(mp[hash]==NULL){
            return;
        }
        Node* temp=mp[hash];
        Node* prev=NULL;
        while(temp){
            if(temp->key==key){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(temp&&temp->key==key){
            if(prev==NULL)mp[hash]=temp->next;
            else prev->next=temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */