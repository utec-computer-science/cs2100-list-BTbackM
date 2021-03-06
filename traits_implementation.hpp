#pragma once

#include <iostream>
#include <ostream>
#include <memory>

using namespace std;

namespace nodes { // Node trait, Sll_Node, Dll_node, Csll node and Cdll node
    template <typename T>
    class Node {
        public:
            typedef T value_t;
            // 1typedef unsigned int size_t;

            value_t value;

            Node(const value_t& _value):value(_value){
            }

            size_t size(){
              return 0;
            }

            ~Node() {
            }

            value_t& operator*(void){
                return value;
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
                _out << "Nodo: " <<  _node.value;
                return _out;
            }
    };

    template <typename T>
    class Sll_node : public Node<T> {
        public:
            typedef typename Node<T>::value_t value_t;

            Sll_node<T>* next;

            Sll_node(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~Sll_node(){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Sll_node<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
                return _out;
            }
    };

    template <typename T>
    class Dll_node : public Node<T> {
        public:
            typedef typename Node<T>::value_t value_t;

            Dll_node<T>* next;
            Dll_node<T>* prev;

            Dll_node(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~Dll_node(){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Dll_node<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
                return _out;
            }
    };

    template <typename T>
    class Csll_node : public Node<T> {
        public:
            typedef typename Node<T>::value_t value_t;

            Csll_node<T>* next;

            Csll_node(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~Csll_node(){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Csll_node<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
                return _out;
            }
    };

    template <typename T>
    class Cdll_node : public Node<T> {
        public:
            typedef typename Node<T>::value_t value_t;

            Cdll_node<T>* next;

            Cdll_node(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~Cdll_node(){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Cdll_node<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
                return _out;
            }
    };

    #define DEFAULT_NODE 0
    #define SLL_NODE 1
    #define DLL_NODE 2
    #define CSLL_NODE 3
    #define CDLL_NODE 4

    template <typename T, typename NT>
    struct NodeTraits{
        static const int nodeType = DEFAULT_NODE;
    };

    template <typename NT>
    struct NodeTraits< Sll_node<NT>, NT >{
        static const int nodeType = SLL_NODE;
    };

    template <typename NT>
    struct NodeTraits< Dll_node<NT>, NT >{
        static const int nodeType = DLL_NODE;
    };

    template <typename NT>
    struct NodeTraits< Csll_node<NT>, NT >{
        static const int nodeType = CSLL_NODE;
    };

    template <typename NT>
    struct NodeTraits< Cdll_node<NT>, NT >{
        static const int nodeType = CDLL_NODE;
    };
}

namespace iterators { // One iterator

    using namespace nodes;

    template <typename Node>
    class Iterator{
    public:
        typedef Node node_t;
        typedef typename node_t::value_t value_t;

    protected:
        node_t * pointer;

    public:
        Iterator (node_t* pointer = nullptr){
        }

        ~Iterator(void){
        }

        Iterator& operator++ (void){
            pointer = pointer->next;
            return *this;
        }

        Iterator operator=(Iterator other) {
            return (*this);
        }

        bool operator!= (Iterator it){
            return pointer != it.pointer;
        }

        value_t& operator* (void) {
            return **pointer;
        }

    };
}

namespace lists { // Sll, Dll, Csll, Cdll implementation

    using namespace nodes;
    using namespace iterators;

    template <typename Node>
    class List {
        protected:
            typedef Node node_t;
            typedef typename node_t::value_t value_t;

            node_t* head_pointer;
            node_t* tail_pointer;
            int size = 0;
        public:
            typedef Iterator<Node> Iterator;

            List(const List&):head_pointer(nullptr){
            }

            List(value_t*):head_pointer(nullptr){
            }

            List(node_t*):head_pointer(nullptr){
            }

            List(int):head_pointer(nullptr){
            }

            List(void):head_pointer(nullptr){
            }

            ~List(void){
            }

            template<int nodeType>
            void __push_back__(Node**,Node**,value_t,int&);

            void push_back(const value_t& element) {
                __push_back__<NodeTraits<node_t,value_t>::nodeType>(&head_pointer,&tail_pointer,element,size);
            }

            template<int nodeType>
            void __push_front__(Node**,Node**,value_t,int&);

            void push_front(const value_t& element) {
                __push_front__<NodeTraits<node_t,value_t>::nodeType>(&head_pointer,&tail_pointer,element,size);
            }

            value_t& front() {
                return head_pointer->value;
            }
            value_t& back(){
                return tail_pointer->value;
            }

            template<int nodeType>
            void __pop_back__(Node**,Node**,int& size);

            void pop_back() {
                __pop_back__<NodeTraits<node_t,value_t>::nodeType>(&head_pointer,&tail_pointer,size);
            }

            value_t& operator[] (const int& _position){
                if(_position >= size)
                    throw out_of_range("NOT FOUND");
                node_t * tmp = head_pointer;
                for (int i = 0; i < _position; i++, tmp = tmp->next);
                return tmp->value;
            }

            bool empty(){
                return head_pointer == nullptr;
            }

            unsigned int get_size(){
                return size;
            }

            template<typename _T>
            inline friend ostream& operator<< (ostream& out, const List<_T>&){
                out << "Nothing to print in father" << endl;
                return out;
            }

            /*List& operator<< (const value_t& _value){
                this->push_back(_value);
                return *this;
            }
            List& operator>> (const value_t& _value){
                this->push_front(_value);
                return *this;
            }*/
    };

    template <typename Node, typename ValueNode, int nodeType>
    class ListHelper{
        public:
            static void push_back(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size) {
                cout << "Hola no tengo trait definido" << endl;
            }
            static void push_front(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                cout << "Hola no tengo trait definido" << endl;
            }
            static void pop_back(Node** head_pointer, Node** tail_pointer, int& size){
                cout << "Hola no tengo trait definido" << endl;
            }
            static void print(Node** head_pointer, Node** tail_pointer, ValueNode element){
                cout << "Hola no tengo trait definido" << endl;
            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,SLL_NODE>{
        public:
            static void push_back(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                auto * new_node = new Sll_node<ValueNode>(element);
                new_node->value = element; new_node->next = nullptr;
                if(*head_pointer == nullptr){
                    *head_pointer = *tail_pointer = new_node;
                }else{
                    (*tail_pointer)->next = new_node;
                    (*tail_pointer) = new_node;
                }
                size++;
            }

            static void push_front(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                auto * new_node = new Sll_node<ValueNode>(element);
                new_node->value = element; new_node->next = nullptr;

                if(*head_pointer == nullptr){
                    *head_pointer = *tail_pointer = new_node;
                }else{
                    new_node->next = *head_pointer;
                    *head_pointer = new_node;
                }
                size++;
            }

            static void pop_back(Node** head_pointer, Node** tail_pointer, int& size){
                if ( *head_pointer == *tail_pointer ){
                    auto * tmp = *head_pointer;
                    // delete head_pointer;
                    size--;
                    *head_pointer = *tail_pointer = nullptr;
                } else {
                    auto * tmp = *head_pointer;
                    while (tmp->next != *tail_pointer){
                        tmp = tmp->next;
                    }
                    *tail_pointer = tmp;
                    // delete tmp->next_node;
                    (*tail_pointer)->next = nullptr;
                    size--;
                }
            }

            static void print(Node** head_pointer, Node** tail_pointer, ValueNode element){

            }

    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,DLL_NODE>{
        public:
            static void push_back(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                auto new_node = new Dll_node<ValueNode>(element);
                new_node->value = element;
                if (!(*head_pointer)) {
                    (*head_pointer) = new_node;
                } else {
                    new_node->prev = (*tail_pointer);
                    new_node->next = nullptr;
                    (*tail_pointer)->next = new_node;
                }
                *tail_pointer = new_node;
                size++;
            }

            static void pop_back(Node** head_pointer, Node** tail_pointer, int& size){
                if ( *head_pointer == *tail_pointer ){
                    auto * tmp = *head_pointer;
                    // delete head_pointer;
                    size--;
                    *head_pointer = *tail_pointer = nullptr;
                } else {
                    auto * tmp = *head_pointer;
                    while (tmp->next != *tail_pointer){
                        tmp = tmp->next;
                    }
                    *tail_pointer = tmp;
                    // delete tmp->next_node;
                    (*tail_pointer)->next = nullptr;
                    size--;
                }
            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,CSLL_NODE>{
        public:
            static void push_back(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                auto * new_node = new Csll_node<ValueNode>(element);
                new_node->value = element;
                new_node->next = (*head_pointer);
                if(*head_pointer == nullptr){
                    *head_pointer = new_node;
                    *tail_pointer = new_node;
                }else{
                    (*tail_pointer)->next = new_node;
                    (*tail_pointer) = new_node;
                }
                size++;
            }

            static void pop_back(Node** head_pointer, Node** tail_pointer, int& size){
                if ( *head_pointer == *tail_pointer ){
                    auto * tmp = *head_pointer;
                    // delete head_pointer;
                    size--;
                    *head_pointer = *tail_pointer = nullptr;
                } else {
                    auto * tmp = *head_pointer;
                    while (tmp->next != *tail_pointer){
                        tmp = tmp->next;
                    }
                    *tail_pointer = tmp;
                    // delete tmp->next_node;
                    (*tail_pointer)->next = nullptr;
                    size--;
                }
            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,CDLL_NODE>{
        public:
            static void push_back(Node** head_pointer, Node** tail_pointer, ValueNode element, int& size){
                auto * new_node = new Cdll_node<ValueNode>(element);
                new_node->value = element;
                new_node->next = (*head_pointer);
                if(*head_pointer == nullptr){
                    *head_pointer = new_node;
                    *tail_pointer = new_node;
                }else{
                    (*tail_pointer)->next = new_node;
                    (*tail_pointer) = new_node;
                }
                size++;
            }

            static void pop_back(Node** head_pointer, Node** tail_pointer, int& size){
                if ( *head_pointer == *tail_pointer ){
                    auto * tmp = *head_pointer;
                    // delete head_pointer;
                    size--;
                    *head_pointer = *tail_pointer = nullptr;
                } else {
                    auto * tmp = *head_pointer;
                    while (tmp->next != *tail_pointer){
                        tmp = tmp->next;
                    }
                    *tail_pointer = tmp;
                    // delete tmp->next_node;
                    (*tail_pointer)->next = nullptr;
                    size--;
                }
            }
    };

    template< typename Node>  template <int nodeType>
    void List<Node>::__push_back__( typename List<Node>::node_t ** head_pointer, typename List<Node>::node_t ** tail_pointer, typename List<Node>::value_t element, int& size) {
            ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back(head_pointer,tail_pointer,element, size);
    }

    template< typename Node>  template <int nodeType>
    void List<Node>::__pop_back__(typename List<Node>::node_t ** head_pointer, typename List<Node>::node_t ** tail_pointer, int& size) {
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back(head_pointer,tail_pointer,size);
    }

    template< typename Node>  template <int nodeType>
    void List<Node>::__push_front__(typename List<Node>::node_t ** head_pointer, typename List<Node>::node_t ** tail_pointer, typename List<Node>::value_t element, int& size) {
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front(head_pointer,tail_pointer,element, size);
    }
}
