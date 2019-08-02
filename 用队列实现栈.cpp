class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        if(q1.empty())
        {
            q2.push(x);
        }
        else{
            q1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())
        {
            int len = q2.size();
            for(int i=0;i<len-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int a=q2.front();
            q2.pop();
            return a;
        }
        else{
            int len=q1.size();
            for(int i=0;i<len-1;++i)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int a=q1.front();
            q1.pop();
            return a;    
        }
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())
        {
            int len=q2.size();
            for(int i=0;i<len-1;++i)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int a=q2.front();
            q1.push(q2.front());
            q2.pop();
            return a;
        }
        else{
            int len = q1.size();
            for(int i=0;i<len-1;++i)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int a=q1.front();
            q2.push(q1.front());
            q1.pop();
            return a;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() &&q2.empty();
    }
};
