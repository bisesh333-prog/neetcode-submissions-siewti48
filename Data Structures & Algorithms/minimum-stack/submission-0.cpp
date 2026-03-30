class MinStack {
public:
    stack<int> s,mins;
    MinStack() {
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty())mins.push(val);
        else{
            if(mins.top()>=val) mins.push(val);
        }
    }
    
    void pop() {
        if(s.top()==mins.top()){
            s.pop();
            mins.pop();
        }
        else{
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
