// C++ program to implement LRU Least Recently Used) using
//Built-in Doubly linked list
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
  public:
    int capacity;
    list<pair<int, int>> List;

    // Map from key to list iterator
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    // Constructor to initialize the 
      //cache with a given capacity
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Function to get the value for a given key
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        }

        // Move the accessed node to the 
          //front (most recently used position)
        int value = it->second->second;
        List.erase(it->second);
        List.push_front({key, value});

        // Update the iterator in the map
        cacheMap[key] = List.begin();
        return value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // Remove the old node from the list and map
            List.erase(it->second);
            cacheMap.erase(it);
        }

        // Insert the new node at the front of the list
        List.push_front({key, value});
        cacheMap[key] = List.begin();

        // If the cache size exceeds the capacity,
          //remove the least recently used item
        if (cacheMap.size() > capacity) {
            auto lastNode = List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};

int main() {
  
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}