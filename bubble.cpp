#include <stdio.h>
// g++ bubble.cpp -o bubble

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

// bubblesort
// ========================================================================
void sort( const int N, int *data )
{
    for( int i = 0; i < N; i++ )
    {
        bool swap = false;
        for( int j = N-1; j > i; j-- )
        {
printf( "i:%d  j: %d\n", i, j );
            if( data[j] < data[j-1] )
            {
                    swap = true;           
printf( "swap [%d]:%d > [%d]:%d\n", j-1, data[j-1], j, data[j] );
                int temp = data[j-1];
                           data[j-1] = data[j];
                                       data[j] = temp;
dump( N, data );
            }
        }
printf( "sorted [%d]\n", i );
printf( "\n" );
        if( !swap )
            break;
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
