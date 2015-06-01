#include <stdio.h>
// g++ insertion.cpp -o insertion

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
    for( int i = 1; i < N; i++ )
    {
        for( int k = i; k > 1 && (data[k] < data[k-1]); k-- )
        {
printf( "i:%d  k-1: %d\n", i, k-1 );
printf( "swap [%d]:%d > [%d]:%d\n", i, data[i], k-1, data[k-1] );
                int temp = data[i];
                           data[i] = data[k-1];
                                     data[k-1] = temp;
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
