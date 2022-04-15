#pragma once
#include <stack>

class CQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    CQueue() {
        ClearStack(stack1);
        ClearStack(stack2);
    }

    void ClearStack(std::stack<int>& m_Stack)
    {
        while (!m_Stack.empty())
        {
            m_Stack.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if (stack1.empty() && stack2.empty())
        {
            return -1;
        }

		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
        
        int temp = stack2.top();
        stack2.pop();

        return temp;
    }
};