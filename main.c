#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;


Node *CN();
Node *createCLL();
void displayCSLL(Node *head);
Node *insertfirst(Node *head,int x);
Node *insertLast(Node *head,int x);
int countNodes(Node *head);
Node *insertBetween(Node *head,int pos,int x);
Node *deletefirst(Node *head);
Node *deleteLast(Node *head);
Node *deleteBetween(Node *head,int pos);


int main()
{
    Node *HEAD=NULL;
    while(1)
    {
        int choice,x,pos;

        printf("\n=============================");
        printf("\n1  :  create Circular linked list");
        printf("\n2  :  Display List");
        printf("\n3  :  Insert First Node in CSLL .");
        printf("\n4  :  Insert Last Node in CSLL .");
        printf("\n5  :  Insert Between Node in CSLL .");
        printf("\n6  :  Delete First Node From SLL .");
        printf("\n7  :  Delete Last Node From SLL .");
        printf("\n8  :  Delete Between Node From SLL .");
        printf("\n9  :  Count Nodes in SLL .");
        printf("\n=============================");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                HEAD = createCLL();
                printf("Sucessfully Created CSLL");
                break;
            case 2:
                displayCSLL(HEAD);
                break;
            case 3:
                printf("Enter Data: ");
                scanf("%d",&x);
                HEAD = insertfirst(HEAD,x);
                printf("Successfully inserted First Element !!! ");
                break;
            case 4:
                printf("Enter Data: ");
                scanf("%d",&x);
                HEAD = insertLast(HEAD,x);
                printf("Successfully Inserted Last Element!!! ");
                break;
            case 5:
                printf("Enter Position: ");
                scanf("%d",&pos);
                printf("Enter Data: ");
                scanf("%d",&x);
                HEAD = insertBetween(HEAD,pos,x);
                printf("Successfully Inserted Between Element!!! ");
                break;
            case 6:
                HEAD = deletefirst(HEAD);
                printf("Successfully Deleted First Element!!! ");
                break;
            case 7:
                HEAD = deleteLast(HEAD);
                printf("Successfully Deleted Last Element!!! ");
                break;
            case 8:
                printf("Enter Position: ");
                scanf("%d",&pos);
                HEAD = deleteBetween(HEAD,pos);
                printf("Successfully Deleted Between Element!!! ");
                break;

            case 9:
                printf("No.of Nodes are %d",countNodes(HEAD));
                break;
        }

    }
}

//head      p    q
//10|2002   20|1002
//1002      2002

Node *createCLL()
{
    int i=1,n,x;
    printf("How many Nodes U Want: ");
    scanf("%d",&n);

    Node *head=NULL;
    head = CN();

    printf("Enter Data: ");
    scanf("%d",&x);

    head->data=x;
    head->next=head;

    Node *p=head;

    while(i<n)//1<3
    {
        Node *q = CN();
        printf("Enter Data: ");
        scanf("%d",&x);

        q->data=x;
        q->next=head;

        p->next=q;
        p=p->next;
        i++;

    }
    return head;
}

Node *CN()
{
    return (Node *)malloc(sizeof(Node ));
}

void displayCSLL(Node *head)
{
    Node *p=head;
    if(p==NULL)
        printf("\nCSLL is Empty!!! ");
    else
    {
        printf("\n");
        while(p->next != head)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("%d\t",p->data);
    }
}

//head                      q
//5|1002  10|2002       20|3002     30|5002
//5005    1002          2002        3002

Node *insertfirst(Node *head,int x)
{

    Node *p = CN();
    p->data = x;

    if(head == NULL)
    {
        p->next = p;
        return p;
    }
    p->next = head;

    Node *q = head;
    while(q->next!=head)
        q=q->next;
    q->next=p;
    head=p;

    return head;
}

//head                              q          p
//5|1002  10|2002       20|3002     30|6002    40|5002
//5002    1002          2002        3002       6002

Node *insertLast(Node *head,int x)
{
    Node *q = head;
    while(q->next!=head)
        q=q->next;

    Node *p = CN();
    p->data = x;
    p->next = head;

    q->next = p;
    return head;
}

//head    p         q
//5|1002  10|7002   15|2002     20|3002     30|6002    40|5002
//5002    1002      7002        2002        3002       6002

Node *insertBetween(Node *head,int pos,int x)
{
    if(head==NULL || pos==1)
        return insertfirst(head,x);
    if(pos == countNodes(head)+1)
        return insertLast(head,x);

    Node *p = head;
    int i = 1;
    while(i<pos-1)//2<2
    {
        p=p->next;
        i++;//2|
    }
    Node *q=CN();
    q->data=x;
    q->next=p->next;
    p->next=q;

    return head;
}

//head p
//5|1002  10|2002       20|3002     30|5002
//5005    1002          2002        3002

int countNodes(Node *head)
{
    int count = 0;
    Node *p=head;
    while(p->next!=head)
    {
        p=p->next;
        count++;
    }
    return count+1;
}

//p        head                      q
//5|1002   10|2002       20|3002     30|1002
//5005     1002          2002        3002


Node *deletefirst(Node *head)
{
    if(head==NULL)
    {
        printf("Empty List..");
        return NULL;
    }
    if(head->next == head)
    {
        free(head);
        return NULL;
    }
    Node *p = head;
    Node *q = head;

    while(q->next!=head)
        q=q->next;

    head = head->next;
    q->next=head;
    free(p);

    return head;
}
//head                   p           q
//5|1002   10|2002       20|5005     30|5005
//5005     1002          2002        3002
Node *deleteLast(Node *head)
{
    if(head==NULL)
    {
        printf("Empty List..");
        return NULL;
    }
    if(head->next == head)
    {
        free(head);
        return NULL;
    }

    Node *q=head;
    while(q->next!=head)
        q=q->next;
    Node *p=head;
    while(p->next!=q)
        p=p->next;
    p->next=head;
    free(q);

    return head;
}

//head     q
//5|1002   10|3002       30|5005
//5005     1002          3002

Node *deleteBetween(Node *head,int pos)
{
    if(head==NULL)
        return head;
    if(pos == 1)
        return deletefirst(head);
    if(pos == countNodes(head))
        return deleteLast;
    Node *p=head;
    int i=1;
    while(i<pos)//3<3
    {
        p=p->next;
        i++;//2|3
    }
    Node *q=head;
    while(q->next!=p)
        q=q->next;
    q->next=p->next;
    free(p);

    return head;
}


