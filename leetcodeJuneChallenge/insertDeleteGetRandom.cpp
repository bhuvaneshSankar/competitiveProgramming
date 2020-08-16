#include <bits/stdc++.h>
#include <vector>
#include <map>

class RandomizedSet
{
    unordered_map<int, int> mp;
    vector<int> v;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        else
        {
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (mp.find(val) == mp.end())
        {
            return false;
        }
        else
        {
            //copy the last element in the vector to the index of the target element to be deleted(val)
            //now we can delete the last element from the vector as we have moved it to index(val)
            //update the index of the last element in the map to the index(val)
            auto it = mp.find(val);
            int pos = it->second;
            v[pos] = v.back();
            v.pop_back();
            mp[v[pos]] = it->second;
            mp.erase(val);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int r = rand();
        return v[r % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */