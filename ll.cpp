#include <iostream>
using namespace std;

class LinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = NULL;
        }
    };

    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // 1. INSERT AT START
    void insertStart(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 2. INSERT AT END
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. INSERT AT MIDDLE (1-based position)
    void insertMiddle(int value, int position)
    {
        if (position == 1)
        {
            insertStart(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. DELETE FROM START
    void deleteStart()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 5. DELETE FROM END
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // 6. DELETE FROM MIDDLE (1-based position)
    void deleteMiddle(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (position == 1)
        {
            deleteStart();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    // 7. BUBBLE SORT (Sorts list in ascending order before Binary Search)
    void bubbleSort()
    {
        if (head == NULL) return;

        for (Node* i = head; i->next != NULL; i = i->next)
        {
            for (Node* j = head; j->next != NULL; j = j->next)
            {
                if (j->data > j->next->data)
                {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
            }
        }
    }

    // 8. LINEAR SEARCH (Works on unsorted or sorted list)
    void linearSearch(int key)
    {
        Node* temp = head;
        int position = 1;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Value found at position " << position << "!" << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value not found!" << endl;
    }

    // 9. BINARY SEARCH (Requires sorted list - Your Sir's exact logic)
    void binarySearch(int key)
    {
        Node* start = head;
        Node* end = NULL;

        while (start != end)
        {
            Node* mid = start;
            Node* temp = start;

            // Find middle node using fast and slow pointers
            while (temp != end && temp->next != end)
            {
                temp = temp->next->next;
                mid = mid->next;
            }

            if (mid->data == key)
            {
                cout << "Value found!" << endl;
                return;
            }
            if (mid->data < key)
            {
                start = mid->next;
            }
            else
            {
                end = mid;
            }
        }
        cout << "Value not found!" << endl;
    }

    // 10. DISPLAY LINKED LIST
    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    int n;
    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insertEnd(value);
    }

    cout << "\nOriginal Linked List: ";
    list.display();

    // Practice Insertions
    list.insertStart(10);
    cout << "After inserting 10 at start: ";
    list.display();

    list.insertMiddle(20, 3);
    cout << "After inserting 20 at position 3: ";
    list.display();

    // Practice Deletions
    list.deleteStart();
    cout << "After deleting from start: ";
    list.display();

    list.deleteMiddle(2);
    cout << "After deleting from position 2: ";
    list.display();

    // Practice Sorting & Searching
    list.bubbleSort();
    cout << "After Bubble Sort: ";
    list.display();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    list.linearSearch(key);
    list.binarySearch(key);

    return 0;
}