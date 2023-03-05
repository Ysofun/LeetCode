class LRUCache {
public:
	struct DlinkedNode
	{
		int key, val;
		DlinkedNode* prev;
		DlinkedNode* next;
		DlinkedNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
		void RemoveNode()
		{
			prev->next = next;
			next->prev = prev;
		}
		void InsertNode(DlinkedNode* node)
		{
			next = node->next;
			prev = node;
			node->next->prev = this;
			node->next = this;
		}
	};

	int capacity, size;
	DlinkedNode* head;
	DlinkedNode* tail;
	unordered_map<int, DlinkedNode*> cache;

	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		head = new DlinkedNode(0, 0);
		tail = new DlinkedNode(0, 0);
		head->next = tail;
		tail->prev = head;
	}

	void MoveToHead(DlinkedNode* node)
	{
		node->RemoveNode();
		node->InsertNode(head);
	}

	int get(int key) {
		if (!cache.count(key)) { return -1; }
		MoveToHead(cache[key]);
		return cache[key]->val;
	}

	void put(int key, int value) {
		if (cache.count(key))
		{
			cache[key]->val = value;
			MoveToHead(cache[key]);
			return;
		}

		size++;
		DlinkedNode* temp = new DlinkedNode(key, value);
		if (size > capacity)
		{
			cache.erase(tail->prev->key);
			tail->prev->RemoveNode();
			size--;
		}
		temp->InsertNode(head);
		cache[key] = temp;
	}
};