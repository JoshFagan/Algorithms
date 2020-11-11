/************************************************\
| Joshua Fagan                                   |
| COSC581, HW4                                   |
| Due 2/3/2015                                   |
|------------------------------------------------|
| Implementation of the selection sort algorithm |
\************************************************/

#include <iostream>

using namespace std;

/* 
* Method that writes out the given array with given size
*/
void display( int* array, int size )
{
    for( int i = 0; i < size; i++ )
    {
        cout << "|" << array[i];
    }
    cout << endl;
}

/*
* Method that performs the selection sort algorithm on the given array of 
* given size
*/
void sort( int* array, int size )
{
    // Iterate through each element of the array
    for( int i = 0; i < size; i++ )
    {
        int k = i;

        // Iterate through the remaining elements in the array
        for( int j = i+1; j < size; j++ )
        {
            // If there is an element to the right of index i that is smaller
            // than the element indexed at i then save the index of the smaller
            // element.
            if( array[j] < array[k] )
            {
                k = j;
            }
        }

        // If the index of the smallest element from i to the end of the array
        // does not equal i, then swap the smallest element and the element
        // indexed at i.
        if( k != i )
        {
            int tmp = array[i];
            array[i] = array[k];
            array[k] = tmp;
        }
    }
}

int main( int argc, const char** argv )
{
    int seed = atoi( argv[1] );
    int size = atoi( argv[2] );

    int to_sort[size];

    srand( seed );

    for( int i = 0; i < size; i++ )
    {
        to_sort[i] = rand() % size;
    }

// Uncomment below line to display unsorted array.
//    display( to_sort, size );

    sort( to_sort, size );

// Uncomment below line to display sorted array.
//    display( to_sort, size );

    return 0;
}
