class MinStack {
public:
    stack<int> st;
	stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
		val = min(minstack.empty() ? val : minstack.top(), val);
		minstack.push(val);
    }
    
    void pop() {
        st.pop();
		minstack.pop();
    }
    
    int top() {
       return st.top(); 
    }
    
    int getMin() {
        return minstack.top();
    }
};
