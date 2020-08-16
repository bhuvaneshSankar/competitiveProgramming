#include <bits/stdc++.h>
#include <vector>

using namespace std;

void printHeap(vector<int> heap)
{
    for (int val : heap)
    {
        cout << val << " ";
    }
    cout << "\n";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
vector<int> buildHeap(vector<int> arr)
{
    int n = arr.size();
    int nextEmpty = 0;
    int parent;
    vector<int> heap(n);
    for (int i = 0; i < n; i++)
    {
        heap[nextEmpty] = arr[i];
        int pos = nextEmpty;
        parent = pos & 1 ? (pos - 1) / 2 : (pos - 2) / 2;
        while (parent > 0)
        {
            parent = pos & 1 ? (pos - 1) / 2 : (pos - 2) / 2;
            if (heap[parent] > heap[pos])
            {
                swap(heap[parent], heap[pos]);
            }
            pos = parent;
        }
        nextEmpty++;
    }
    return heap;
}
int pop(vector<int> &heap)
{
    int n = heap.size();
    int front = heap[0];
    heap[0] = heap[n - 1];
    heap[n - 1] = -1;
    vector<int>::iterator it = heap.begin() + (n - 1);
    heap.erase(it);
    int pos = 0;
    n = n - 1;
    for (; (pos * 2 + 2) < n;)
    {
        int c1 = (pos * 2) + 1;
        int c2 = (pos * 2) + 2;

        if (heap[pos] > heap[c1] && heap[pos] > heap[c2])
        {
            if (heap[c1] < heap[c2])
            {
                swap(heap[c1], heap[pos]);
                pos = c1;
            }
            else
            {
                swap(heap[c2], heap[pos]);
                pos = c2;
            }
        }
        else if (heap[pos] > heap[c1])
        {
            swap(heap[c1], heap[pos]);
            pos = c1;
        }
        else if (heap[pos] > heap[c2])
        {
            swap(heap[c2], heap[pos]);
            pos = c2;
        }
        else
        {
            break;
        }
    }
    return front;
}

void insertHeap(vector<int> &heap, int newVal)
{
    int n = heap.size();
    heap.resize(n + 1, newVal);
    int pos = n;
    int parentIndex = (pos - 1) / 2;
    while (parentIndex >= 0 && heap[parentIndex] >= heap[pos])
    {
        swap(heap[parentIndex], heap[pos]);
        if (parentIndex == 0)
        {
            break;
        }
        pos = parentIndex;
        parentIndex = (pos - 1) / 2;
    }
}
int main()
{
    vector<int> arr = {9, 7, 4, 15, 20, 13, 3, 10, 9, 8};
    vector<int> heap = buildHeap(arr);
    printHeap(heap);
    cout << "top value " << pop(heap) << endl;
    printHeap(heap);
    cout << "top value " << pop(heap) << endl;
    printHeap(heap);
    cout << "top value " << pop(heap) << endl;
    printHeap(heap);
    cout << "top value " << pop(heap) << endl;
    printHeap(heap);
    cout << "insert value 7\n";
    insertHeap(heap, 7);
    printHeap(heap);
    cout << "insert value 11\n";
    insertHeap(heap, 11);
    printHeap(heap);
    cout << "top value " << pop(heap) << "\n";
    printHeap(heap);
    cout << "top value " << pop(heap) << "\n";
    printHeap(heap);
    for (int i = 0; i < 6; i++)
    {
        cout << "top value " << pop(heap) << "\n";
        printHeap(heap);
    }

    // vector<int> arr = {10, 11, 13, 20, 15};
    // vector<int> heap = buildHeap(arr);
    // //   cout << "top value " << pop(heap) << "\n";
    // int topValue = pop(heap);
    // cout << " top value = " << topValue << "\n";
    // printHeap(heap);
}