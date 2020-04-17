// This class specifies the member to implement the basic properties of a linked list.
// This is an abstract class.
// We can not instantiate an object of this class
// Recognition: Build with the help from D.S Maliks book Datastructures using c++ second edition

#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <linkedListIterator.h>
#include <cassert>
#include <iostream>

using namespace std;

template <class Type>
class linkedListType
{
    public:
        const linkedListType<Type>& operator=(const linkedListType<Type>&);
        //overload the assignment operator
        void initializeList();
        //initialize the list to an empty state
        //Postcondition: first = NULL, last == NULL, count = 0;
        bool isEmptyList() const;
        //Function to determine whether a list is empty
        //Postcondition: Return true if the list is empty otherwise returns false
        void print() const;
        //Function to output data contained in each node
        //Postcondition: the value of count is returned
        int length() const;
        //Returns the number of nodes in the list
        //Postcondition: the value of count is returned
        void destroyList();
        //Delete all nodes from the list
        //Postcondition: first = NULL, last = NULL, count = 0;
        Type front() const;
        //Returns the first element of the list
        //Postcondition: If the list is empty the program terminates, otherwise the first item in the list is returned
        Type back() const;
        //Returns last element in the list
        //Postcondition: if the list is empty the program terminates, otherwise it returns the last item in the list
        virtual bool search(const Type &searchItem) const = 0;
        //Function to determine if an element is in the list
        //Postcondition: Returns true if search item is in the list, otherwise returns false
        virtual void insertFirst(const Type &newItem) = 0;
        //Function to insert item at the the beginning of the list
        //Postcondition: first points to the new list, last points to the last node in the list, and count is incremented by one
        virtual void insertLast(const Type &newItem) = 0;
        //Function to insert item at the end of the list
        //Postcondition: First points to the new list, newItem is inserted at the end of the list, last points to the last node in the list, and count is incremented by 1
        virtual void deleteNode(const Type &deleteItem) = 0;
        //delete deleteItem from the list
        //Postcondition: If found, the node containing deleteItem is deleted from the list. first points to the first node, last points to the last node of the updated list and count is decremented by 1
        linkedListIterator<Type> begin();
        //Function to return an iterator at the begining of the linked list
        //Postcondition: Returns an iterator such that current is set to first
        linkedListIterator<Type> end();
        //Funtion to return an iterator one element past the las element of the linked list
        //Postcondition: Returns an iterator such that current is set to NULL
        linkedListType();
        //default constructor
        //Initializes the list to an empty state
        //Postcondition: first = NULL, last = NULL, count = 0;
        linkedListType(const linkedListType<Type> &otherlist);
        //Copy constructor
        ~linkedListType();
        //destructor
        //Deletes all the nodes from the list
        //Postcondition: The list object is destroyed

    protected:
        int count; //stores the number of list items
        nodeType<Type> *first; //pointer to the first node in the list
        nodeType<Type> *last; //pointer to the last node in the list

    private:
        void copyList(const linkedListType<Type> &otherList);
        //Function to make a copy of otherList;
        //Postcondition: A copy of otherList is created and assigned to this list
};

#endif // LINKEDLISTTYPE_H
