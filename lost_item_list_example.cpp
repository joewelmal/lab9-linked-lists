/*
 * Course: COEN 2220 - Programming 2
 * Name: [Joewel Maldonado]
 * Lab: Lab 9 - Linked Lists
 * Description: Guided example - a linked list of lost-item codes
 * Due date: [October 17 2026]
 */
 
#include <iostream>
#include <string>
using namespace std;

class LostItemList
{
private:
    struct Node
    {
        string itemCode; // Store one lost-item code.
        Node *next;      // Store the address of the next node.
    };

    Node *head;          // Store the first node address or nullptr.

public:
    LostItemList()
    {
        head = nullptr;  // A new list begins with no nodes.
    }

    bool isEmpty() const
    {
        return head == nullptr; // No first node means the list is empty.
    }

    // --- STEP B2: Add one item at the end ---
    
    void addItem(const string& newItemCode)
    {
        Node *newNode = new Node;
        newNode->itemCode = newItemCode;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }
    

    // --- STEP B3: Traverse and search the list ---
    
    void display() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Lost item: " << currentNode->itemCode << endl;
            currentNode = currentNode->next;
        }
    }

    bool contains(const string& targetItemCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->itemCode == targetItemCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
    
};

int main()
{
    cout << boolalpha; // Print bool results as true or false.

    LostItemList lostItems;

    cout << "List starts empty: " << lostItems.isEmpty() << endl;

    // --- STEP B2: Add dummy lost-item codes ---
    
    lostItems.addItem("LF-104");
    lostItems.addItem("LF-215");
    lostItems.addItem("LF-330");

    cout << "List starts empty after additions: "
         << lostItems.isEmpty() << endl;
    

    // --- STEP B3: Display and search stored codes ---
    
    lostItems.display();
    cout << "Contains LF-215: " << lostItems.contains("LF-215") << endl;
    cout << "Contains LF-999: " << lostItems.contains("LF-999") << endl;
    

    return 0;
}


/*
 * B4 — Appending LF-330
 * Answer:
 * head still points to LF-104, and currentNode points to LF-215.
 * The new link connects LF-215 to LF-330.
 * head does not change because it must keep pointing to
 * the first node.
 *
 * B5 — Traversal and linear search
 * Answer:
 * Both functions move through the list using currentNode->next.
 * display prints each item, while contains searches for a match.
 * contains can stop early when it finds the item.
 */
