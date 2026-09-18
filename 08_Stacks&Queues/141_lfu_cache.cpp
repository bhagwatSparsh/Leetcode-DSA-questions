#include <unordered_map>
#include <map>
#include <list>
#include <vector>

using namespace std;

class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int, list<vector<int>>::iterator> mpp; // key-<address(har ek node ka, list of vect of int type ka)
    map<int, list<vector<int>>> freq; // counter ke corrspn-> { key, val, counter}
    LFUCache(int capacity) {
        cap=capacity;
        size=0;
        
    }
    
    void makeMostFrequentlyUsed(int key){
        auto &vec =*(mpp[key]);
        int value=vec[1];
        int f= vec[2];
        freq[f].erase(mpp[key]); // delete node frequency

        if (freq[f].empty()){
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key, value, f});
        mpp[key]=freq[f].begin();
    }
    int get(int key) {
        if (mpp.find(key)==mpp.end()){
            return -1;
        }

        auto vec=(*(mpp[key])); // dir get the node {key, val, counter}
        int value=vec[1];

        

        makeMostFrequentlyUsed(key);

        return value;
    }
    
    void put(int key, int value) {
        if (cap==0){
            return;
        }
        if (mpp.find(key)!=mpp.end()){
            auto &vec=(*(mpp[key]));
            vec[1]=value;

            makeMostFrequentlyUsed(key);
        }
        else if (size<cap){
            size++;
            // fresh banda:

            freq[1].push_front(vector<int>({key, value, 1}));
            mpp[key]=freq[1].begin();

        }
        else{
            // time to remove lfu or lru when there is a tie:

            auto &kaun_sa_list=freq.begin()->second; // least counter wala

            int key_to_del=(kaun_sa_list.back())[0];
            kaun_sa_list.pop_back();

            if (kaun_sa_list.empty()){
                freq.erase(freq.begin()->first); // map.erase(key)
            }

            freq[1].push_front(vector<int>({key, value, 1}));
            mpp.erase(key_to_del);
            mpp[key]=freq[1].begin();
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 