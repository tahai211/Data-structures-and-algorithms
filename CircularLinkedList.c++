#include <iostream>
using namespace std;
 
struct Node {
    int data;
    struct Node * next;
};
 
typedef struct Node NODE;
 
NODE * CreateNewNode(int data) {
    NODE * newNode = (NODE *) malloc (sizeof(NODE));
    newNode -> data = data;
    return newNode;
}
 
void Display(NODE * tail) {
    NODE * current = tail;
    if (tail != NULL) {
        do {
            current = current -> next;
            cout<<current -> data;
        } while (current != tail);
    }
}
 
int Length(NODE * tail) {
    NODE * current = tail;
    int i = 1;
    if (tail == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != tail) {
            i++;
            current = current -> next;
        }
    }
    return i;
}
 
NODE * InsertAtHead(NODE * tail, int data) {
    NODE * newNode = CreateNewNode(data);
    if (tail == NULL) {
        tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = tail -> next;
        tail -> next = newNode;
    }
    return tail;
}
 
NODE * InsertAtEnd(NODE * tail, int data) {
    // simply insert at head and return the next node pointed by tail
    return InsertAtHead(tail, data) -> next;
}
 
NODE * InsertAtArbitrary(NODE * tail, int data, int location) {
    int len = Length(tail), i;
    if (location < 1 || location > len + 1) {
        cout<<"\nInvalid location to enter data\n";
    } else {
        if (tail == NULL) return InsertAtHead(tail, data);
        NODE * newNode = CreateNewNode(data), * current = tail;
        for (i = 1; i != location; i++) current = current -> next;
        newNode -> next = current -> next;
        current -> next = newNode;
        if (location == len + 1) tail = newNode;
    }
    return tail;
}
 
NODE * DeleteByValue(NODE * tail, int data) {
    NODE * current = tail, * previous;
    if (tail == NULL) return tail;
    else if (tail == tail -> next) {
        if (tail -> data == data) {
            tail = NULL;
            free(current);
        }
        return tail;
    }
    do {
        previous = current;
        current = current -> next;
        if (current -> data == data) {
            previous -> next = current -> next;
            if (current == tail) tail = previous;
            free(current);
            current = previous -> next;
        }
    } while (current != tail);
    return tail;
}
 
NODE * DeleteByLocation(NODE * tail, int location) {
    NODE * current, * previous = tail;
    int len = Length(tail), i;
    if (location < 1 || location > len) {
        cout<<"Invalid Location to delete";
    } else if (len == 1) {
        tail = NULL;
        free(current);
    } else {
        current = tail -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == tail) tail = previous;
        free(current);
    }
 
    return tail;
}
 
NODE * sort(NODE * tail) {
    if (Length(tail) < 2) return tail;
    NODE * ptr1 = tail -> next, * ptr2, * min;
    int temp;
    // selection sort implementation
    while (ptr1 -> next != tail -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != tail -> next) {
            if (min -> data > ptr2 -> data) min = ptr2;
            ptr2 = ptr2 -> next;
        }
        if (min != ptr1) {
            temp = min -> data;
            min -> data = ptr1 -> data;
            ptr1 -> data = temp;
        }
        ptr1 = ptr1 -> next;
    }
    return tail;
}
 
int main() {
    NODE * cll = NULL;
    int option, data, location;
    while (1) {
        Display(cll);
        cout<<"\nlength = "<<Length(cll)<<"\n";
        cout<<"\n\nMENU OF CHOICE\n1. Insert at head\n2. Insert at end\n3. Insert at arbitrary location\n4. Delete by value\n5. Delete by location\n6. Sort\n7. Exit\n";
        cout<<"Your choice: ";
        cin>>option;
 
        if (option == 1) {
            cout<<"Enter data to be inserted: ";
            cin>>data;
            cll = InsertAtHead(cll, data);
        } else if (option == 2) {
            cout<<"Enter data to be inserted at end: ";
            cin>>data;
            cll = InsertAtEnd(cll, data);
        } else if (option == 3) {
            cout<<"Enter data to be inserted: ";
            cin>>data;
            cout<<"Enter location to be inserted into: ";
            cin>>location;
            cll = InsertAtArbitrary(cll, data, location);
        } else if (option == 4) {
            cout<<"Enter value to be deleted: ";
            cin>>data;
            cll = DeleteByValue(cll, data);
        } else if (option == 5) {
            cout<<"Enter location to be deleted: ";
            cin>>location;
            cll = DeleteByLocation(cll, location);
        } else if(option == 6) {
            sort(cll);
        } else if (option == 7) {
            break;
        }
    }
    return 0;
}
 