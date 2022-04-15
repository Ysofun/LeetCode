#pragma once
#include <stack>

class MinStack {
private:
    std::stack<int> m_Stack;
    std::stack<int> m_MinStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        m_MinStack.push(INT_MAX);
    }

    void push(int x) {
        m_Stack.push(x);
        m_MinStack.push(std::min(m_MinStack.top(), x));
    }

    void pop() {
        m_Stack.pop();
        m_MinStack.pop();
    }

    int top() {
        return m_Stack.top();
    }

    int min() {
        return m_MinStack.top();
    }
};
