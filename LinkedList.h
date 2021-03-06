
#ifndef DIESEL_LINKEDLIST_H
#define DIESEL_LINKEDLIST_H
#include <algorithm>
#include <cstdbool>

template <class T>
class ListNode{
public:
    T* data;
    ListNode* next;
    ListNode* prev;
    explicit ListNode(T* data):data(data),next(nullptr),prev(nullptr){}
    ListNode() = default;
    ~ListNode(){
        delete data;
    }
};

template <class T>
class LinkedList{
private:
    int num_of_nodes;
    ListNode<T>* first;

public:
    //c'tor
    LinkedList(): num_of_nodes(0),first(nullptr){}
    //d'tor
    ~LinkedList(){
       while (first != nullptr){
           ListNode<T>* temp = first;
           first = first->next;
           delete temp;
       }
    }
    //getFirst
    ListNode<T>* getFirstNode(){
        return first;
    }
    //getNext
    ListNode<T>* getNextNode(ListNode<T>* node){
        return node->next;
    }
    //getPrev
    ListNode<T>* getPrevNode(ListNode<T>* node){
        return node->prev;
    }

    //insert first
    ListNode<T>* InsertFirst(T* data){
        auto node = new ListNode<T>(data);
        if (isEmpty()){
            first = node;
            node->prev = nullptr;
            node->next = nullptr;
        }
        else{  // there are already some nodes in the linked list
            node->prev = nullptr;
            node->next = first;
            first->prev = node;
            first = node;
        }
        num_of_nodes++;
        return node;
    }

    //removeNode
    void removeNode (ListNode<T>* node){
        if (node == first){ //delete first node
            if (!node->next){ //if it is the only node in the list
                delete node;
                first = nullptr;
            }
            else{
                node->next->prev = nullptr;
                first = node->next;
                delete node;
            }
            num_of_nodes--
            return;
        }
        else if (node->next == nullptr){ //delete last node
            node->prev->next = nullptr;
            delete node;
            num_of_nodes--;
            return;
        }
        else { // delete middle node
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
            num_of_nodes--;
        }
    }
   //IsEmpty
   bool isEmpty(){
       return (!first);
    }

    ListNode<T>* FindNode (T* data){
        ListNode<T>* search_node = getFirstNode();
        while (search_node->next != nullptr){
            if (search_node->data == data){
                return search_node;
            }
            else{
                search_node = search_node->next;
            }
        }
        return nullptr;
    }
};
#endif //DIESEL_LINKEDLIST_H
