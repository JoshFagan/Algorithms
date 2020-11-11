/************************************************\
| Joshua Fagan                                   |
| COSC581, HW4                                   |
| Due 2/3/2015                                   |
|------------------------------------------------|
| Implementation of the selection sort algorithm |
\************************************************/

#include <iostream>

using namespace std;
    
int main( int argc, const char** argv )
{
    int seed = atoi( argv[1] );
    int size = atoi( argv[2] );

    int to_sort[size];

    srand( seed );

    // Generate array of random numbers. 
    // The largest a random number can be is the size of the array.
    for( int i = 0; i < size; i++ )
    {
        to_sort[i] = rand() % size;
    }

// Uncomment below lines to display unsorted array.
//    for( int i = 0; i < size; i++ )
//    {
//        cout << "|" << to_sort[i];
//    }
//    cout << endl;

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
            if( to_sort[j] < to_sort[k] )
            {
                k = j;
            }
        }

        // If the index of the smallest element from i to the end of the array 
        // does not equal i, then swap the smallest element and the element
        // indexed at i.
        if( k != i )
        {
            int tmp = to_sort[i];
            to_sort[i] = to_sort[k];
            to_sort[k] = tmp;
        }
    }

// Uncomment below lines to display sorted array.
//    for( int i = 0; i < size; i++ )
//    {
//        cout << "|" << to_sort[i];
//    }
//    cout << endl;

    return 0;
}
