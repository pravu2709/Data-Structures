#include<stdio.h> 
#include<stdlib.h> 
   
struct Node  // Node structure definition
{ 
    int data; 
    struct Node *left;
	struct Node *right; 
};    
struct Node *New_Node(int key)  // structure to create a new Node
{ 
    struct Node *Temp =  (struct Node *)malloc(sizeof(struct Node)); 
    Temp->data = key; 
    Temp->left = Temp->right = NULL; 
    return Temp; 
} 
struct Node* insert_data(struct Node* Node, int data)   //Utility function for inserting data into the node in  the Binary Search Tree
{ 
    if (Node == NULL) return New_Node(data);  // returns the new node when the tree is empty
    if (data < Node->data)  // follow recursion when the tree is not null and move down left
        Node->left  = insert_data(Node->left, data); 
    else if (data > Node->data)  // else follow recursion and move right
        Node->right = insert_data(Node->right, data); 
    return Node;  // returning the node pointer
} 
void inorder_traverse(struct Node *Root)  // function to do the inorder traversal in the Binary Search Tree
{ 
    if (Root != NULL) 
    { 
        inorder_traverse(Root->left); 
        printf("%d ", Root->data); 
        inorder_traverse(Root->right); 
    } 
}   

struct Node * Max_Value_Node(struct Node* Node)  // function to find the predecessor
{ 
    struct Node* current = Node;    
    while (current && current->left != NULL)  // going down in loop to the rightmost value
        current = current->left;   
    return current; // return the predecessor
} 

struct Node* delete_node(struct Node* Root, int data)  // function to delete the given node and return the new Root in BST
{ 
    if (Root == NULL) return Root;  // base case for deleting 
    if (data < Root->data)  // checking if the data to be deleted is lesser than the Root
        Root->left = delete_node(Root->left, data);  // When the above condition satisfies, moving towards left since smaller values lie on left  
    else if (data > Root->data) // checking if the data to be deleted is greater than the Root
        Root->right = delete_node(Root->right, data); // When the above condition satisfies, moving towards left since greater values lie on right
    else // when the data to be deleted is same as the Root
    { 
        if (Root->left == NULL) 
        { 
            struct Node *Temp = Root->right; 
            free(Root); 
            return Temp; 
        } 
        else if (Root->right == NULL) 
        { 
            struct Node *Temp = Root->left; 
            free(Root); 
            return Temp; 
        } 
        struct Node* Temp = Max_Value_Node(Root->right); // When the node to be deleted has two child nodes, getting the predecessor in the left subtree
         Root->data = Temp->data;  // Now copy the data from  predecessor
         Root->right = delete_node(Root->right, Temp->data); // Now delete the predecessor
    } 
    return Root; 
}    

int main()    // main function to initiate all the functions 
{ 
    struct Node *Root = NULL; 
    Root = insert_data(Root, 100); 
    insert_data(Root, 50); 
    insert_data(Root, 200); 
    insert_data(Root, 150); 
    insert_data(Root, 300); 
    insert_data(Root, 25); 
    insert_data(Root, 75); 
    insert_data(Root, 12); 
    insert_data(Root, 37); 
    insert_data(Root, 125); 
    insert_data(Root, 175); 
    insert_data(Root, 250); 
    insert_data(Root, 320);
    insert_data(Root, 67); 
    insert_data(Root, 87); 
    insert_data(Root, 94); 
    insert_data(Root, 89); 
    insert_data(Root, 92); 
    insert_data(Root, 88);   
    printf("Inorder Traversal of the Binary Search tree after inserting the given data \n");
    inorder_traverse(Root);     
	printf("\n");
    Root = delete_node(Root, 100); 
    printf("Inorder traversal of the Binary Search Tree after deleting the node \n"); 
    inorder_traverse(Root);    
    return 0; 
} 