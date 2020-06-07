
#ifndef SOUNDCLOUD_HASHTABLE_H
#define SOUNDCLOUD_HASHTABLE_H
#include "LinkedList.h"
#include <algorithm>
#include <cstdbool>

template <class T>
class HashTable{
private:
    unsigned int num_occupied;
    unsigned int size;
    LinkedList<T>** table;
    void resize();
    unsigned int hashFunc(int value){
        return value% this->size;
    }

public:
    HashTable():num_occupied(0),size(7),table(nullptr){
        table = new LinkedList<T>*[size];



    }

    ~HashTable();
    void insert(T* data);
    void remove (T* data);
    T* find(T* data);

};
#endif //SOUNDCLOUD_HASHTABLE_H
