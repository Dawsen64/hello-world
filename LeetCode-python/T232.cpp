class MyQueue {
public:
    stack<int> stackin;
    stack<int> stackout;

    MyQueue() {
        ;
    }
    
    void push(int x) {
        stackin.push(x);
    }
    
    int pop() {
        if (stackout.empty()){
            while(!stackin.empty()){
            stackout.push(stackin.top());
            stackin.pop();
            }
        }
        auto res =  stackout.top();
        stackout.pop();
        return res;
    }
    
    int peek() {
        auto tmp = this->pop();
        stackout.push(tmp);
        return tmp;
    }
    
    bool empty() {
        return stackin.empty() && stackout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
