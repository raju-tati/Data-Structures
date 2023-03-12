#include<stdio.h>

struct node {
    int data;
    struct node* link;
};

/// @brief add at the end of the list
/// @param q list q
/// @param num number to add
append(struct node **q, int num) {
    struct node *temp, *r;
    temp = *q;

    if(*q == NULL) {
        temp = malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    } else {
        temp = *q;
        while(temp->link != NULL) {
            temp = temp->link;
        }

        r = malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

addAtBegin(struct node **q, int num) {
    struct node *temp;
    temp = malloc(sizeof( struct node));
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

addAfter(struct node *q, int loc, int num) {
    struct node *temp, *r;
    int i;
    temp = q;

    for(i = 0; i< loc; i++) {
        temp = temp->link;
        if(temp == NULL) {
            printf("\n there are less than %d elements in list", loc);
            return;
        }
    }

    r = malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

display(struct node *q) {
    printf("\n");

    while(q != NULL) {
        printf("%d", q->data);
        q = q->link;
    }
}

count(struct node *q) {
    int c = 0;
    while( q != NULL) {
        q = q->link;
        c++;
    } 
    return c;
}

delete (struct node **q, int num) {
    struct node *old, *temp;
    temp = *q;

    while(temp != NULL) {
        if(temp->data == num) {
            if(temp == *q) {
                *q = temp->link;
                free(temp);
                return;
            }
            else {
                old->link = temp->link;
                free(temp);
                return;
            }
        }
        else {
            old = temp;
            temp = temp->link;
        }
    }
    printf("\nElement %d not found", num);
}

int main() {
    struct node* p;
    p = NULL;

    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);

    display(p);

    addAtBegin(&p, 999);
    addAtBegin(&p, 888);
    addAtBegin(&p, 777);

    display(p);

    addAfter(p, 7, 21);
    addAfter(p, 2, 22);
    addAfter(p, 3, 23);

    display(p);

    delete(&p, 888);
    delete(&p, 1);
    delete(&p, 22);

    display(p);
}
