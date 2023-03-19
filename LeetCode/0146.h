class LRUCache {
private:
	struct DLinkedNode
	{
		int key, value;
		DLinkedNode* prev;
		DLinkedNode* next;
		DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
		DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}

		void remove()
		{
			prev->next = next;
			next->prev = prev;
			next = nullptr;
			prev = nullptr;
		}

		void insert(DLinkedNode* node)
		{
			next = node->next;
			node->next->prev = this;
			prev = node;
			node->next = this;
		}
	};

	int size, capacity;
	DLinkedNode* head;
	DLinkedNode* tail;
	unordered_map<int, DLinkedNode*> cache;

public:
	LRUCache(int _capacity) : size(0), capacity(_capacity) {
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (!cache.count(key)) { return -1; }
		cache[key]->remove();
		cache[key]->insert(head);
		return cache[key]->value;
	}

	void put(int key, int value) {
		if (cache.count(key)) 
		{ 
			cache[key]->value = value;
			cache[key]->remove();
		}
		else
		{
			if (++size > capacity)
			{
				DLinkedNode* removed = tail->prev;
				cache.erase(removed->key);
				removed->remove();
				size--;
			}
			cache[key] = new DLinkedNode(key, value);
		}
		cache[key]->insert(head);
	}
};