#include <iostream>
#include <array>

using namespace std;

void display( int* array, int size )
{
    for( int i = 0; i < size; i++ )
    {
        cout << "|" << array[i];
    }
    cout << endl;
}

void swap( int* array, int i_1, int i_2 )
{
    int tmp = array[i_1];
    array[i_1] = array[i_2];
    array[i_2] = tmp;
}

int partition( int* array, int left, int right, int ascending )
{
    int decrement = 1;
    while( left < right )
    {
        if( ascending )
        {
            if( array[left] > array[right] )
            {
                swap( array, left, right );
                decrement = ( decrement + 1) % 2;
            }
        
            if( decrement )
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        else
        {
            if( array[left] < array[right] )
            {
                swap( array, left, right );
                decrement = ( decrement + 1) % 2;
            }
        
            if( decrement )
            {
                right--;
            }
            else
            {
                left++;
            }  
        }
    }

    return left;
}

void quicksort( int* array, int left, int right, int ascending )
{
    if( left < right )
    {
        int part = partition( array, left, right, ascending );
        quicksort( array, left, part-1, ascending );
        quicksort( array, part+1, right, ascending );
    }
}

int main( int argc, const char** argv )
{
    int ascending = atoi( argv[1] );
    int seed      = atoi( argv[2] );
    int size      = atoi( argv[3] );
    int to_sort[size];

    srand( seed );

    for( int i = 0; i < size; i++ )
    {
        to_sort[i] = rand() % size;
    }

//    display( to_sort, size );

    quicksort( to_sort, 0, size-1, ascending );

//    display( to_sort, size );
   
    return 0;
}
