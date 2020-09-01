/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reorder(ListNode *&curr1, ListNode *curr2, int j, int len)
{
    if (curr2 == NULL)
        return;
    reorder(curr1, curr2->next, j + 1, len);
    if ((len % 2 == 0 && j > len / 2) || (len % 2 != 0 && j - 2 >= len / 2))
    {
        ListNode *temp = curr1->next;
        curr1->next = curr2;
        curr2->next = temp;
        curr1 = temp;
    }

    if ((j - 1 == len / 2))
    {
        curr2->next = NULL;
    }
}
void reorderList(ListNode *head)
{
    int len = 0;
    ListNode *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        len++;
    }
    reorder(head, head, 1, len);
}