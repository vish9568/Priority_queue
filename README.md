# Priority_queue
Implementation of a priority queue using a max heap. To use the priority queue:<br>

1. Check "Example.cpp" file <br>
Note: <br>
you need to define a function comparator that accepts two objects of type myDataType and returns true if 1st compares less than 2nd object and false otherwise.
the highest priority object(does not compare less than any other object in the heap) is the topmost item in the heap.<br>

The following functionalities are provided:<br>

push(T obj) : inserts in the queue the item obj.<br>
pop() : deletes the highest priority item from the queue.<br>
top() : returns the highest priority item present in the queue and returns -1 if queue is empty <br>
isEmpty() : return 1 if there is no element in the queue. 0 otherwise.<br>
