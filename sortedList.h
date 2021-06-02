#ifndef SORTEDLIST_H
#define SORTEDLIST_H

typedef int T;
template <class T>
class Node{
public:
    T* data;
    T* next_node;
};

template <class T>
class SortedList{
private:
    Node<T>* head;
    int size;
    void clearList();
    void copyList(const SortedList<T>& sorted_list_to_copy);
public:
    SortedList<T>();
    SortedList<T>(const SortedList<T>& sorted_list_to_copy);
    ~SortedList<T>();
    SortedList& operator=(const SortedList<T>& sorted_list_to_assign);


};
template <class T>
SortedList<T>::SortedList():head(NULL),size(0)
{}
template <class T>
SortedList<T>::SortedList(const SortedList<T>& sorted_list_to_copy):size(sorted_list_to_copy.size){
    copyList(sorted_list_to_copy);
}

template <class T>
void SortedList<T>::clearList() {
    while(head){
        Node<T> to_delete = head ;
        head = head->next_node;
        delete to_delete;
    }
}

template <class T>
void SortedList<T>::copyList(const SortedList<T>& sorted_list_to_copy) {
    if(!sorted_list_to_copy.head){
        return;
    }
    Node<T> head_ptr_to_copy = sorted_list_to_copy.head;
    this->head=new Node<T>;
    this->head->data=head_ptr_to_copy.data;
    Node<T> current = this->head;
    head_ptr_to_copy=head_ptr_to_copy.next_node;
    while(head_ptr_to_copy)
    {
        current.next_node=new Node<T>;
        current=current.next_node;
        current->data= head_ptr_to_copy->data;
        current->next=NULL;
        head_ptr_to_copy=head_ptr_to_copy.next_node;
    }
}
template <class T>
SortedList<T>& SortedList<T>::operator=(const SortedList<T>& sorted_list_to_assign){
    if(this == &sorted_list_to_assign){
        return *this;
    }
    copyList(sorted_list_to_assign);
}
template <class T>
SortedList<T>::~SortedList(){
    clearList();
}
#endif //SORTEDLIST_H
