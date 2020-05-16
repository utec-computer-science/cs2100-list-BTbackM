#include <iostream>
#include "data_structures.hpp"
#include "data_structures.cpp"
#include "traits_implementation.hpp"

using namespace std;
using namespace singly_linked_list;
using namespace doubly_linked_list;
using namespace circular_singly_linked_list;
using namespace circular_doubly_linked_list;
using namespace nodes;
using namespace iterators;
using namespace lists;

int main (int, char *[]){

    /*<-------------------------- singly_linked_list--------------------------->

    singly_linked_list::Sll<int> Sll_test;

    // Testing push back and push_front
    Sll_test.push_back(1);
    Sll_test.push_back(2);
    Sll_test.push_front(-1);
    Sll_test.push_back(4);
    Sll_test.push_back(5);
    Sll_test.push_front(-3);

    // Testing front and back functions
    cout << Sll_test.front()->value << endl;
    cout << Sll_test.back()->value << endl;

    // Testing get_size and empty functions
    cout << Sll_test.get_size() << endl;
    cout << Sll_test.empty() << endl;

    // Testing operator <<
    cout << Sll_test;

    // Testing pop_back
    Sll_test.pop_back();

    cout << Sll_test.get_size() << endl;
    cout << Sll_test;

    // Testing pop_front
    Sll_test.pop_front();

    cout << Sll_test.get_size() << endl;
    cout << Sll_test;

    // Testing random access
    cout << Sll_test[0]->value << endl;

    // Testing erase function
    shared_ptr<Sll_node<int>> value2 = Sll_test[2];
    Sll_test.erase(Sll_test.back());
    Sll_test.erase(value2);

    cout << Sll_test;

    // Testing inset function
    Sll_test.insert(Sll_test.front(), -9);
    Sll_test.insert(Sll_test.back()->next_node, 8);

    cout << Sll_test[1]->value << endl;
    cout << Sll_test[2]->value << endl;

    Sll_test.insert(Sll_test[2], 1);

    cout << Sll_test[4]->value << endl;
    cout << Sll_test;

    // Testing remove function
    Sll_test.remove(1);

    cout << Sll_test;

    // Testing sort function
    Sll_test.insert(Sll_test[3], -5);
    cout << Sll_test;

    cout << Sll_test.sort();

    // Testing reverse function
    cout << Sll_test.reverse();

    // Testing clear function
    Sll_test.clear();

    // cout << Sll_test;

    cout << Sll_test.get_size() << endl;
    // cout << Sll_test;

    //*/

    /*<-------------------------- doubly_linked_list--------------------------->

    doubly_linked_list::Dll<int> Dll_test;

    // Testing push back and push_front
    Dll_test.push_back(1);
    Dll_test.push_back(2);
    Dll_test.push_front(-1);
    Dll_test.push_back(4);
    Dll_test.push_back(5);
    Dll_test.push_front(-3);

    // Testing front and back functions
    cout << Dll_test.front()->value << endl;
    cout << Dll_test.back()->value << endl;

    // Testing get_size and empty functions
    cout << Dll_test.get_size() << endl;
    cout << Dll_test.empty() << endl;

    // Testing operator <<
    cout << Dll_test;

    // Testing pop_back
    Dll_test.pop_back();

    cout << Dll_test.get_size() << endl;
    cout << Dll_test;

    // Testing pop_front
    Dll_test.pop_front();

    cout << Dll_test.get_size() << endl;
    cout << Dll_test;

    // Testing random access
    cout << Dll_test[0]->value << endl;

    // Testing erase function
    shared_ptr<Dll_node<int>> value2 = Dll_test[2];
    Dll_test.erase(Dll_test.back());
    Dll_test.erase(value2);

    cout << Dll_test;

    // Testing inset function
    Dll_test.insert(Dll_test.front(), -9);
    Dll_test.insert(Dll_test.back()->next_node, 8);

    cout << Dll_test[1]->value << endl;
    cout << Dll_test[2]->value << endl;

    Dll_test.insert(Dll_test[2], 1);

    cout << Dll_test[4]->value << endl;
    cout << Dll_test;

    // Testing remove function
    Dll_test.remove(1);

    cout << Dll_test;

    // Testing sort function
    Dll_test.insert(Dll_test[3], -5);
    cout << Dll_test;

    cout << Dll_test.sort();

    // Testing reverse function
    cout << Dll_test.reverse();

    // Testing clear function
    Dll_test.clear();

    // cout << Sll_test;

    cout << Dll_test.get_size() << endl;
    // cout << Sll_test;

    //*/

    /*<-------------------------- circular_singly_linked_list--------------------------->

    circular_singly_linked_list::Csll<int> Csll_test;

    // Testing push back and push_front
    Csll_test.push_back(1);
    Csll_test.push_back(2);
    Csll_test.push_front(-1);
    Csll_test.push_back(4);
    Csll_test.push_back(5);
    Csll_test.push_front(-3);

    // Testing front and back functions
    cout << Csll_test.front()->value << endl;
    cout << Csll_test.back()->value << endl;

    // Testing get_size and empty functions
    cout << Csll_test.get_size() << endl;
    cout << Csll_test.empty() << endl;

    // Testing operator <<
    cout << Csll_test;

    // Testing pop_back
    Csll_test.pop_back();

    cout << Csll_test.get_size() << endl;
    cout << Csll_test;

    // Testing pop_front
    Csll_test.pop_front();

    cout << Csll_test.get_size() << endl;
    cout << Csll_test;

    // Testing random access
    cout << Csll_test[0]->value << endl;

    // Testing erase function
    shared_ptr<Csll_node<int>> value2 = Csll_test[2];
    Csll_test.erase(Csll_test.back());
    Csll_test.erase(value2);

    cout << Csll_test;

    // Testing inset function
    Csll_test.insert(Csll_test.front(), -9);
    Csll_test.insert(Csll_test.back()->next_node, 8);

    cout << Csll_test[1]->value << endl;
    cout << Csll_test[2]->value << endl;
    cout << Csll_test;

    Csll_test.insert(Csll_test[2], 1);

    cout << Csll_test[4]->value << endl;
    cout << Csll_test.get_size() << endl;
    cout << Csll_test;

    // Testing remove function
    Csll_test.remove(1);

    cout << Csll_test;
    cout << Csll_test.back()->value << endl;

    // Testing sort function
    Csll_test.insert(Csll_test[3], -5);
    cout << Csll_test;

    cout << Csll_test.sort();

    // Testing reverse function
    cout << Csll_test.reverse();

    // Testing clear function
    Csll_test.clear();

    // cout << Sll_test;

    cout << Csll_test.get_size() << endl;
    // cout << Sll_test;

    //*/

    /*<-------------------------- circular_doubly_linked_list--------------------------->

    circular_doubly_linked_list::Cdll<int> Cdll_test;

    // Testing push back and push_front
    Cdll_test.push_back(1);
    Cdll_test.push_back(2);
    Cdll_test.push_front(-1);
    Cdll_test.push_back(4);
    Cdll_test.push_back(5);
    Cdll_test.push_front(-3);

    // Testing front and back functions
    cout << Cdll_test.front()->value << endl;
    cout << Cdll_test.back()->value << endl;

    // Testing get_size and empty functions
    cout << Cdll_test.get_size() << endl;
    cout << Cdll_test.empty() << endl;

    // Testing operator <<
    cout << Cdll_test;

    // Testing pop_back
    Cdll_test.pop_back();

    cout << Cdll_test.get_size() << endl;
    cout << Cdll_test;

    // Testing pop_front
    Cdll_test.pop_front();

    cout << Cdll_test.get_size() << endl;
    cout << Cdll_test;

    // Testing random access
    cout << Cdll_test[0]->value << endl;

    // Testing erase function
    shared_ptr<Cdll_node<int>> value2 = Cdll_test[2];
    Cdll_test.erase(Cdll_test.back());
    Cdll_test.erase(value2);

    cout << Cdll_test;

    // Testing inset function
    Cdll_test.insert(Cdll_test.front(), -9);
    Cdll_test.insert(Cdll_test.back()->next_node, 8);

    cout << Cdll_test[1]->value << endl;
    cout << Cdll_test[2]->value << endl;

    Cdll_test.insert(Cdll_test[2], 1);

    cout << Cdll_test[4]->value << endl;
    cout << Cdll_test;

    // Testing remove function
    Cdll_test.remove(1);

    cout << Cdll_test;

    // Testing sort function
    Cdll_test.insert(Cdll_test[3], -5);
    cout << Cdll_test;

    cout << Cdll_test.sort();

    // Testing reverse function
    cout << Cdll_test.reverse();

    // Testing clear function
    Cdll_test.clear();

    // cout << Sll_test;

    cout << Cdll_test.get_size() << endl;
    // cout << Sll_test;

    //*/

    //<-------------------------- traits_list--------------------------->
    typedef nodes::Sll_node<int> forward_node_t;
    typedef Node<int> node_test;
    typedef List<forward_node_t> list_t;
    // typedef list_t::Iterator iterator_t;

    list_t list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(-1);
    list.push_back(4);
    list.push_back(5);
    list.push_front(-3);
    list.pop_back();
    list.push_front(-9);
    cout<< list.get_size() <<endl;
    cout << list.back() << endl;
    cout << list.front() << endl;

    cout << list;

    /*dlist_t dlist;
    dlist << 10 << 12 << 3;*/

    return 1;
}
