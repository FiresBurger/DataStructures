#include <iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

int main()
{
    nodeType *first, *last, *newNode, *current;
    int num;
    first = NULL;
    last = NULL;
    string addAnother = "y";

    while(addAnother == "y")
    {
        cout << "Which number would you like to add? ";
        cin >> num;
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = NULL;

        if(first == NULL)
        {
            first = newNode;
            last = newNode;
        }else
        {
            last->link = newNode;
            last = newNode;
        }

        cout << "Would you like to add another number? ";
        cin >> addAnother;
    }

    current = first;
    cout << "Your list is: " << endl;

    while(current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }

    return 0;
}
