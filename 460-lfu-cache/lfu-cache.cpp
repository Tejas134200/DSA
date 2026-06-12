class LFUCache {
public:

    class FreqNode;

    class KeyNode{
    public:
        int key,val;
        KeyNode *prev,*next;
        FreqNode *freqNode;
    };

    class FreqNode{
    public:
        int freq;
        FreqNode *prev,*next;

        KeyNode *head,*tail;
    };

    int cap,size;

    unordered_map<int,KeyNode*> keyStore;

    FreqNode *head,*tail;

    FreqNode* getFreqNode(int freq){
        FreqNode* node = new FreqNode();

        node->freq = freq;
        node->prev = node->next = NULL;

        node->head = new KeyNode();
        node->tail = new KeyNode();

        node->head->next = node->tail;
        node->tail->prev = node->head;

        return node;
    }

    KeyNode* getKeyNode(int key,int val){
        KeyNode* node = new KeyNode();

        node->key = key;
        node->val = val;
        node->prev = node->next = NULL;
        node->freqNode = NULL;

        return node;
    }

    void removeFreq(FreqNode* cur){
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur->head;
        delete cur->tail;
        delete cur;
    }

    void removeKey(KeyNode* cur){
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void addFreqRight(FreqNode* cur,int freq){
        FreqNode* node = getFreqNode(freq);

        node->next = cur->next;
        node->prev = cur;

        cur->next->prev = node;
        cur->next = node;
    }

    void addKeyRight(FreqNode* freqNode,KeyNode* keyNode){

        keyNode->next = freqNode->tail;
        keyNode->prev = freqNode->tail->prev;

        freqNode->tail->prev->next = keyNode;
        freqNode->tail->prev = keyNode;
    }

    void increase(KeyNode* cur){

        FreqNode* f = cur->freqNode;

        removeKey(cur);

        FreqNode* nxt;

        if(f->next != tail &&
           f->next->freq == f->freq + 1){

            nxt = f->next;
        }
        else{
            addFreqRight(f,f->freq+1);
            nxt = f->next;
        }

        addKeyRight(nxt,cur);
        cur->freqNode = nxt;

        if(f->head->next == f->tail)
            removeFreq(f);
    }

    LFUCache(int capacity) {

        cap = capacity;
        size = 0;

        head = getFreqNode(-1);
        tail = getFreqNode(-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(!keyStore.count(key))
            return -1;

        KeyNode* cur = keyStore[key];

        increase(cur);

        return cur->val;
    }

    void put(int key, int value) {

        if(cap==0) return;

        if(keyStore.count(key)){

            KeyNode* cur = keyStore[key];

            cur->val = value;

            increase(cur);

            return;
        }

        if(size == cap){

            FreqNode* mnFreq = head->next;

            KeyNode* victim = mnFreq->head->next;

            keyStore.erase(victim->key);

            removeKey(victim);

            delete victim;

            if(mnFreq->head->next == mnFreq->tail)
                removeFreq(mnFreq);

            size--;
        }

        FreqNode* oneFreq;

        if(head->next != tail &&
           head->next->freq == 1){

            oneFreq = head->next;
        }
        else{
            addFreqRight(head,1);
            oneFreq = head->next;
        }

        KeyNode* newKey = getKeyNode(key,value);

        addKeyRight(oneFreq,newKey);

        newKey->freqNode = oneFreq;

        keyStore[key] = newKey;

        size++;
    }
};
