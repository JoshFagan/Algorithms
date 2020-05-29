/******************************************************************************\
| Joshua Fagan                                                                 |
| COSC581, HW4                                                                 |
| Due 2/3/2015                                                                 |
|------------------------------------------------------------------------------|
| Implementation of the SELECT(A, ith_smallest, low, high) algorithm.          |
| Runtime is O(n).                                                             |
|------------------------------------------------------------------------------|
| Returns the ith smallest elment of A in the range low-high.                  |
\******************************************************************************/

#include <iostream>
#include "math.h"
#include <stdlib.h>


using namespace std;

/* 
* Method that writes out the given array with given size
*/
void display( int* array, int low, int high )
{
    for( int i = low; i < high; i++ )
    {
        cout << "|" << array[i];
    }
    cout << endl;
}

void swap( int* array, int index1, int index2 )
{
    int tmp  = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void insertionSort( int* array, int low, int high )
{
    for( int j = low+1; j < high; j++ )
    {
        int key = array[j];
        int i = j-1;
        while( i >= low && array[i] > key )
        {
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}

int partition( int* array, int low, int high, int pivot )
{
    for( int i = low; i < high; i++ )
    {
        if( array[i] == pivot )
        {
            swap( array, i, high-1 );
        }
    }

    int i = low - 1;
    for( int j = low; j < high-1; j++ )
    {
        if( array[j] <= pivot )
        {
            i++;
            swap( array, i, j );
        }
    }
    swap( array, i+1, high-1 );

    return i+1;
}

int select( int* to_sort, int* array, int ith_smallest, int low, int high, int size )
{
    int num_groups = (int)ceil((double)(high-low)/5);
    int medians[num_groups];
    int mom;
    int pivot_index;

    if( high-low == 1 )
    {
        return array[low];
    }

    int i = 0;
    while( i < num_groups-1 )
    {
        insertionSort(array, i*5+low, i*5+5+low);
        medians[i] = array[i*5+low+2];
        i++;
    }

    insertionSort( array, i*5+low, high );
    medians[i] = array[ i*5+low + ((high)-(i*5+low)-1)/2];

    mom = select(to_sort,medians, (num_groups-1)/2,0, num_groups, size);

    pivot_index = partition( array, low, high, mom );

    if( ith_smallest == pivot_index )
    {
        return mom;
    }
    else if( ith_smallest < pivot_index )
    {
        return select(to_sort,array, ith_smallest, low, pivot_index, size );
    }
    else
    {
        return select(to_sort, array, ith_smallest, pivot_index+1, high, size);
    }
}

int main( int argc, const char** argv )
{
    int seed = atoi( argv[1] );
    int size = atoi( argv[2] );
    int i    = atoi( argv[3] );
    int ith_value;

    int array_A[size];

    srand( seed );

    for( int j = 0; j < size; j++ )
    {
        array_A[j] = rand() % size;
    }

// Uncomment below line to display unsorted array.
//    display( array_A, 0,size );

    ith_value = select( array_A,array_A, i-1, 0, size, size );

// Uncomment below line to display sorted array.
//    display( array_A,0, size );
    cout << "The "<< i << "th smallest element is: " << ith_value << endl;
    return 0;
}
