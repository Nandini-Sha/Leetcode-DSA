class MinStack {
private:
    long min;
    stack<long> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min = val;
        }
        else{
            st.push(val-min);
            if(val<min) min = val; 
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long pop = st.top();
        st.pop();

        if(pop<0) min = min - pop;
    }
    
    int top() {
        long top = st.top();
        return (top>0)?(min+top):(int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */