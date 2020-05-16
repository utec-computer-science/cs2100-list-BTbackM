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
            typedef unsigned int size_t;
        public:
            value_t value;
        public:
            Node(const value_t& _value):value(_value){
            }

            size_t size(){
              return 0;
            }

            ~Node(void){
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
    class ForwardListNode : public Node<T> {
        public:
        typedef typename Node<T>::value_t value_t;
        public:
            ForwardListNode<T>* next;
        public:
            ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~ForwardListNode(void){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
                return _out;
            }
    };

    template <typename T>
    class DoubleListNode : public Node<T> {
        public:
        typedef typename Node<T>::value_t value_t;

        public:
            DoubleListNode<T>* next;
            DoubleListNode<T>* prev;

        public:
            DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~DoubleListNode(void){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
                return _out;
            }
    };

    template <typename T>
    class CircularListNode : public Node<T> {
        public:
            typedef typename Node<T>::value_t value_t;
        public:
            CircularListNode<T>* next;
        public:
            CircularListNode(const T& _value):Node<T>(_value),next(nullptr){
            }

            ~CircularListNode(void){
            }

            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
                _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
                return _out;
            }
    };

    #define DEFAULT_NODE 0
    #define FOWARD_NODE 1
    #define DOUBLE_NODE 2
    #define CIRCULAR_NODE 3

    template <typename T, typename NT>
    struct NodeTraits{
        static const int nodeType = DEFAULT_NODE;
    };

    template <typename NT>
    struct NodeTraits< ForwardListNode<NT>, NT >{
        static const int nodeType = FOWARD_NODE;
    };

    template <typename NT>
    struct NodeTraits< DoubleListNode<NT>, NT >{
        static const int nodeType = DOUBLE_NODE;
    };

    template <typename NT>
    struct NodeTraits< CircularListNode<NT>, NT >{
        static const int nodeType = CIRCULAR_NODE;
    };
}

namespace iterators {

    using namespace nodes;

    template <typename Node>
    class Iterator{
    public:
        using node_t = Node ;
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

namespace lists {

    using namespace nodes;
    using namespace iterators;

    template <typename Node>
    class List {
        protected:
            typedef Node node_t;
            typedef typename node_t::value_t value_t;

            node_t* head;
            node_t* tail;
            int size = 0;
        public:
            typedef Iterator<Node> Iterator;

            List(const List&):head(nullptr){
            }

            List(value_t*):head(nullptr){
            }

            List(node_t*):head(nullptr){
            }

            List(int):head(nullptr){
            }

            List(void):head(nullptr){
            }

            ~List(void){
            }

            template<int nodeType>
            void __push_back__(Node**,Node**,value_t,int&);

            void push_back(const value_t& element) {
                __push_back__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element,size);
            }

            template<int nodeType>
            void __push_front__(Node**,Node**,value_t,int&);

            void push_front(const value_t& element) {
                __push_front__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,element,size);
            }

            value_t& front() {
                return head->value;
            }
            value_t& back(){
                return tail->value;
            }

            template<int nodeType>
            void __pop_back__(Node**,Node**,int& size);

            void pop_back() {
                __pop_back__<NodeTraits<node_t,value_t>::nodeType>(&head,&tail,size);
            }

            value_t& operator[] (const int& _position){
                if(_position >= size)
                    throw out_of_range("INDEX OUT OF RANGE");
                node_t * tmp = head;
                for (int i = 0; i < _position; i++, tmp = tmp->next);
                return tmp->value;
            }

            bool empty(){
                return head == nullptr;
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
            static void push_back(Node** head, Node** tail, ValueNode element, int& size) {
                cout << "Hola no tengo trait definido" << endl;
            }
            static void push_front(Node** head, Node** tail, ValueNode element, int& size){
                cout << "Hola no tengo trait definido" << endl;
            }
            static void pop_back(Node** head, Node** tail, int& size){
                cout << "Hola no tengo trait definido" << endl;
            }
            static void print(Node** head, Node** tail, ValueNode element){
                cout << "Hola no tengo trait definido" << endl;
            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,FOWARD_NODE>{
        public:
            static void push_back(Node** head, Node** tail, ValueNode element, int& size){
                auto * new_node = new ForwardListNode<ValueNode>(element);
                new_node->value = element;
                new_node->next = nullptr;

                if(*head == nullptr){
                    *head = new_node;
                    *tail = new_node;
                }else{
                    auto temp = (*head);
                    (*tail)-> next = new_node;
                    (*tail) = new_node;
                }
                size++;
            }

            static void push_front(Node** head, Node** tail, ValueNode element, int& size){
                auto * new_node = new ForwardListNode<ValueNode>(element);
                new_node->value = element;
                new_node->next = nullptr;

                if(*head == nullptr){
                    *head = new_node;
                    *tail = new_node;
                }else{
                    new_node->next = *head;
                    *head = new_node;
                }
                size++;
            }

            static void pop_back(Node** head, Node** tail, int& size){
                if(size > 0){
                    auto * temp = (*head);
                    for(int i = 0; i < size -2; ++i){
                        temp = temp->next;
                    }
                    temp->next = (*head);
                    delete (*tail);
                    (*tail) = temp;
                    size--;
                }
            }

            static void print(Node** head, Node** tail, ValueNode element){

            }

    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,DOUBLE_NODE>{
        public:
            static void push_back(Node** head, Node** tail, ValueNode element, int& size){
                auto new_node = new DoubleListNode<ValueNode>(element);
                new_node->value = element;
                if (!(*head)) {
                    (*head) = new_node;
                } else {
                    new_node->prev = (*tail);
                    new_node->next = nullptr;
                    (*tail)->next = new_node;
                }
                *tail = new_node;
                size++;
            }

            static void pop_back(Node** head, Node** tail, int& size){
                if(size > 0){
                    DoubleListNode<ValueNode>* temp = *tail;
                    *tail = (*tail)->prev;
                    (*tail)->next = nullptr;
                    delete temp;
                    size--;
                }

            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
        public:
            static void push_back(Node** head, Node** tail, ValueNode element, int& size){
                auto * new_node = new CircularListNode<ValueNode>(element);
                new_node->value = element;
                new_node->next = (*head);
                if(*head == nullptr){
                    *head = new_node;
                    *tail = new_node;
                }else{
                    (*tail)->next = new_node;
                    (*tail) = new_node;
                }
                size++;
            }

            static void pop_back(Node** head, Node** tail, int& size){
                if(size > 0){
                    auto * temp = (*head);
                    for(int i = 0; i < size -2; ++i){
                        temp = temp->next;
                    }
                    temp->next = (*head);
                    delete (*tail);
                    (*tail) = temp;
                    size--;
                }
            }
    };


    template< typename Node>  template <int nodeType>
    void List<Node>::__push_back__( typename List<Node>::node_t ** head, typename List<Node>::node_t ** tail, typename List<Node>::value_t element, int& size) {
            ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back(head,tail,element, size);
    }

    template< typename Node>  template <int nodeType>
    void List<Node>::__pop_back__(typename List<Node>::node_t ** head, typename List<Node>::node_t ** tail, int& size) {
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back(head,tail,size);
    }

    template< typename Node>  template <int nodeType>
    void List<Node>::__push_front__(typename List<Node>::node_t ** head, typename List<Node>::node_t ** tail, typename List<Node>::value_t element, int& size) {
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front(head,tail,element, size);
    }
}
