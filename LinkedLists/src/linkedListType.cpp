#include "linkedListType.h"

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp; //pointer to dealocate memory occupied by the node
    while(first != NULL) //While there are nodes in the list
    {
        temp = first; //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;
    }
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes delete them
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;
    current = first;
    while(current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);

    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);

    return last->info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);

    return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> &otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if(first != NULL) //If the list isn't empty make it empty
    {
        destroyList();
    }

    if(otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the list to be copied
        count = otherList.count;

        //copy the first node
        first = new nodeType<Type>; //create the node
        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link; //make current point to the next node

        //copy the remainding list
        while(current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type> &otherList)
{
    first = NULL;
    copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type> &otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}
