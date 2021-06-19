#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <stdexcept>
#include <cassert>



//typedef int T;

namespace mtm {
    template <class T>
    class SortedList{
    private:
        class Node{
        public:
            T data;
            Node* next_node;
            explicit Node(const T val): data(val), next_node(nullptr) {};
        };
        Node* head;
        int size;
        void clearList();
        void copyList(const SortedList<T>& sorted_list_to_copy);
        void insertNodeAtEnd(Node* last_node, Node* new_node);
        void insertNodeAtStart(Node* new_node);
        Node* getNodeByIndex (int index);
    public:
        class const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        SortedList<T>();
        SortedList<T>(const SortedList<T>& sorted_list_to_copy);
        ~SortedList<T>();
        SortedList& operator=(const SortedList<T>& sorted_list_to_assign);
        void insert(const T& element);
        void remove(const const_iterator iterator);
        template<class Condition>
        SortedList filter(Condition condition) const;
        template<class Applicator>
        SortedList apply(Applicator applicator) const;
        const int length() const;

    };

    template <class T>
    class SortedList<T>::const_iterator{
        const SortedList<T>* list;
        int index;
        const_iterator(const SortedList<T>*, int index);
        friend class SortedList<T>;
    public:
        const T& operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);

        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&)= default;
        const T* operator->() const;
    };


    template <class T>
    SortedList<T>::const_iterator::const_iterator(const SortedList<T>* list, int index) :
            list(list),
            index(index)
    { }

    template <class T>
    const T& SortedList<T>::const_iterator::operator*() const {
        if(index >= list->length()){
            throw std::out_of_range ("");
        }
        assert(index >= 0);
        Node* current = list->head;
        for(int i=0; i<index; i++){
            current= current->next_node;
        }
        return current->data;
    }

    template <class T>
    typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
        ++index;
        return *this;
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::const_iterator::operator++(int) {
        const_iterator result = *this;
        ++*this;
        return result;
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator==(const const_iterator& i) const {
        assert(list == i.list);
        return index == i.index;
    }

    template<class T>
    bool SortedList<T>::const_iterator::operator!=(const const_iterator& i) const {
        return !(*this == i);
    }

    template<class T>
    const T* SortedList<T>::const_iterator::operator->() const {
        if(index >= list->length()){
            throw std::out_of_range ("");
        }
        assert(index >= 0 );
        Node* current = list->head;
        for(int i=0; i<index; i++){
            current= current->next_node;
        }

        return &(current->data);
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::begin() const {
        return const_iterator(this, 0);
    }

    template<class T>
    typename SortedList<T>::const_iterator SortedList<T>::end() const {
        return const_iterator(this, size);
    }

    template <class T>
    SortedList<T>::SortedList():head(nullptr),size(0)
    {}
    template <class T>
    SortedList<T>::SortedList(const SortedList<T>& sorted_list_to_copy):head(nullptr), size(sorted_list_to_copy.size){
        copyList(sorted_list_to_copy);
    }

    template <class T>
    void SortedList<T>::clearList() {
        while(this->head){
            Node* to_delete = this->head;
            this->head = this->head->next_node;
            delete to_delete;
        }
    }

    template <class T>
    void SortedList<T>::insertNodeAtEnd(Node* last_node, Node* new_node) {
        last_node->next_node = new_node;
    }

    template <class T>
    void SortedList<T>::insertNodeAtStart(Node* new_node) {
        new_node->next_node = this->head;
        this->head = new_node;
    }

    template <class T>
    void SortedList<T>::copyList(const SortedList<T>& sorted_list_to_copy) {
        if(!sorted_list_to_copy.head){
            return;
        }
        Node* head_ptr_to_copy = sorted_list_to_copy.head;
        this->head=new Node(head_ptr_to_copy->data);
//        this->head->data=head_ptr_to_copy->data;
        Node* current = this->head;
        head_ptr_to_copy=head_ptr_to_copy->next_node;
        while(head_ptr_to_copy)
        {
            //todo: should we check for allocation failures
            current->next_node=new Node(head_ptr_to_copy->data);
            current=current->next_node;
            current->data= head_ptr_to_copy->data;
            current->next_node= nullptr;
            head_ptr_to_copy=head_ptr_to_copy->next_node;
        }
    }
    template <class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList<T>& sorted_list_to_assign){

        if(this == &sorted_list_to_assign){
            return *this;
        }
        clearList();
        this->size = sorted_list_to_assign.size;
        copyList(sorted_list_to_assign);
        return *this;
    }
    template <class T>
    SortedList<T>::~SortedList(){
        clearList();
    }

    template <class T>
    void SortedList<T>::insert(const T& element){
        Node* new_node = new Node(element);
        this->size++;
        if(this->head== nullptr){
            new_node->next_node= nullptr;
            insertNodeAtStart(new_node);
            return;
        }
        Node* current_ptr = this->head, *previous= nullptr;
        while(current_ptr){
            if(!(current_ptr->data < new_node->data)){
                if (!previous) {
                    insertNodeAtStart(new_node);
                    return;
                }
                Node* store_node = previous->next_node;
                previous->next_node = new_node;
                new_node->next_node = store_node;
                return;
            }
            previous= current_ptr;
            current_ptr= current_ptr->next_node;
        }
        insertNodeAtEnd(previous, new_node);
    }

    template <class T>
    const int SortedList<T>:: length() const{
        return this->size;
    }

    template <class T>
    typename SortedList<T>::Node* SortedList<T>::getNodeByIndex (int index){
        if(index<0 || index>=size){
            throw std::out_of_range("");
        }
        Node* current = this->head;
        for(int i=0; i<index; i++){
            current = current->next_node;
        }
        return current;
    }


    template <class T>
    void SortedList<T>::remove(const SortedList::const_iterator iterator ){
        if(this != iterator.list){
            //todo:check if exception needed
        }
        else{
            Node* node_to_delete=getNodeByIndex(iterator.index);
            if(iterator.index==0){
                this->head=this->head->next_node;
            }
            else{
                Node* previous_node = getNodeByIndex(iterator.index-1);
                previous_node->next_node=node_to_delete->next_node;
            }
            delete node_to_delete;
        }
        this->size--;
    }

    template <class T>
    template<class Condition>
    SortedList<T> SortedList<T>::filter(Condition condition) const{
        SortedList<T> result;
        for (typename SortedList<T>::const_iterator it =begin(); it != end(); ++it) {
            if (condition(*it)) {
                result.insert(*it);
            }
        }
        return result;
    }

    template <class T>
    template<class Applicator>
    SortedList<T> SortedList<T>::apply(Applicator applicator) const{
        SortedList<T> result;
        for (typename SortedList<T>::const_iterator it =begin(); it != end(); ++it) {
            {
                result.insert((applicator(*it)));
            }
        }
        return result;
    }
}
#endif //SORTEDLIST_H
