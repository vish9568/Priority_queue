#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<vector>
#include<bits/stdc++.h>
template<class T>
class MaxHeap
{
public:
    /*
         *constructs an empty Max heap
         *this max heap will hold objects of type T
         *the priority of the objects will be decided
         *by a user defined function.
        */
    MaxHeap<T> (bool (*comp)(T obj1, T obj2));
    //return true if the Max Heap is empty, false otherwise.
    bool isEmpty();
    //used to insert an item in the priority queue.
    void push(T obj);
    //deletes the highest priority item currently in the queue.
    void pop();
    //return the highest priority item currently in the queue.
    T top();
private:
    //return true if obj1 compares less than obj2
    bool (*compare)(T obj1, T obj2);
    //the max heap is implemented using a vector.
    std::vector<T>heap;
    void Insert(int idx);
    void Delete(int idx);

    int leftchild(int i)
    {
        return 2*i+1;
    }
    int rightchild(int i)
    {
        return 2*i+2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

};
template<class T>
MaxHeap<T>::MaxHeap(bool (*comp)(T obj1,T obj2))
{
    this->compare=comp;
}

template<class T>
bool MaxHeap<T>::isEmpty()
{
    return heap.empty();
}

template<class T>
void MaxHeap<T>::push(T obj)
{
    heap.push_back(obj);
    Insert(heap.size()-1);
}

template<class T>
void MaxHeap<T>::pop()
{
    if(!isEmpty())
    {
        std::swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        if(!isEmpty())
            Delete(0);
    }
}
template<class T>
T MaxHeap<T>::top()
{
    if(!isEmpty())
    {
        return heap[0];
    }
    else
    {
        return -1;
    }
}

template<class T>
void MaxHeap<T>::Insert(int idx)
{
    int parentid=parent(idx);
    if(parentid<0)
        return;

    if(compare(heap[parentid],heap[idx]))
    {
        std::swap(heap[parentid],heap[idx]);
        Insert(parentid);
    }
}

template<class T>
void MaxHeap<T>::Delete(int idx)
{
    int largeid=idx;
    int leftchildid=leftchild(idx);
    int rightchildid=rightchild(idx);
    if(leftchildid<heap.size())
    {
        if(compare(heap[largeid],heap[leftchildid]))
        {
            largeid=leftchildid;
        }
    }
    if(rightchildid<heap.size())
    {
        if(compare(heap[largeid],heap[rightchildid]))
        {
            largeid=rightchildid;
        }
    }
    if(largeid !=idx)
    {
        std::swap(heap[largeid],heap[idx]);
        Delete(largeid);
    }
}

#endif // MAXHEAP_H
