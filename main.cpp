#include <iostream>
#include "data_structures.hpp"
#include "data_structures.cpp"

using namespace std;
using namespace singly_linked_list;
using namespace doubly_linked_list;

int main(int argc, char const *argv[]) {
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

    */

    //<-------------------------- doubly_linked_list--------------------------->

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
    return 0;
}
