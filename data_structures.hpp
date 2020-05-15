#pragma once

#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

namespace singly_linked_list{   // abbreviation Sl

    template <typename T>
    struct Sll_node {
        T value;
        shared_ptr<Sll_node<T>> next_node;
    };

    template <typename T>
    class Sll_iterator {
        private:
            typedef Sll_node<T> Sll_node;
            shared_ptr<Sll_node> pointer;

        public:
            Sll_iterator() { pointer = nullptr;};
            Sll_iterator(shared_ptr<Sll_node> ptr) { this->pointer = ptr; };

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
            shared_ptr<Node> head_pointer;
            shared_ptr<Node> tail_pointer;
            unsigned int size;

        public:
            typedef Sll_iterator<T> Iterator;

            Sll( shared_ptr<Sll<T>> List ) {}

            Sll( shared_ptr<T> arr, int n ) {}

            Sll( shared_ptr<Node> node ) {}

            Sll( int n ) {}

            Sll() {
                head_pointer = nullptr;
                tail_pointer = nullptr;
                size = 0;
            }

            virtual ~Sll() { }

            shared_ptr<Node> front();
    		shared_ptr<Node> back();
            void push_back( const T& element );
            void push_front( const T& element );
            shared_ptr<Node> pop_back();
            shared_ptr<Node> pop_front();
            shared_ptr<Node> operator[] ( const int& place);
            bool empty();
            unsigned int get_size();
            void clear();
            void erase( shared_ptr<Node> pointer );
            void insert( shared_ptr<Node> pointer, const T& element );
            void remove( const T& element );
            Sll& sort();
            Sll& reverse();

            inline friend std::ostream& operator<< (std::ostream& os, const Sll<T>& list ) {
                shared_ptr<Node> pointer = list.head_pointer;
                while (pointer != nullptr) {
                    cout << "(" << pointer->value << ") -> ";
                    pointer = pointer->next_node;
                }
                cout << "nullptr" <<endl;
                return os;
            }
        };
}

namespace doubly_linked_list{   // abbreviation Dll

    template <typename T>
    struct Dll_node {
        T value;
        shared_ptr<Dll_node<T>> prev_node;
        shared_ptr<Dll_node<T>> next_node;
    };

    template <typename T>
    class Dll_iterator {
        private:
            typedef Dll_node<T> Dll_node;
            shared_ptr<Dll_node> pointer;

        public:
            Dll_iterator() { pointer = nullptr;};
            Dll_iterator(shared_ptr<Dll_node> ptr) { this->pointer = ptr; };

            // Operators

            void operator ++() {
                this->pointer = this->pointer->next_node;
            }

            void operator --() {
                this->pointer = this->pointer->prev_node;
            }

            void operator ++(int n) {
                for (int i = 0; i < n; ++i)
                    this->pointer = this->pointer->next_node;
            }

            T operator * () {
                return this->pointer->value;
            }

            bool operator == (const Dll_iterator & it) {
                return this->pointer == it.pointer;
            }

            bool operator != (const Dll_iterator & it) {
                return this->pointer != it.pointer;
            }

            bool operator <= (const Dll_iterator & it) {
                return this->pointer <= it.pointer;
            }

            bool operator >= (const Dll_iterator & it) {
                return this->pointer >= it.pointer;
            }

            bool operator < (const Dll_iterator & it) {
                return this->pointer < it.pointer;
            }

            bool operator > (const Dll_iterator & it) {
                return this->pointer > it.pointer;
            }
    };

    template <typename T>
    class Dll {
        private:
            typedef Dll_node<T> Node;
            shared_ptr<Node> head_pointer;
            shared_ptr<Node> tail_pointer;
            unsigned int size;

        public:
            typedef Dll_iterator<T> Iterator;

            Dll( shared_ptr<Dll<T>> List ) {}

            Dll( shared_ptr<T> arr, int n ) {}

            Dll( shared_ptr<Node> node ) {}

            Dll( int n ) {}

            Dll() {
                head_pointer = nullptr;
                tail_pointer = nullptr;
                size = 0;
            }

            virtual ~Dll() { }

            shared_ptr<Node> front();
    		shared_ptr<Node> back();
            void push_back( const T& element );
            void push_front( const T& element );
            shared_ptr<Node> pop_back();
            shared_ptr<Node> pop_front();
            shared_ptr<Node> operator[] ( const int& place);
            bool empty();
            unsigned int get_size();
            void clear();
            void erase( shared_ptr<Node> pointer );
            void insert( shared_ptr<Node> pointer, const T& element );
            void remove( const T& element );
            Dll& sort();
            Dll& reverse();

            inline friend std::ostream& operator<< (std::ostream& os, const Dll<T>& list ) {
                shared_ptr<Node> pointer = list.head_pointer;
                while (pointer != nullptr) {
                    cout << " <- (" << pointer->value << ") -> ";
                    pointer = pointer->next_node;
                }
                cout << "nullptr" <<endl;
                return os;
            }
        };
}

namespace circular_singly_linked_list{   // abbreviation Csll

    template <typename T>
    struct Csll_node {
        T value;
        shared_ptr<Csll_node<T>> next_node;
    };

    template <typename T>
    class Csll_iterator {
        private:
            typedef Csll_node<T> Csll_node;
            shared_ptr<Csll_node> pointer;

        public:
            Csll_iterator() { pointer = nullptr;};
            Csll_iterator(shared_ptr<Csll_node> ptr) { this->pointer = ptr; };

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

            bool operator == (const Csll_iterator & it) {
                return this->pointer == it.pointer;
            }

            bool operator != (const Csll_iterator & it) {
                return this->pointer != it.pointer;
            }

            bool operator <= (const Csll_iterator & it) {
                return this->pointer <= it.pointer;
            }

            bool operator >= (const Csll_iterator & it) {
                return this->pointer >= it.pointer;
            }

            bool operator < (const Csll_iterator & it) {
                return this->pointer < it.pointer;
            }

            bool operator > (const Csll_iterator & it) {
                return this->pointer > it.pointer;
            }
    };

    template <typename T>
    class Csll {
        private:
            typedef Csll_node<T> Node;
            shared_ptr<Node> head_pointer;
            shared_ptr<Node> tail_pointer;
            unsigned int size;

        public:
            typedef Csll_iterator<T> Iterator;

            Csll( shared_ptr<Csll<T>> List ) {}

            Csll( shared_ptr<T> arr, int n ) {}

            Csll( shared_ptr<Node> node ) {}

            Csll( int n ) {}

            Csll() {
                head_pointer = nullptr;
                tail_pointer = nullptr;
                size = 0;
            }

            virtual ~Csll() { }

            shared_ptr<Node> front();
    		shared_ptr<Node> back();
            void push_back( const T& element );
            void push_front( const T& element );
            shared_ptr<Node> pop_back();
            shared_ptr<Node> pop_front();
            shared_ptr<Node> operator[] ( const int& place);
            bool empty();
            unsigned int get_size();
            void clear();
            void erase( shared_ptr<Node> pointer );
            void insert( shared_ptr<Node> pointer, const T& element );
            void remove( const T& element );
            Csll& sort();
            Csll& reverse();

            inline friend std::ostream& operator<< (std::ostream& os, const Csll<T>& list ) {
                shared_ptr<Node> pointer = list.head_pointer;
                do{
                    cout << "(" << pointer->value << ") -> ";
                    pointer = pointer->next_node;
                }while( pointer != list.head_pointer);
                cout << "head" <<endl;
                return os;
            }
        };
}

namespace circular_doubly_linked_list{   // abbreviation Cdll

    template <typename T>
    struct Cdll_node {
        T value;
        shared_ptr<Cdll_node<T>> prev_node;
        shared_ptr<Cdll_node<T>> next_node;
    };

    template <typename T>
    class Cdll_iterator {
        private:
            typedef Cdll_node<T> Cdll_node;
            shared_ptr<Cdll_node> pointer;

        public:
            Cdll_iterator() { pointer = nullptr;};
            Cdll_iterator(shared_ptr<Cdll_node> ptr) { this->pointer = ptr; };

            // Operators

            void operator ++() {
                this->pointer = this->pointer->next_node;
            }

            void operator --() {
                this->pointer = this->pointer->prev_node;
            }

            void operator ++(int n) {
                for (int i = 0; i < n; ++i)
                    this->pointer = this->pointer->next_node;
            }

            T operator * () {
                return this->pointer->value;
            }

            bool operator == (const Cdll_iterator & it) {
                return this->pointer == it.pointer;
            }

            bool operator != (const Cdll_iterator & it) {
                return this->pointer != it.pointer;
            }

            bool operator <= (const Cdll_iterator & it) {
                return this->pointer <= it.pointer;
            }

            bool operator >= (const Cdll_iterator & it) {
                return this->pointer >= it.pointer;
            }

            bool operator < (const Cdll_iterator & it) {
                return this->pointer < it.pointer;
            }

            bool operator > (const Cdll_iterator & it) {
                return this->pointer > it.pointer;
            }
    };

    template <typename T>
    class Cdll {
        private:
            typedef Cdll_node<T> Node;
            shared_ptr<Node> head_pointer;
            shared_ptr<Node> tail_pointer;
            unsigned int size;

        public:
            typedef Cdll_iterator<T> Iterator;

            Cdll( shared_ptr<Cdll<T>> List ) {}

            Cdll( shared_ptr<T> arr, int n ) {}

            Cdll( shared_ptr<Node> node ) {}

            Cdll( int n ) {}

            Cdll() {
                head_pointer = nullptr;
                tail_pointer = nullptr;
                size = 0;
            }

            virtual ~Cdll() { }

            shared_ptr<Node> front();
    		shared_ptr<Node> back();
            void push_back( const T& element );
            void push_front( const T& element );
            shared_ptr<Node> pop_back();
            shared_ptr<Node> pop_front();
            shared_ptr<Node> operator[] ( const int& place);
            bool empty();
            unsigned int get_size();
            void clear();
            void erase( shared_ptr<Node> pointer );
            void insert( shared_ptr<Node> pointer, const T& element );
            void remove( const T& element );
            Cdll& sort();
            Cdll& reverse();

            inline friend std::ostream& operator<< (std::ostream& os, const Cdll<T>& list ) {
                shared_ptr<Node> pointer = list.head_pointer;
                while (pointer != nullptr) {
                    cout << " <- (" << pointer->value << ") -> ";
                    pointer = pointer->next_node;
                }
                cout << "nullptr" <<endl;
                return os;
            }
        };
}
