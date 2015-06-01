/*
  g++ selection.cpp -o selection
*/
#include <stdio.h>
#include "util.h"

// selection
// ========================================================================
void sort( const int N, int *data )
{
    for( int i = 0; i < N; i++ )
    {
        int k = i;
        for( int j = i+1; j < N; j++ )
        {
printf( "i:%d  j: %d\n", i, j );
            if( data[j] < data[k] )
                k = j;
        }
        swap( data, i, k );
dump( N, data );
printf( "sorted [%d]\n", i );
printf( "\n" );
    }
}

int main()
{
    /* */ int src[] = { 3, 4, 2, 1 };
    const int len   = sizeof( src ) / sizeof( int );

    dump( len, src );
    sort( len, src );
    dump( len, src );

    return 0;
}
