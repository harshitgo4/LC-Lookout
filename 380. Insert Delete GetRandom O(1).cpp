#include <cstdlib>
class RandomizedSet {
public:
    unordered_map<int,bool> mp;
    RandomizedSet() {
        mp.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
        mp[val]=true;    
        return true;
        }
        else
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end())
        {
        mp.erase(val);
        return true;
        }
        else
        return false;
    }
    
    int getRandom() {
        int n=mp.size();
        int random_number = rand() % n;
        auto itr=mp.begin();
        advance(itr, random_number);
        return itr->first;
    }
};
