#pragma once

#include <iostream>
#include <ostream>

using namespace std;

namespace singly_linked_list{   // abbreviation Sl

    template <typename T>
    struct Sll_node {
        T value;
        Sll_node<T> * next_node;
    };

    template <typename T>
    class Sll_iterator {
        private:
            typedef Sll_node<T> Sll_node;
            Sll_node * pointer;

        public:
            Sll_iterator() { pointer = nullptr;};
            Sll_iterator(Sll_node * ptr) { this->pointer = ptr; };

            // Operators

            void operator ++() {
                this->pointer = this->pointer->next;
            }

            void operator ++(int n) {
                for (int i = 0; i < n; ++i)
                    this->pointer = this->pointer->next;
            }

            T operator * () {
                return this->pointer->value;
            }

            bool operator == (const Sll_iterator & it) {
                return this->pointer == it.pointer;
            }

            bool operator != (const Sll_iterator & it) {
                return this->pointer != it.pointer;
            }

            bool operator <= (const Sll_iterator & it) {
                return this->pointer <= it.pointer;
            }

            bool operator >= (const Sll_iterator & it) {
                return this->pointer >= it.pointer;
            }

            bool operator < (const Sll_iterator & it) {
                return this->pointer < it.pointer;
            }

            bool operator > (const Sll_iterator & it) {
                return this->pointer > it.pointer;
            }
    };

    template <typename T>
    class Sll {
        private:
            typedef Sll_node<T> Node;
            Node * head_pointer;
            Node * tail_pointer;
            unsigned int size;

        public:
            typedef Sll_iterator<T> Iterator;

            Sll( Sll<T> * List ) {}

            Sll( T * arr, int n ) {}

            Sll( Node * node ) {}

            Sll( int n ) {}

            Sll() {
                head_pointer = nullptr;
                tail_pointer = nullptr;
                size = 0;
            }

            virtual ~Sll() { }

            Node * front();
    		Node * back();
            void push_back( const T& element );
            void push_front( const T& element );
            Node * pop_back();
            Node * pop_front();
            Node * operator[] ( const int& place);
            bool empty();
            unsigned int get_size();
            void clear();
            void erase( Node * pointer );
            void insert( Node * pointer, const T& element );
            void remove( const T& element );
            Sll& sort();
            Sll& reverse();

            inline friend std::ostream& operator<< (std::ostream& os, const Sll<T>& list ) {
                Node * pointer = list.head_pointer;
                while (pointer != nullptr) {
                    cout << pointer->value << " -> ";
                    pointer = pointer->next_node;
                }
                cout << "nullptr" <<endl;
                return os;
            }
        };
}
