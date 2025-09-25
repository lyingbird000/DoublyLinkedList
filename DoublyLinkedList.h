#include<iostream>
using namespace std;
 
template <typename T>
class Node{
public:
    T data;
    Node* pre;
    Node* next;
    Node(T value):data(value),pre(nullptr),next(nullptr){}
};
template <typename T>
class DLL{
    Node<T>* head;
    Node<T>* tail;
    int len;
public:
    DLL() : head(nullptr) , tail(nullptr) , len(0){}
    ~DLL(){ 
         clear();
    }
    //Add a new node to the tail.
    void push_tail(T data){
        Node<T>* newNode = new Node<T>(data);
	if(len == 0) {head = tail = newNode;}
	else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
        len++;
    }
     //Add a new node to the head.
     void push_head(T data){
         Node<T>* newNode = new Node<T>(data);
         if(len == 0){head = tail = newNode;}
         else {
             head->pre = newNode;
             newNode->next = head;
             head = newNode;
         }
         len++;  
     }
     //Delete and get the data of the tail node.
     T pop_tail(){
         if(len == 0) {
             cout<<"ERROR:空链表";
             return 0;
         }else {
             T res = tail->data;
             Node<T>* p = tail;
             tail->pre->next = nullptr;
             tail = tail->pre;
             delete p;
             len--;
             return res;
         } 

     }
     //Delete and get the data of the head node.
     T pop_head(){
         if(len == 0) {
             cout<<"ERROR:empty linked list";
             return 0;
         }else{
             T res = head->data;
             Node<T>* p = head;
             if(len == 1){head = tail = nullptr;}
             else {
             head->pre->next = nullptr;
             head = head->next;
             delete p;
             len--;
             return res;
             }
         }
     }
     //Print the linked list. Input 1 to represent forward and 0 to represent reverse.
     void print_list(int dire){
         Node<T>* cur = nullptr;
         if(dire){
             cur = head;
             while(cur != nullptr){
                 cout<<cur->data<<" ";
                 cur = cur->next;
             }
         }
         else{
             cur = tail;
             while(cur != nullptr){
                 cout<<cur->data<<" ";
                 cur = cur->pre;
             }
         }
         cout<<endl;

     }
     //get the length of the linked list
     int get_len(){
          return len;
     }
     //clear the linked list
     void clear(){
        
         if(len == 0) return;  // Add an check of empty linked list.
         Node<T>* cur = head;
         while(cur != nullptr){
             Node<T>* next = cur->next;
             delete cur;
             cur = next;
         }
         head = tail = nullptr;
         len = 0;
     }

};
