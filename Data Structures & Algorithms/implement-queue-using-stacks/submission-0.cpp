class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        int element = peek();
        popStack.pop();
        return element;
    }
    
    int peek() {
        if(popStack.empty()){
            transfer();
        }
        if(popStack.empty()){
            return -1; // error signal
        }

        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
private:
    stack<int> pushStack;
    stack<int> popStack;

    void transfer(){
        while(!pushStack.empty()){
            int element = pushStack.top();
            popStack.push(element);
            pushStack.pop();
        }
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