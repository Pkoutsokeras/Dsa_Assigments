#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;

/* Double Linked list */
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

/* Insert node at front  */
void insert_front(struct node** head, int new_data){
    struct node* newnode= new node;
    newnode -> data = new_data; //data assign
    newnode ->next = (*head);
    newnode -> prev = NULL;
    if((*head) != NULL){
        (*head) -> prev = newnode;
    }
    (*head)=newnode;
}
void insert_back(struct node** head,int new_data){
    struct node* newnode = new node;
    struct node* last = *head;
    newnode -> data = new_data;
    newnode -> next = NULL;
    if(*head == NULL){
        newnode -> prev = NULL;
        *head = newnode;
        return;
    }


}
