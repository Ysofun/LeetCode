#pragma once
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<queue<char>> wordStack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && (i - 1 < 0 || s[i - 1] == ' '))
            {
                queue<char> m_Word;
                while (i < s.length() && s[i] != ' ')
                {
                    m_Word.push(s[i]);
                    i++;
                }
                wordStack.push(m_Word);
                while (!m_Word.empty()) m_Word.pop();
            }
        }
        string sNew;
        while (!wordStack.empty())
        {
            while (!wordStack.top().empty())
            {
                sNew += wordStack.top().front();
                wordStack.top().pop();
            }
            if (wordStack.size() > 1) sNew += ' ';
            wordStack.pop();
        }
        return sNew;
    }
};