#include "MaxHeap.h"
#include<bits/stdc++.h>
using namespace std;

bool comparator(int x, int y)
{
    return x < y;
}
int main()
{
    MaxHeap<int>myHeap(comparator);

    myHeap.push(15);
    myHeap.push(5);
    myHeap.push(25);
    myHeap.push(45);
    myHeap.push(35);

    myHeap.pop();
    myHeap.pop();

    cout<<myHeap.top()<<" ";

}
