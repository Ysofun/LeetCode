#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* m_NodeHead = new Node(head->val);
        Node* m_Node = m_NodeHead;
        Node* currentHead = head;

        currentHead = currentHead->next;
        while (currentHead != nullptr)
        {
            m_Node->next = new Node(currentHead->val);
            m_Node = m_Node->next;
            currentHead = currentHead->next;
        }

        m_Node = m_NodeHead;
        currentHead = head;
        while (currentHead != nullptr)
        {
            if (currentHead->random == nullptr)
            {
                m_Node = m_Node->next;
                currentHead = currentHead->next;
                continue;
            }

            int nodeCnt = 0;
            Node* currentHead2 = head;
            while (currentHead2 != currentHead->random)
            {
                nodeCnt++;
                currentHead2 = currentHead2->next;
            }

            Node* m_Node2 = m_NodeHead;
            while (nodeCnt > 0)
            {
                nodeCnt--;
                m_Node2 = m_Node2->next;
            }
            m_Node->random = m_Node2;
            m_Node = m_Node->next;
            currentHead = currentHead->next;
        }

        return m_NodeHead;
    }
};