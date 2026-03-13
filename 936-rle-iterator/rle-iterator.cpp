class RLEIterator {
public:
    vector<int> en;
    int i;

    RLEIterator(vector<int>& encoding) {
        en = encoding;
        i = 0;
    }
    
    int next(int n) {
        while(i < en.size()){
            if(en[i] >= n){
                en[i] -= n;
                return en[i+1];
            }else{
                n -= en[i];
                en[i] = 0;
                i += 2;
            }
        }
        return -1;
    }
};