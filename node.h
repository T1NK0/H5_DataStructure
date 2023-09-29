#ifndef NODE_H
#define NODE_H

struct Node {
    int roll;
    char name[100];
    int age;
    struct Node* next;
};

typedef struct Node node;

#endif // NODE_H