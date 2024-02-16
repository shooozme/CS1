#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char letter;
    struct node *next;
} node;
// Returns number of nodes in the linkedList.
int length(node *head) {
    node* current = head;
    int counter = 0;
    while(current != NULL) {
        counter++;
        current = current->next;
    }
    return counter;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head) {
    node* current = head;
    int stringLength = length(head);
    char *array = (char*)malloc(stringLength + 1 * sizeof(char));
    for(int i = 0; i < stringLength; i++) {
        array[i] = current->letter;
        current = current->next;
    }
    array[stringLength] = '\0';
    return array;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
    node* current = *pHead;
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->letter = c;
    if(*pHead ==  NULL) {
        *pHead = newNode;
        return;
    }
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return;
}
// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
    node *current = *pHead;
    node *temp;
    for(int i = 0; i < length(*pHead); i++){
        temp = current->next;
        free(current);
        current = temp;
    }
    *pHead = NULL;
    return;
}
int main(void)
{
    int i, strLen, numInputs;
    node *head = NULL;
    char *str;
    char c;
    FILE *inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}