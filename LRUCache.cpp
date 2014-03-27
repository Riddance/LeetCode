class LRUCache{
public:
    typedef std::list< pair<int, int> > CACHE_LIST;
    CACHE_LIST cache_list;

    typedef std::unordered_map<int, decltype(cache_list.end())> CACHE_MAP;
    CACHE_MAP cache_map;

    size_t cache_size;

    LRUCache(int capacity) {
        cache_size = capacity;
    }
    
    int get(int key) {
        auto got = cache_map.find(key);
        if (got == cache_map.end())
            return -1;

        cache_list.splice(cache_list.begin(), cache_list, got->second);
        
        return got->second->second;
    }
    
    void set(int key, int value) {
        auto got = cache_map.find(key);
        if (got != cache_map.end()) {
            cache_list.erase(got->second);
            cache_map.erase(got);
        }

        cache_list.push_front(make_pair(key, value));
        cache_map.insert(make_pair(key, cache_list.begin()));
        clean();
    }

    void clean() {
        while (cache_map.size() > cache_size) {
            auto mv_node = cache_list.end();
            --mv_node;
            cache_map.erase(mv_node->first);
            cache_list.pop_back();
        }
    }
};