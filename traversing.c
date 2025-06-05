#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};struct Node*head=NULL;


struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data=data;
    newNode->next = NULL;
    return newNode;
};

void insertAtEnd(int data)
{
    struct Node* newNode= createNode(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    struct Node* current=head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void traverseList(struct Node* head)
{
    struct Node* current= head;
    if(current == NULL)
    {
        printf("list is empty\n");
        return;
    }
    printf("linked list: ");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("NULL");
}

void freelist(struct Node* head)
{
    struct Node* current;
    while(head!=NULL)
    {
        current=head;
        head=head->next;
        free(current);
    }
}
int main()
{

    //insertAtEnd(&head,4);
    //insertAtEnd(&head,5);
   // insertAtEnd(&head,8);
    //insertAtEnd(&head,5);
    //insertAtEnd(&head,7);
    //traverseList(head);
    //freelist(head);
    int n,i,data;
    printf("enter the number of data\n");
    scanf("%d",&n);
    printf("enter data\n");
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insertAtEnd( data);
    }
    traverseList(head);
    freelist(head);
    return 0;


    return 0;
}
