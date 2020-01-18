#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator> > hashMap;
    list<int> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!hashMap.count(key)) {
            return -1;
        }
        cache.erase(hashMap[key].second);
        cache.push_front(key);
        hashMap[key].second = cache.begin();
        return hashMap[key].first;
    }
    
    void put(int key, int value) {
        if (hashMap.count(key)) {
            cache.erase(hashMap[key].second);
            cache.push_front(key);
            hashMap[key].first = value;
            hashMap[key].second = cache.begin();
        } else {
            if (hashMap.size() < capacity) {
                cache.push_front(key);
                hashMap[key] = {value, cache.begin()};
            } else {
                hashMap.erase(cache.back());
                cache.pop_back();
                cache.push_front(key);
                hashMap[key] = {value, cache.begin()};
            }
        }
    }
};

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;       // returns 1
    cache->put(3, 3);    // evicts key 2
    cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    cout << cache->get(1) << endl;       // returns -1 (not found)
    cout << cache->get(3) << endl;       // returns 3
    cout << cache->get(4) << endl;       // returns 4
    return 0;
}
