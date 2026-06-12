class AllOne {
public:

    class Node{
        public:
        unordered_set<string> con;
        Node *next , *prev;
        int freq;
    };

    Node *tail , *head;
    unordered_map<string , Node*> keyStore;

    Node* getNewNode(string key , int freq){
        Node* newnode = new Node();
        newnode->con.insert(key);
        newnode->freq=freq;
        newnode->next=newnode->prev=NULL;
        return newnode;
    }

    void removeNode(Node* cur){
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        cur->next=cur->prev=NULL;
        delete cur;
        return;
    }
    void add_right(Node* cur , string s , int freq){
        Node* newnode = getNewNode(s , freq);
        newnode->next=cur->next;
        cur->next->prev=newnode;
        cur->next=newnode;
        newnode->prev=cur;

    }


    
    AllOne() {
        head = getNewNode("",-10);
        tail = getNewNode("" ,-10);
        head->next=tail;
        tail->prev=head;
    }
    
    void inc(string key) {
        if(keyStore.count(key)){
            Node* cur = keyStore[key];
            cur->con.erase(key);

            if(cur->next->freq==cur->freq+1){
                cur->next->con.insert(key);
            }else{
                add_right(cur , key , cur->freq+1);
            }

            keyStore[key]=cur->next;
            if(cur->con.empty()) removeNode(cur);
        }
        else{
            if (head->next->freq == 1) {
                head->next->con.insert(key);
            } else {
                add_right(head, key, 1);
            }
            keyStore[key] = head->next;
        }
    }
    
    void dec(string key) {
        Node* cur = keyStore[key];
        cur->con.erase(key);
        if(cur->freq==1){
            keyStore.erase(key);
        }else{
            if(cur->prev->freq==cur->freq-1){
                cur->prev->con.insert(key);
            
            }
            else add_right(cur->prev , key , cur->freq-1);
            keyStore[key] = cur->prev;
        }
        if(cur->con.empty()) removeNode(cur);

    }
    
    string getMaxKey() {
        if(tail->prev==head) return "";
        return *(tail->prev->con.begin());
    }
    
    string getMinKey() {
        if(head->next==tail) return "";
        return *(head->next->con.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */