#include <iomanip>
#include <iomanip>
#include <vector>
#include <deque>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
    }
    bool search(int val) {
        if(R_Set.find(val)==R_Set.end()) {
            return false;
        }
        return true;

    }
    bool insert(int val) {
        if(search(val)) {
            return false;
        }
        else {
            R_Vec.push_back(val);
            R_Set[val]=(int)R_Vec.size()-1;
            return true;
        }
    }

    bool remove(int val) {
        if(!search(val)) {
            return false;
        }
        else {
            int tmp=R_Vec[R_Vec.size()-1];
            R_Vec[R_Vec.size()-1]=R_Vec[R_Set[val]];
            R_Vec[R_Set[val]]=tmp;
            int pos=R_Set[val];
            R_Vec.pop_back();
            R_Set.erase(val);
            if(val!=tmp) {
                R_Set[tmp]=pos;
            }
            return true;
        }
    }

    int getRandom() {
        int random=rand()%R_Vec.size();
        return R_Vec[random];
    }
private:
    vector<int>R_Vec;
    unordered_map<int,int> R_Set;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(void) {
    RandomizedSet randomizedSet;
    assert(randomizedSet.insert(1)==true); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    assert(randomizedSet.remove(2)==false); // Returns false as 2 does not exist in the set.
    assert(randomizedSet.insert(2)==true); // Inserts 2 to the set, returns true. Set now contains [1,2].
   // assert(randomizedSet.getRandom()==1 || randomizedSet.getRandom()==2); // getRandom() should return either 1 or 2 randomly.
    assert(randomizedSet.remove(1)==true); // Removes 1 from the set, returns true. Set now contains [2].
    assert(randomizedSet.insert(2)==false); // 2 was already in the set, so return false.
    assert(randomizedSet.getRandom()==2); // Since 2 is the only number in the set, getRandom() will always return 2.



    return EXIT_SUCCESS;
}