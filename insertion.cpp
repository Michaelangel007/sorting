/*
    g++ insertion.cpp -o insertion
Reference:
    http://www.sorting-algorithms.com/insertion-sort
*/
#include <stdio.h>
#include "util.h"

// insertion
// ========================================================================
void sort( const int N, int *data )
{
    for( int i = 1; i < N; i++ )
    {
        for( int k = i; k > 1 && (data[k] < data[k-1]); k-- )
        {
printf( "i:%d  k-1: %d\n", i, k-1 );
            swap( data, i, k-1 );
dump( N, data );
        }
printf( "sorted [%d]\n", i );
printf( "\n" );
    }
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
