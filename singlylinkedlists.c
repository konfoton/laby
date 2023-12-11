#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node {
    int value;
    struct node* link; 
} node;
node* create_new_node(int data);
void print_list(node* first);
void insert_after(int position, int value, node* head);
void delete_after(int position, node* head);
int main()
{
 node* head = create_new_node(0);
 node* temp1 = head;
 node* temp2 = NULL;
 for(int i = 1; i < 10; i++)
 {
    temp2 = create_new_node(i);
    temp1->link = temp2;
    temp1 = temp2;

 }
 insert_after(3, 69, head);
 delete_after(6, head);
 print_list(head);
 return 0;
}
node* create_new_node(int data)
{
    node* result = (node*)malloc(sizeof(node));
    result->value = data;
    result->link = NULL;
    return result;
}
void print_list(node* first)
{
    printf("[ ");
    while(first)
    {
        printf("%d ", first->value);
        first = first->link;
    }
    printf("]");
}
void insert_after(int position, int data, node* head)
{
    node* temp1 = head;
    node* temp2 = NULL;
    while(position > 1)
    {
        temp1 = temp1->link;
        position--;
    }
    temp2 = temp1->link;
    temp1->link = create_new_node(data);
    temp1->link->link = temp2;

}
void delete_after(int position, node* head)
{
    node* temp1 = head;
    node* temp2 = NULL;
    while(position > 1)
    {
        temp1 = temp1->link;
        position--;
    }
    temp2 = temp1->link->link;
    free(temp1->link);
    temp1->link = temp2;
}