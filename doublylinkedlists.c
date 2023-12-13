#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct node {
    int value;
    struct node* link_right;
    struct node* link_left; 
} node;
node* createnode(int data);
void print(node* first);
void swap(node* first, int pos1, int pos2);
int main()
{
    srand(time(NULL));
    node* head = createnode(3);
    node* temp1 = head;
    node* temp2 = NULL;
    for(int i = 0; i < 10; i++)
    {
        temp2 = createnode(rand() % 10);
        temp1->link_right = temp2;
        temp2->link_left = temp1;
        temp1 = temp2;
    }
    print(head);
    swap(head, 6, 3);
    printf("\n");
    print(head);
    return 0; 
}
node* createnode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->value = data;
    temp->link_right = NULL;
    temp->link_left = NULL;
    return temp; 
}
void print(node* first)
{
    node* temp = first;
    printf("[ ");
    while(temp)
    {
        printf("%d ", temp->value);
        temp = temp->link_right;
    }
    printf("]");
}
void swap(node* first, int pos1, int pos2)
{
    if(pos1 < pos2)
    {
        int temp = pos1;
        pos1 = pos2;
        pos2 = temp;
    }
    node* temp1 = first;
    node* temp2 = NULL;
    for(int i = 0; i < pos1; i++)
    {
        temp1 = temp1->link_right;
        if(i == pos2)
        {
            temp2 = temp1;
        }
    }
    node temp3 = *temp1;
    temp1->link_right = temp2->link_right;
    temp1->link_left = temp2->link_left;
    temp2->link_left->link_right = temp1;
    temp2->link_right->link_left = temp1;
    temp2->link_right = temp3.link_right;
    temp2->link_left = temp3.link_left;
    temp3.link_left->link_right = temp2;
    temp3.link_right->link_left = temp2;
}