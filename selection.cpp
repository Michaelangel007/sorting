#include <stdio.h>
// g++ selection.cpp -o selection

// ========================================================================
void dump( const int N, const int *data )
{
    for( int i = 0; i < N; i++ )
#if 0
        printf( "%d ", data[i] );
#else
        printf( "[%d]:%d %.*s\n", i, data[i], data[i], "*****" );
#endif
printf( "\n" );
}

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
printf( "swap [%d]:%d > [%d]:%d\n", j-1, data[j-1], j, data[j] );
                int temp = data[i];
                           data[i] = data[k];
                                     data[k] = temp;
dump( N, data );
        }
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
