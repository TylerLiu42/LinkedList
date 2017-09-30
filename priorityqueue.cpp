#include <iostream>
#include <string> 
#include <climits>
using namespace std;

struct node
{
    int priority;
    string data;
    node *next;
};

class priorityQueue
{
    private:
    node *head;
    node *tail;
    public:
    priorityQueue()
    {
        head = NULL;
        tail = NULL;
    }
    
    void insert (string task, int priority)
    {
        node *temp = new node;
        node *temp2 = new node;
        temp -> data = task;
        temp -> priority = priority;
        if (head == NULL || priority < head -> priority)
        {
            temp -> next = head;
            head = temp;
        }
        else
        {
            temp2 = head;
            while (temp2 -> next != NULL && temp2 -> next -> priority <= priority)
            {
                temp2 = temp2 -> next; 
            }
            temp -> next = temp2 -> next;
            temp2 -> next = temp;
        }
    }
    
    void pop()
    {
        if (head == NULL)
        {
            cout << "Empty Queue!";
        }
        node *temp = new node;
        temp = head;
        head = head -> next;
        delete temp; 
    }
    
    void printQueue()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp -> data << "(Priority: " << temp -> priority << ")" << "\n";
            temp = temp -> next;
        }
    }
    
    int getHighestPriority()
    {
        int highestSoFar = INT_MAX; 
        node *temp = new node;
        temp = head;
        while (temp -> next != NULL)
        {
            if (temp -> priority < highestSoFar)
            {
                highestSoFar = temp -> priority;
            }
            temp = temp -> next;
        }
        return highestSoFar;
    }
    
    void printHighestPriority()
    {
        int topPriority = getHighestPriority();
        node *temp = new node;
        temp = head;
        while (temp -> next != NULL)
        {
            if (temp -> priority == topPriority)
            {
                cout << temp -> data << "\t"; 
            }
            temp = temp -> next; 
        }
    }
    
};


int main() 
{
    priorityQueue obj;
    obj.insert("Wash Dishes", 1);
    obj.insert("Study", 1);
    obj.insert("Walk dog", 2);
    obj.insert("Use coupons", 3);
    obj.insert("Watch GOT", 4); 
    obj.pop();
    obj.printQueue();
    cout << "Highest Priority: "; 
    obj.getHighestPriority();
    obj.printHighestPriority();
}

