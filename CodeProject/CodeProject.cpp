#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* newListFromArr(int arr[], int len)
{
    if (len==0 || arr==NULL) return NULL;

    struct ListNode *pHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pHead->val = arr[0];

    struct ListNode *pCur = pHead;
    int i;
    for (i=1;i<len;i++,pCur=pCur->next)
    {
        pCur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        pCur->next->val = arr[i];
    }
    pCur->next = NULL;

    return pHead;
}

void printList( struct ListNode *pHead)
{
    struct ListNode *pCur = pHead;
    while (pCur!=NULL) {
        printf("%d ",pCur->val);
        pCur=pCur->next;
    }
    printf("\n");
}

/*

void addFront(struct ListNode **ppHead, struct ListNode *pNode)
{
    pNode->next = *ppHead;
    *ppHead = pNode;
}

struct ListNode* getTail(struct ListNode* pHead)
{
    if (pHead==NULL)
        return NULL;

    struct ListNode *pCur=pHead;
    while (pCur->next !=NULL)
        pCur=pCur->next;
    return pCur;
}

struct ListNode* reverseList(struct ListNode *head)
{
    if (head==NULL) return NULL;
    struct ListNode *pLast=head, *pCur=head->next, *pNext=NULL;
    head->next=NULL;

    while (pCur!=NULL)
    {
        pNext = pCur->next;
        pCur->next = pLast;

        pLast = pCur;
        pCur = pNext;
    }
    return pLast;
}
*/

bool hasCycle(struct ListNode *head)
{
    if (head==NULL)
        return false;

    struct ListNode *pCur = head->next;
    struct ListNode *pNext;

    while( pCur!=NULL )
    {
        if (pCur==head)
            return true;

        pNext = pCur->next;
        pCur->next = head;
        pCur = pNext;
    }

    return false;
}

int main(){

    int arr[]={1,2,3,4};
    struct ListNode *head = newListFromArr(arr, sizeof(arr)/sizeof(int) );
	printList(head);

	head->next->next->next->next = head;

	printf("cycle=%d\n", hasCycle(head) );
	//printList(head);

    return 0;

}

/*
int main(){

    int arr[]={1,2,3,4,3,2};
    struct ListNode *head = newListFromArr(arr, sizeof(arr)/sizeof(int) );

    printList(head);
    printf("%d\n", isPalindrome(head) );

    return 0;

}
*/
