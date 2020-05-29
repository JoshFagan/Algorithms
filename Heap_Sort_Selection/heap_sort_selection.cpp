/*******************************************\
| Joshua Fagan                              |
| COSC581, HW4                              |
| Due 2/3/2015                              |
|-------------------------------------------|
| Implementation of the Heap Sort algorithm |
\*******************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

void display( int* array, int size )
{
    for( int i = 0; i < size; i++ )
    {
        cout << "|" << array[i];
    }
    cout << endl;
}

/* 
* Given the index of a child node in the heap, return the index of its parent
* node.
*/
int parent( int i_child )
{
    return (i_child/2);
}

/* 
* Given the index of a parent node in the heap, return the index of its left
* child node. 
*/
int left( int i_parent )
{
    return (2*i_parent)+1;
}

/* 
* Given the index of a parent node in the heap, return the index of its right
* child node. 
*/
int right( int i_parent )
{
    return (2*i_parent)+2;
}

/*
* Given an array, an index, and the size of the heap:
* reorder the heap, rooted at the given index, so that the heap has the hax heap
* property. That is, the value of any node is less than the value of any node
* preceding that node. 
*/
void max_heapify( int* array, int i_parent, int heap_size )
{
    int i_left_child = left( i_parent );
    int i_right_child = right( i_parent );
    int i_largest = i_parent;

    // If the index of the child is within the bounds of the heap
    // and if the value of the child is greater than the value of the current  
    // largest node (largest between the parent, and the left and right child)
    // Then set the largest current node to be the left child.
    if( i_left_child < heap_size && array[i_left_child] > array[i_largest] )
    {
        i_largest = i_left_child;
    }
    
    // If the index of the child is within the bounds of the heap
    // and if the value of the child is greater than the value of the current  
    // largest node (largest between the parent, and the left and right child)
    // Then set the largest current node to be the left child.
    if( i_right_child < heap_size && array[i_right_child] > array[i_largest] )
    {
        i_largest = i_right_child;
    }

    // If the index of the largest node is not the parent, then we know one of 
    // the children is the largest. 
    if( i_largest != i_parent )
    {
        // Swap the parent with the largest child
        int tmp = array[i_parent];
        array[i_parent] = array[i_largest];
        array[i_largest] = tmp;
        // Max-heapify the node that used to be the largest child. 
        // This will trickle down the original parent until it reaches a point 
        // where it is in max heap order.
        max_heapify( array, i_largest, heap_size );
    }
}

/*
* Perform the Build-Max-Heap portion of the algorithm.
* Given an array and an array size, it puts the heap in order such that every
* parent node has a greater value than both of its child nodes. 
*/
void build_max_heap( int* array, int array_size )
{
    for( int i = array_size/2; i >= 0; i-- )
    {
         max_heapify( array, i, array_size );
    }
}

/* 
* Perform the Heap-Sort portion of the algorithm. By repeatedly calling 
* the max-heapify algorithm, the heapsort algorithm sorts the given array. 
*/
void heapsort( int* array, int array_size )
{
    int heap_size = array_size;  // heap_size is the size of the array that is
                                 // used to represent the heap.
                                 // The elements from heap_size+1 to array_size
                                 // are sorted.

    build_max_heap( array, array_size ); // Put the array in max-heap order.
                                         // Note, this does not sort the array
                                         // but it does put the largest value 
                                         // in the heap, at the start of the 
                                         // array.

    // Repeatedy swap the first element of the array (the largest element in the
    // heap) with the last element of the heap, reduce the heap_size so as not 
    // to reintroduce the largest element that was swapped, and max-heapify. 
    // This will sort from the back of the array to the front of the array,
    for( int i = array_size-1; i >= 0; i-- )
    {
        // Swap the first element in the tree with the last element in the tree
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;

        // Reduce the heap size by one so we do not incorporate the sorted
        // elements of the array in our heapify routine
        heap_size--;

        max_heapify( array, 0, heap_size );
    }
}

int main( int argc, const char** argv )
{
    int seed = atoi( argv[1] );
    int size = atoi( argv[2] );
    int i    = atoi( argv[3] );
    int to_sort[size];

    srand( seed );

    for( int i = 0; i < size; i++ )
    {
        to_sort[i] = rand() % size;
    }
// Uncomment below line to display unsorted array.
//    display(to_sort, size);
    heapsort( to_sort, size );
// Uncomment below line to display sorted array.
//    display(to_sort, size);
    cout << "The " << i << "th smallest element is: " << to_sort[i-1] << endl;

    return 0;
}
