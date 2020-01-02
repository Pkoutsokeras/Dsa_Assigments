#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <fstream>
using namespace std;

/* Struct for Double Linked list */
struct node{
    string code;
    string name;
    int year;
    string direction;
    double grade;
    struct node* next;
    struct node* prev;
};
/* Insert Node at Back */
void insert_back(struct node** head, struct node * a_student){

  a_student->next = (*head);
    a_student->prev = NULL;
 
    if ((*head) != NULL)
        (*head)->prev = a_student;
 
 
    (*head) = a_student;
 
    }

/* Erase node*/
void erase (struct node** head,node* del){

    if(*head == NULL || del == NULL){
        return;
    }

    if(*head == del){
        *head = del -> next;
    }

    if(del -> next !=NULL){
        del -> next -> prev = del -> prev;
    }

    if(del-> prev !=NULL){
        del -> prev -> next = del -> next;
    }
}

/* Print node */
void print_forward(node* node){
    while(node !=NULL){
        cout << "Code :" << node->code << "Name:" << node -> name << "Year :" << node -> year << "Direction : " << node -> direction << "Grade : " << node -> grade << endl; 
        node = node -> next;
    }
}

// /* Print node at reverse */
// void print_reverse(struct node** head){
//     struct node* node= *head;

//     while(node -> next !=NULL){
//         node = node -> next;
//     }

//     while(node != *head){
//         cout << node -> data << " ";
//     }

//    cout << "Code : " << node->code << "Name : " << node -> name << "Year :" << node -> year << "Direction" << node -> direction << "Grade : " << node -> grade << endl; 
// }
int main(){
    struct node *head;
   list<node>a_list;
   fstream fin;
   /* Read the File Line by line */
   fin.open("students.txt",ios::in);
   string line;
   while(getline(fin,line)){
       istringstream ss(line);
       node a_student;  
    ss >> a_student.code;
    ss >> a_student.name;
    ss >> a_student.year;
    ss >> a_student.direction;
    ss >> a_student.grade;
     print_forward(&a_student);
     insert_back(&head,*a_student);
      print_forward(&a_student);
    a_list.push_back(a_student);
}
     system("pause");
}
