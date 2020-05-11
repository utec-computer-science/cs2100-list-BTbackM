#include <iostream>
#include "data_structures.hpp"

using namespace std;

//<-------------------------- singly_linked_list--------------------------->

template <typename T>
shared_ptr<singly_linked_list::Sll_node<T>> singly_linked_list::Sll<T>::front(){
    return head_pointer;
}

template <typename T>
shared_ptr<singly_linked_list::Sll_node<T>> singly_linked_list::Sll<T>::back(){
    return tail_pointer;
}

template <typename T>
void singly_linked_list::Sll<T>::push_back( const T& element ) {
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->value = element; new_node->next_node = nullptr;
    if (head_pointer == nullptr) {
        tail_pointer = head_pointer = new_node;
    } else {
        tail_pointer->next_node = new_node;
        tail_pointer = new_node;
    }
    size++;
}

template <typename T>
void singly_linked_list::Sll<T>::push_front( const T& element ) {
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->value = element; new_node->next_node = head_pointer;
    if ( head_pointer == nullptr ) {
        head_pointer = tail_pointer = new_node;
    } else {
        head_pointer = new_node;
    }
    size++;
}

template <typename T>
shared_ptr<singly_linked_list::Sll_node<T>> singly_linked_list::Sll<T>::pop_back() {
    if ( head_pointer == tail_pointer ){
        shared_ptr<Node> tmp = head_pointer;
        // delete head_pointer;
        size--;
        head_pointer = tail_pointer = nullptr;
        return tmp;
    } else {
        shared_ptr<Node> tmp = head_pointer;
        while (tmp->next_node != tail_pointer){
            tmp = tmp->next_node;
        }
        tail_pointer = tmp;
        // delete tmp->next_node;
        tail_pointer->next_node = nullptr;
        size--;
        return tmp;
    }
}

template <typename T>
shared_ptr<singly_linked_list::Sll_node<T>> singly_linked_list::Sll<T>::pop_front() {
    if ( head_pointer == tail_pointer ){
        shared_ptr<Node> tmp = head_pointer;
        // delete head_pointer;
        size--;
        head_pointer = tail_pointer = nullptr;
        return tmp;
    } else {
        shared_ptr<Node> tmp = head_pointer;
        head_pointer = tmp->next_node;
        size--;
        // delete tmp;
        return tmp;
    }
}

template <typename T>
shared_ptr<singly_linked_list::Sll_node<T>> singly_linked_list::Sll<T>::operator[] ( const int& place) {
    shared_ptr<Node> pointer = head_pointer;
    if( place == 0 ) { return front(); }
    else if ( place <= get_size() ) {
        for (auto i = 0; i != place+1; i++) {
            if( i == place) {
                return pointer;
            }
            pointer = pointer->next_node;
        }
    }
    return 0;
}

template <typename T>
bool singly_linked_list::Sll<T>::empty() {
    return head_pointer == nullptr;
}

template <typename T>
unsigned int singly_linked_list::Sll<T>::get_size() {
    return size;
}

template <typename T>
void singly_linked_list::Sll<T>::clear() {
    while( !empty() ) {
        pop_back();
    }
}

template <typename T>
void singly_linked_list::Sll<T>::erase( shared_ptr<Node> pointer ) {
    if( pointer == head_pointer ) {
        pop_front();
    } else if ( pointer == tail_pointer ) {
        pop_back();
    } else {
        for (shared_ptr<Node> tmp = head_pointer; tmp != nullptr; tmp = tmp->next_node){
            if ( tmp->next_node == pointer ) {
                tmp->next_node = ( tmp->next_node )->next_node;
                // delete pointer;
                size--;
            }
        }
    }
}

template <typename T>
void singly_linked_list::Sll<T>::insert( shared_ptr<Node> pointer, const T& element ) {
    if( pointer == head_pointer ) {
        push_front(element);
    } else if ( pointer == tail_pointer->next_node ) {
        push_back(element);
    } else {
        shared_ptr<Node> tmp = head_pointer;
        while(tmp != nullptr ){
            if( tmp == pointer ) {
                shared_ptr<Node> new_node = make_shared<Node>();
                new_node->value = tmp->value; new_node->next_node = tmp->next_node;
                tmp->value = element;
                tmp->next_node = new_node;
            }
            tmp = tmp->next_node;
        }
        size++;
    }
}

template <typename T>
void singly_linked_list::Sll<T>::remove( const T& element ) {
    if( element == head_pointer->value ) {
        pop_front();
    } else {
        shared_ptr<Node> tmp = head_pointer;
        shared_ptr<Node> ptr;
        while( tmp != nullptr ){
            if( element == tmp->value ) {
                ptr = tmp->next_node;
                erase(tmp);
                tmp = ptr;
            } else {
                tmp = tmp->next_node;
            }
        }
    }
}

template <typename T>
singly_linked_list::Sll<T>& singly_linked_list::Sll<T>::sort() {
    for(auto i = 1 ; i < get_size() ; i++) {
        T it = ( ( *this )[i] )->value;
        int j = i - 1;
        while(j >= 0 && ( ( *this )[j] )->value > it) {
            ( ( *this )[j + 1] )->value = ( ( *this )[j] )->value;
            j = j - 1;

        }
        ( ( *this )[j + 1] )->value = it;
    }
    return (*this);
}

template <typename T>
singly_linked_list::Sll<T>& singly_linked_list::Sll<T>::reverse() {
    for(auto i = 0; i < get_size()/2; i++) {
        T tmp = ( ( *this )[i] )->value;
        ( ( *this )[i] )->value = ( ( *this )[size-1-i] )->value;
        ( (*this)[size-1-i] )->value = tmp;
    }
    return *this;
}

//<-------------------------- doubly_linked_list--------------------------->

template <typename T>
shared_ptr<doubly_linked_list::Dll_node<T>> doubly_linked_list::Dll<T>::front(){
    return head_pointer;
}

template <typename T>
shared_ptr<doubly_linked_list::Dll_node<T>> doubly_linked_list::Dll<T>::back(){
    return tail_pointer;
}

template <typename T>
void doubly_linked_list::Dll<T>::push_back( const T& element ) {
    if ( head_pointer == nullptr ) {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->value = element; new_node->prev_node = nullptr; new_node->next_node = nullptr;
        head_pointer = tail_pointer = new_node;
    } else {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->value = element; new_node->prev_node = tail_pointer; new_node->next_node = nullptr;
        tail_pointer->next_node = new_node;
        tail_pointer = new_node;
    }
    size++;
}

template <typename T>
void doubly_linked_list::Dll<T>::push_front( const T& element ) {
    if ( head_pointer == nullptr ) {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->value = element; new_node->prev_node = nullptr; new_node->next_node = nullptr;
        head_pointer = tail_pointer = new_node;
    } else {
        shared_ptr<Node> new_node = make_shared<Node>();
        new_node->value = element; new_node->prev_node = nullptr; new_node->next_node = head_pointer;
        head_pointer->prev_node = new_node;
        head_pointer = new_node;
    }
    size++;
}

template <typename T>
shared_ptr<doubly_linked_list::Dll_node<T>> doubly_linked_list::Dll<T>::pop_back() {
    if ( head_pointer == tail_pointer ){
        shared_ptr<Node> tmp = head_pointer;
        // delete tmp;
        size--;
        head_pointer = tail_pointer = nullptr;
        return tmp;
    } else {
        shared_ptr<Node> tmp = head_pointer;
        while (tmp->next_node != tail_pointer){
            tmp = tmp->next_node;
        }
        tail_pointer = tmp;
        // delete tmp->next_node;
        tail_pointer->next_node = nullptr;
        size--;
        return tmp;
    }
}

template <typename T>
shared_ptr<doubly_linked_list::Dll_node<T>> doubly_linked_list::Dll<T>::pop_front() {
    if ( head_pointer == tail_pointer ){
        shared_ptr<Node> tmp = head_pointer;
        // delete head_pointer;
        size--;
        head_pointer = tail_pointer = nullptr;
        return tmp;
    } else {
        shared_ptr<Node> tmp = head_pointer;
        // delete head_pointer;
        head_pointer = tmp->next_node;
        size--;
        return tmp;
    }
}

template <typename T>
shared_ptr<doubly_linked_list::Dll_node<T>> doubly_linked_list::Dll<T>::operator[] ( const int& place) {
    shared_ptr<Node> pointer = head_pointer;
    if( place == 0 ) { return front(); }
    else if ( place <= get_size() ) {
        for (auto i = 0; i != place+1; i++) {
            if( i == place) {
                return pointer;
            }
            pointer = pointer->next_node;
        }
    }
    return 0;
}

template <typename T>
bool doubly_linked_list::Dll<T>::empty() {
    return head_pointer == nullptr;
}

template <typename T>
unsigned int doubly_linked_list::Dll<T>::get_size() {
    return size;
}

template <typename T>
void doubly_linked_list::Dll<T>::clear() {
    while( !empty() ) {
        pop_back();
    }
}

template <typename T>
void doubly_linked_list::Dll<T>::erase( shared_ptr<Node> pointer ) {
    if( pointer == head_pointer ) {
        pop_front();
    } else if ( pointer == tail_pointer ) {
        pop_back();
    } else {
        for ( shared_ptr<Node> tmp = head_pointer; tmp != nullptr; tmp = tmp->next_node ){
            if ( tmp->next_node == pointer ) {
                tmp->next_node = ( tmp->next_node )->next_node;
                // delete pointer;
                size--;
            }
        }
    }
}

template <typename T>
void doubly_linked_list::Dll<T>::insert( shared_ptr<Node> pointer, const T& element ) {
    if( pointer == head_pointer ) {
        push_front(element);
    } else if ( pointer == tail_pointer->next_node ) {
        push_back(element);
    } else {
        shared_ptr<Node> tmp = head_pointer;
        while(tmp != nullptr ){
            if( tmp == pointer ) {
                shared_ptr<Node> new_node = make_shared<Node>();
                new_node->value = tmp->value; new_node->prev_node = pointer; new_node->next_node = tmp->next_node;
                tmp->value = element;
                tmp->next_node = new_node;
            }
            tmp = tmp->next_node;
        }
        size++;
    }
}

template <typename T>
void doubly_linked_list::Dll<T>::remove( const T& element ) {
    if( element == head_pointer->value ) {
        pop_front();
    } else {
        shared_ptr<Node> tmp = head_pointer;
        shared_ptr<Node> ptr;
        while( tmp != nullptr ){
            if( element == tmp->value ) {
                ptr = tmp->next_node;
                erase(tmp);
                tmp = ptr;
            } else {
                tmp = tmp->next_node;
            }
        }
    }
}

template <typename T>
doubly_linked_list::Dll<T>& doubly_linked_list::Dll<T>::sort() {
    for(auto i = 1 ; i < get_size() ; i++) {
        T it = ( ( *this )[i] )->value;
        int j = i - 1;
        while(j >= 0 && ( ( *this )[j] )->value > it) {
            ( ( *this )[j + 1] )->value = ( ( *this )[j] )->value;
            j = j - 1;

        }
        ( ( *this )[j + 1] )->value = it;
    }
    return (*this);
}

template <typename T>
doubly_linked_list::Dll<T>& doubly_linked_list::Dll<T>::reverse() {
    for(auto i = 0; i < get_size()/2; i++) {
        T tmp = ( ( *this )[i] )->value;
        ( ( *this )[i] )->value = ( ( *this )[size-1-i] )->value;
        ( (*this)[size-1-i] )->value = tmp;
    }
    return *this;
}
