class CustomStack {
public:
stack<int> st;
int ms;
int cs;
    CustomStack(int maxSize) {
        ms=maxSize;
        cs=0;
    }
    
    void push(int x) {
        if(cs<ms) {st.push(x);cs++;}
        
    }
    
    int pop() {
        if(st.empty()) return -1;
        cs--;
        int k = st.top();
        st.pop();
        return k;
    }
    
    void increment(int k, int val) {
        int mini =min(k , cs);
        stack<int> ss;
        while(!st.empty()){
            ss.push(st.top());
            st.pop();
        }
        
        while(mini--&&!ss.empty()) {
            st.push(ss.top()+val);
            ss.pop();
        }
        while(!ss.empty()){
            st.push(ss.top());
            ss.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */