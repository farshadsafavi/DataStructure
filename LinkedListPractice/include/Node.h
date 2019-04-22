#ifndef NODE_H
#define NODE_H


class Node
{

    public:
        int value;
        Node *next;
        Node(int value, Node *n){
            this->value = value;
            this->next = n;
        }
};

#endif // NODE_H
