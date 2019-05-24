class LRUCache 
{
public:
    LRUCache(int capacity) 
    {
        cap = capacity;
    }
    
    int get(int key) 
    {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) 
    {
        auto it = mp.find(key);
        if (it != mp.end()) l.erase(it->second);
        if (l.size() == cap)
        {
            int k = l.rbegin()->first;
            l.pop_back();
            mp.erase(k);
        }
        l.emplace_front(key, value);
        mp[key] = l.begin();
    }

private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */