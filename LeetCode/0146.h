#pragma once

struct DLinkedNode
{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    DLinkedNode* head;
    DLinkedNode* tail;
    int size, capacity;
    unordered_map<int, DLinkedNode*> cache;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) { return -1; }
        RemoveNode(cache[key]);
        InsertNode(head, cache[key]);
        return cache[key]->value;
    }

    void put(int key, int value) {
        if (!cache.count(key))
        {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;

            InsertNode(head, node);
            size++;
            if (size > capacity)
            {
                DLinkedNode* removed = tail->prev;
                cache.erase(removed->key);
                removed->prev->next = tail;
                tail->prev = removed->prev;
                delete removed;
                size--;
            }
        }
        else
        {
            cache[key]->value = value;
            RemoveNode(cache[key]);
            InsertNode(head, cache[key]);
        }
    }

    void RemoveNode(DLinkedNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void InsertNode(DLinkedNode* inserted, DLinkedNode* node)
    {
        node->next = inserted->next;
        inserted->next->prev = node;
        inserted->next = node;
        node->prev = inserted;
    }
};