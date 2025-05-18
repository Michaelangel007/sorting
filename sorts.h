// ========================================================================
void Swap( int *data, const int src, const int dst )
{
    int temp = data[dst];
               data[dst] = data[src];
                           data[src] = temp;
}

// ========================================================================
void bubble_sort( const int N, int *data )
{
    for( int i = 0; i < N; i++ )
    {
        bool swapped = false;
        for( int j = N-1; j > i; j-- )
        {
            if( data[j] < data[j-1] )
            {
                swapped = true;
                Swap( data, j-1, j );
            }
        }
        if( !swapped )
            break;
    }
}

// ========================================================================
void insert_sort( const int N, int *data )
{
    for( int i = 1; i < N; i++ )
    {
        for( int k = i; k > 1 && (data[k] < data[k-1]); k-- )
        {
            Swap( data, i, k-1 );
        }
    }
}

// ========================================================================
void selection_sort( const int N, int *data )
{
    for( int i = 0; i < N; i++ )
    {
        int k = i;
        for( int j = i+1; j < N; j++ )
        {
            if( data[j] < data[k] )
                k = j;
        }
        Swap( data, i, k );
    }
}


// ========================================================================
void quick_sort( const int N, int *data )
{
    if( N <= 1 ) // BUGFIX: original algorithm does not include recursion termination
        return;

    // leave pivot; use as-is data[0]
    // swap( data[0], rand(1,N));

    // move all data that is less then the pivot to the left side
    // we end up with 2 partitions
    //   [1..k-1] all data is <  pivot data[k]
    //   [k..n  ] all data is >= pivot data[k]
    int k = 0;

    for( int i = 1; i < N; i++ )
    {
        if( data[i] < data[0] )
        {
            Swap( data, ++k, i ); // inefficient if data[1] > data[pivot] --> swap with itself!
        }
    }
    Swap( data, 0, k );
    quick_sort( k    , data + 0   ); //   0..k-1
    quick_sort( N-k-1, data + k+1 ); // k+1..n   -->  n-k terms
}

#if 0
#include <stdio.h>
#define sort quick_sort

// ========================================================================
void dump( const int N, const int *data )
{
    for( int i = 0; i < N; i++ )
        printf( "[%d]:%d %.*s\n", i, data[i], data[i], "**********" );
    printf( "\n" );
}

// ========================================================================
int main()
{
    int src[] = { 9, 7, 5, 3, 1, 2, 4, 6, 8 }; // alternating reverse and forward
    const int len   = sizeof( src ) / sizeof( int );

    dump( len, src );
    sort( len, src );
    dump( len, src );

    return 0;
}
#endif
