// This class specifies the member to implement an iterator to a linked list
// Recognition: Build with the help from D.S Maliks book Datastructures using c++ second edition


#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include <cstddef>

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
    public:
        linkedListIterator();
        //Default Constructor
        //Postcondition: current = NULL
        linkedListIterator(nodeType<Type> *ptr);
        //Constructor with a parameter
        //Postcondition: current = ptr;
        Type operator*();
        //Function to overload the dereferencing operator *
        //Postcondition: returns the info contained in the node
        linkedListIterator<Type> operator ++ ();
        //Overload the preincrement operator
        //Postcondition: The iterator is advanced to the next node
        bool operator == (const linkedListIterator<Type>& right) const;
        //Overload the equality operator
        //Postcondition: Returns true if this iterator is equal to the iterator specified by right, otherwise returns false
        bool operator != (const linkedListIterator<Type>& right) const;
        //Overload the not equal to operator
        //Postcondition: Return true if this iterator is not equal to the iterator specified by right, otherwise returns false
    private:
        nodeType<Type> *current; //pointer to point to the current node in the linked list
};

#endif // LINKEDLISTITERATOR_H
