
/*
 * Course: COEN 2220 - Programming 2
 * Name: Joewel Maldonado
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [Date]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Part C: Node and class data members =====

    struct Node
    {
        string groupCode;
        int meetingRoom;
        Node *next;
    };

    Node *head;
    int groupCount;

public:
    // ===== Part C: Constructor =====

    StudyGroupList()
    {
        head = nullptr;
        groupCount = 0;
    }

    // ===== Resolve these TODOs later (Part D) =====

    
    // ===== Part D: Add and display study groups =====

    void addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        groupCount++;
    }

    void displayGroups() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Study group: " << currentNode->groupCode
                 << " | Room: " << currentNode->meetingRoom << endl;

            currentNode = currentNode->next;
        }
    }

    int size() const
    {
        return groupCount;
    }


    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    // TODO (Part E): Display every stored group and print the result of size().
    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.

    return 0;
}
