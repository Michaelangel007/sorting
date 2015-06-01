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

// ========================================================================
inline
void swap( int *data, const int a, const int b )
{
printf( "swap [%d]:%d > [%d]:%d\n", a, data[a], b, data[b] );
    int temp = data[a];
               data[a] = data[b];
                         data[b] = temp;
}

