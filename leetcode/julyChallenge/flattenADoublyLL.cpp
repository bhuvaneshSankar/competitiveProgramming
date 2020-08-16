#include <bits/stdc++.h>
#include <stack>
using namespace std;
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

//recursive approach
Node *flattenll(Node *node, Node *nextNode)
{
    while (node->child != NULL || node->next != NULL)
    {
        if (node->child != NULL)
        {
            Node *temp = node->next;
            node->next = node->child;
            node->child->prev = node;
            Node *prevNode = flattenll(node->child, temp);
            node->child = NULL;
            if (temp != NULL)
                temp->prev = prevNode;
            else
                break;
            node = temp;
            continue;
        }
        node = node->next;
    }
    if (node->next == NULL)
    {
        node->next = nextNode;
    }
    return node;
}

//non recursive approach
Node *flatten(Node *head)
{
    if (head == NULL)
        return head;
    Node *node = head;
    stack<Node *> s;
    while (node != NULL)
    {
        if (node->child != NULL)
        {
            s.push(node->next);
            node->next = node->child;
            node->child = NULL;
            node->next->prev = node;
        }
        while (node->next == NULL && !s.empty())
        {
            Node *temp = s.top();
            s.pop();
            node->next = temp;
            if (temp != NULL)
            {
                temp->prev = node;
            }
            else
            {
                continue;
            }
            node = temp;
        }
        node = node->next;
    }
    return head;
}