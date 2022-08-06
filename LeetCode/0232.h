#pragma once



class MyQueue {

private:

	stack<int> s1;
	stack<int> s2;

public:

	MyQueue() {
		while (!s1.empty()) s1.pop();
		while (!s2.empty()) s2.pop();
	}

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		int res = peek();
		s2.pop();
		return res;
	}

	int peek() {
		
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		return s2.top();
	}

	bool empty() {
		return s1.empty() && s2.empty();
	}
};
