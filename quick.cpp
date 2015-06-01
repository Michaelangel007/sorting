/*
    g++ quick.cpp -o quick
Reference:
    http://www.sorting-algorithms.com/quick-sort
*/
#include <stdio.h>
#include "util.h"

// quick (with 2 partitions)
// Note: The common implementation uses a left and right index (this doesn't)
// For faster implementations see:
//   http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C
// ========================================================================
void sort( const int N, int *data )
{
    if( N <= 1 ) // BUGFIX: original algorithm does not include recursion termination
        return;
printf( "N=%d\n", N );

    // leave pivot; use as-is data[0]
    // swap( data[0], rand(1,N));

    // move all data that is less then the pivot to the left side
    // we end up with 2 partitions
    //   [1..k-1] all data is <  pivot data[k]
    //   [k..n  ] all data is >= pivot data[k]
    int k = 0;
printf( "pivot = [%d]:%d\n", k, data[k] );

    for( int i = 1; i < N; i++ )
    {
printf( "i:%d  k: %d\n", i, k );
        if( data[i] < data[0] )
        {
            swap( data, ++k, i ); // inefficient if data[1] > data[pivot] --> swap with itself!
dump( N, data );
        }
    }
printf( "sorted [%d]\n", k );
    swap( data, 0, k );
dump( N, data );

printf( "sort Left k=%d terms ...\n", k );
    sort( k    , data + 0   ); //   0..k-1

printf( "sort Right N-k-1 = %d-%d-1 = %d terms ...\n", N, k, N-k-1 );
    sort( N-k-1, data + k+1 ); // k+1..n   -->  n-k terms

printf( "\n" );
}

int main()
{
    /* */ int src[] = { 3, 4, 2, 1 };
//int src[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 }; // reverse
//int src[] = { 9, 7, 5, 3, 1, 2, 4, 6, 8 }; // alternating reverse and forward
    const int len   = sizeof( src ) / sizeof( int );

    dump( len, src );
    sort( len, src );
    dump( len, src );

    return 0;
}
