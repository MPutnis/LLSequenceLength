#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node *next;
    Node(int data) {
        info = data;
        next = NULL;
    }
    // Node() {
    //     next = NULL;
    // }
};

void pushBack(Node* &head, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
//function to find the length of a sequence that starts with 1
int seqLen(Node* listHead1, Node* listHead2) {
    int i = 0; // base counter
    do
    {
        int timesFound = 0; //counter for how many times i is found in the lists
        Node* temp1 = listHead1;
        Node* temp2 = listHead2;
        while( temp1 != NULL)
        {
            //search for i+1, if found increment timesFound
            if(temp1->info == i+1) 
            {
                timesFound++;
            }
            temp1 = temp1->next;
        }
        while( temp2 != NULL)
        {
            if(temp2->info == i+1)
            {
                timesFound++;
            }
            temp2 = temp2->next;
        }
        // if i+1 is found only once, check next value
        if( timesFound == 1)
        {
            //cout << i << endl;
            i++;
        }
        // if i+1 is found more than once, return i+1
        else if (timesFound > 1)
        {
            return i+1;
        }
        // if i+1 is not found at all, return i
        else
        {
            return i;
        }
    } while (i);
    //return i;
}
void deleteList(Node* &head) {
    Node *temp = head;
    while (head != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}
int main()
{
    Node* listHead1 = NULL;
    pushBack(listHead1, 4);
    pushBack(listHead1, 3);
    pushBack(listHead1, 2);
    pushBack(listHead1, 1);
    pushBack(listHead1, 1);

    Node* listHead2 = NULL;
    pushBack(listHead2, 3);
    pushBack(listHead2, 4);
    pushBack(listHead2, 2);

    printList(listHead1);
    printList(listHead2);
    cout << seqLen(listHead1, listHead2) << endl;

    deleteList(listHead1);
    deleteList(listHead2);
    return 0;
}