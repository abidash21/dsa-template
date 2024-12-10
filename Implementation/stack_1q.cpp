    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n=q.size();
        q.push(x);
        for (int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res=q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }