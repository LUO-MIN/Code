class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //先将数据都插入到不为空的队列里，保证数据都插入到同一个队列里
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
			//除了q2中的最后一个元素，其他的都push到q1中
            for(int i=0;i<len-1;i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
			//将q2的最后一个元素pop()
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
            q1.push(q2.front());//目的:为了将所有元素都放到同一队列里
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
