
/* C++ program for to create a linked list and sort the list using Insertion sort*/
#include <iostream>

using namespace std;

struct node //Structure for the Node of the Linked List
{ 
    public:
    int data; 
    struct node* next; 
};

void print_linked_List(struct node *head) //Funtion to print the list obtained 
{ 
    struct node *tmp = head; 
    while(tmp != NULL) 
    { 
        printf("%d  ", tmp->data); 
        tmp = tmp->next; 
    } 
} 

void add_node(struct node** ref_head, int new_data_node)  //Function to insert the values into the linked list
{ 
    struct node* newnode = new node;  // to allocate a node 
    newnode->data  = new_data_node;   // to insert the data into the new node
    newnode->next = (*ref_head);      // link  the new node to the existing list
    (*ref_head)    = newnode;         // moving the head to point to the new node
} 

/*this function inserts the node into sorted linked list*/
void sorted_list_insert(struct node**, struct node*);
 
/*Function to sort the linked list using the insertion sort algorithm*/ 
void Insertion_Sorting(struct node **ref_head) 
{ 
    struct node *sorted = NULL; 
  
    struct node *present = *ref_head; 
    while (present != NULL) 
    { 
        struct node *next = present->next; // storing the next for next round of iteration    
        sorted_list_insert(&sorted, present);  // inserting the present value into the sorted list
        present = next;  // updating the present value 
    } 
    *ref_head = sorted; 
} 

/*function to insert new node into the linked list... here the function has one of the inputs as 
  pointer to ref_head because this can change the head of the list*/
void sorted_list_insert(struct node** ref_head, struct node* newnode) 
{ 
    struct node* present;
    if (*ref_head == NULL || (*ref_head)->data >= newnode->data)  
    { 
        newnode->next = *ref_head; 
        *ref_head = newnode;    // linking the node to the existing linked list
    } 
    else
    { 
        present = *ref_head; 
        while (present->next!=NULL && present->next->data < newnode->data) 
        { 
            present = present->next; 
        } 
        newnode->next = present->next; 
        present->next = newnode; 
    } 
} 
  
int main()  //Main function which calls all the above functions and performs the task 
{ 
    struct node *c = NULL; 
    add_node(&c, 23); 	
    add_node(&c, 88); 
    add_node(&c, 1); 
    add_node(&c, 5); 
    add_node(&c, 99);
    add_node(&c, 8); 
    add_node(&c, 68); 
    add_node(&c, 14); 
    add_node(&c, 33); 
    add_node(&c, 7);
    add_node(&c, 25); 
    add_node(&c, 80); 
    add_node(&c, 64); 
    add_node(&c, 63); 
    add_node(&c, 90); 
  
    cout<<"Linked List before sorting \n"; 
    print_linked_List(c); 
  
    Insertion_Sorting(&c); 
  
    cout<<"\n Linked List after sorting using Insertion Sorting \n"; 
    print_linked_List(c); 
  
    return 0; 
} 
