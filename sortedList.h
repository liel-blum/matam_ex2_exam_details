#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//typedef int T;

namespace mtm {
    template <class T>
    class SortedList{
    private:
        class Node{
        public:
            T data;
            Node* next_node;
        };
        Node* head;
        int size;
        void clearList();
        void copyList(const SortedList<T>& sorted_list_to_copy);
        void insertNodeAtEnd(Node* last_node, Node* new_node);
        void insertNodeAtStart(Node* new_node);
    public:
        SortedList<T>();
        SortedList<T>(const SortedList<T>& sorted_list_to_copy);
        ~SortedList<T>();
        SortedList& operator=(const SortedList<T>& sorted_list_to_assign);
        void insert(const T& element);
        int length();
    };
    template <class T>
    SortedList<T>::SortedList():head(nullptr),size(0)
    {}
    template <class T>
    SortedList<T>::SortedList(const SortedList<T>& sorted_list_to_copy):size(sorted_list_to_copy.size){
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
        this->head=new Node;
        this->head->data=head_ptr_to_copy->data;
        Node* current = this->head;
        head_ptr_to_copy=head_ptr_to_copy->next_node;
        while(head_ptr_to_copy)
        {
            //todo: should we check for allocation failures
            current->next_node=new Node;
            current=current->next_node;
            current->data= head_ptr_to_copy->data;
            current->next_node=NULL;
            head_ptr_to_copy=head_ptr_to_copy->next_node;
        }
    }
    template <class T>
    SortedList<T>& SortedList<T>::operator=(const SortedList<T>& sorted_list_to_assign){
        if(this == &sorted_list_to_assign){
            return *this;
        }
        clearList();
        copyList(sorted_list_to_assign);
    }
    template <class T>
    SortedList<T>::~SortedList(){
        clearList();
    }

    template <class T>
    void SortedList<T>::insert(const T& element){
        Node* new_node = new Node;
        new_node->data = element;
        this->size++;
        if(this->head==NULL){
            new_node->next_node= NULL;
            insertNodeAtStart(new_node);
            return;
        }
        Node* current_ptr = this->head, *previous= NULL;
        while(current_ptr){
            if(current_ptr->data > new_node->data){
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
    int SortedList<T>:: length(){
        return this->size;
    }
}
#endif //SORTEDLIST_H
