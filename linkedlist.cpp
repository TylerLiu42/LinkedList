#include <iostream>


using namespace std;

  
  
struct node
{
        
	int data;
        
	node *next;
    
};

    
    
class list
{
        
	private:
        
	node *head;
        
	node *tail;
        
	public:
        
	list()
	{
        
	head = NULL;
        
	tail = NULL;
        
	}
        
    

void insertBeginning(int value)
    
{
        
	node *temp = new node;
        
	temp -> data = value; 
        
	temp -> next = head;
        
	head = temp;
    
	}  
    
    
void insertEnd(int value)
    //Same as create
{
        
	node *temp = new node;
        
	temp -> data = value;
        
	temp -> next = NULL;
        
	if (head == NULL) //if empty
        
	{
            
	head = temp;
            
	tail = temp;
  
	temp = NULL;                  
	}
        
	else{
 
	tail = head;
		while (tail -> next != NULL)
		{
			tail = tail -> next;
		}           
	tail -> next = temp;
            
	 
        
	}
    
}
    
    
void insertMiddle(int pos, int value)
    
{
        
	node *temp = new node;
        
	node *previous = new node;
        
	node *current = new node;
        
	current = head;
        
        
	for (int i = 0; i < pos; i++)
        
	{
            
		previous = current;
            
		current = current -> next;
        
	}
        
	temp -> data = value;
        
	previous -> next = temp;
        
	temp -> next = current;
        
    
}
    
    
void printList()
    
{
        
	node *temp = new node; 
        
	temp = head;
        
	while (temp != NULL)
        
	{
            
		cout << temp -> data << "  ";
            
		temp = temp -> next;   
        
	}
    
}
    
    
void deleteBeginning()
    
{
        
	node *temp = new node;
        
	temp = head;
        
	head = head -> next;
        
	delete temp; 
    
}
    
    
void deleteEnd()
    
{
        
	node *current = new node;
        
	node *previous = new node;
        
	current = head;
        
	while (current -> next != NULL)
        
	{
            
		previous = current;
            
		current = current -> next;
        
	}
        
	tail = previous;
        
	previous -> next = NULL;
        
	delete current;
    
}
    
    
void deleteMiddle(int pos)
    
{
        
	node *previous = new node;
        
	node *current = new node; 
        
	current = head;
        
	for (int i = 0; i < pos; i++)
        
	{
            
	previous = current;
            
	current = current -> next;
        
	}
        
	previous -> next = current -> next;
        
	delete current;
    
}
 

int listSize()
{
	int size = 0;
	node *temp = new node();
	temp = head;
	while (temp != NULL)
	{
		temp = temp -> next;
		size++;
	}
	cout << "\n";
	cout << "Number of Elements: " << size;
	return size; 
}

void clear(){
        
	int size = 0;
        
	node *temp = new node;
        
	temp = head;
        
	while (temp != NULL)
        
	{
            
		size++;
            
		temp = temp -> next;
        
	}
        
	for (int i = 0; i < size; i++)
        
	{
            
		deleteBeginning();
        
	}
    
}
    
    


void noOfOccurrences(int value){
        
	int count = 0;
        
	node *temp = new node();
        
	temp = head;
        
	while (temp != NULL)
        
	{
            
		if (temp -> data == value)
            
		{
                
			count++;
            
		}
            
	temp = temp -> next;
            
        
	}
        
	cout << "\n";
        
	cout << "The value " << value << " occurs " << count << " time(s)";
    
}
    
    


void getValue (int pos){
        
	node *temp = new node;
        
	temp = head;
        
	for (int i = 0; i < pos; i++)
        
	{
            
		temp = temp -> next;
        
	}
        
	cout << "\n";
        
	cout << "The value at position " << pos << " is: " << temp -> data; 
    
}
    
    


int *toArray(){
        
	int size = listSize();
        
	int myArray[size];
        
	node *temp = new node;
        
	temp = head;
        
	cout << "\n"; 
    
        
	for (int i = 0; i < size; i++)
        
	{
            
		myArray[i] = temp -> data;
            
		temp = temp -> next;
            
		cout << myArray[i] << "  "; 
        
	}
        
        
	return myArray;
    
}
    
    


int indexOf(int value){
        
//This method returns the index of the first occurrence of the specified element in this list, 
        
//or -1 if this list does not contain the element.
        
	int index = 0;
        
	node *temp = new node;
        
	temp = head;
        
	while (temp -> data != value)
        
	{
            
		index++;
            
		temp = temp -> next; 
        
	}
        
	if (index == 0)
        
	{
            
		cout << "\n" << "Value not found"; 
            
		return -1;
        
	}
        
        
	cout << "\n" << "The first occurrence of " << value << " is at index " << index; 
        
	return index; 
    
}
    
    


void set(int pos, int value){
        
	deleteMiddle(pos);
        
	insertMiddle(pos, value);
    
}
    
    



void erase(int value){
        
//Removes elements of a specified value 
        
	node *previous = new node;
        
	node *current = new node;
        
	current = head;
        
	while (current != NULL)
        
	{
            
		if (current -> data == value)
            
		{
                
			if (current == head)
                
			{
                    
				head = current -> next;
                    
				delete current;
                    
				current = head;
                
			}
                
			else {
                    
			previous -> next = current -> next;
                    
			delete current;
                    
			current = previous -> next; 
                
			}
                
            
		}
            
            
		else {
                
		previous = current;
                
		current = current -> next; 
            
		}
            
        
	}
        
//return;
        
    
}
   

};



int main()

{
    
	list obj;
    
	obj.insertBeginning(1);  
 
  	obj.insertBeginning(2);  

	obj.insertBeginning(3);  

	obj.insertBeginning(4);  

	obj.insertBeginning(5);  

	obj.deleteBeginning();
	obj.insertMiddle(2, 100);
	obj.insertEnd(200); 
	obj.set(1,400);
	obj.insertEnd(700);
	obj.insertEnd(700);
	obj.insertEnd(900);
	obj.erase(700);
	obj.printList();
 
	obj.getValue(3);
	obj.noOfOccurrences(400);
	obj.indexOf(100);
	obj.listSize();   
	return 0;

}