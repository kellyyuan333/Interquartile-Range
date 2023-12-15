#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

//I worked on this with Arisha Haque (who is my programming partner)

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
    Node* fast = head;
    Node* median = head;
    Node* first = head;
    Node* third = head; 
    Node* prevfirst = head;
    Node* prevthird = head;  
    int count1 = 0;  
    int count2 = 0; 
    float datafirst = 0; 
    float datathird = 0; 
    bool countMedian = false;
    bool countFirst = false; 
    bool countfaster = false; 
    bool countThird = false; 
    while (fast->next != nullptr)
    {
        
        fast = fast->next;
        count1 = count1 + 1; 
        count2 = count2 + 1; 
        
        if (countMedian)
        {
            median = median->next;
             
            if (countFirst) {
                prevfirst = first; 
                first = first->next; 
            }
            
            countFirst = !countFirst; 
                
        }
        countMedian = !countMedian;
        if (countFirst == false) { 
            countThird = !countThird; 
        }
        if (countThird) { 
            prevthird = third; 
            third = third->next; 
        }
        
        
    }
    float division = (count1 + 1)/ 2; 
     
    if ((int)(floor(division)) % 2 == 0 && ((count1 + 1) % 2 == 0)) { 
             
            float data1 = first->value; 
            float data2 = first->next->value; 
            datafirst = (data1 + data2)/2; 
            
            float data3 = third->value; 
            float data4 = prevthird->value; 
            datathird = (data3 + data4) / 2; 
            

    }
    else if ((int)(floor(division)) % 2 == 0 && ((count1 + 1) % 2 == 1)) { 
        float data1 = first->value; 
        float data2 = prevfirst->value; 
        datafirst = (data1 + data2)/2; 

        float data3 = third->value; 
        float data4 = third->next->value; 
        datathird = (data3 + data4) / 2;
        
    }
    else { 
        datafirst = first->value; 
        datathird = third->value; 
    }
     
    return datathird - datafirst;   
}