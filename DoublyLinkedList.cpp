#include<iostream>
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
    DLL<int> dll;
    
    dll.push_tail(10);
    dll.push_tail(20);
    dll.push_head(5);
    
    cout<<"Forward traversal:"<<endl; 
    dll.print_list(1);
    
    cout<<"Last element is:"<<dll.pop_tail()<<endl;
    cout<<"Reverse traversal after deleting the last element:"<<endl;
    dll.print_list(0);

    cout<<"The length of linked list is:"<<dll.get_len()<<endl;
    
    return 0; 
}
