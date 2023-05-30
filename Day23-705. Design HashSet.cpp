#include<bits/stdc++.h>
using namespace std;

//problem link 

//https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    static const  int N = 1e6 + 7;
    bool a[N] = {0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        a[key] = true;
    }
    
    void remove(int key) {
        a[key] = false;
    }
    
    bool contains(int key) {
        return a[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */