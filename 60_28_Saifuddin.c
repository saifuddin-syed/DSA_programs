/*DFS Traversal of Graph*/

/*
Name = Saifuddin Syed
Roll No = 60
pid = 28
SE-IT
2023-24
*/

#include<stdio.h>
#include<stdlib.h>

int vis[20];
int  top = -1, stack[ 20 ];
int a[20][20];
 
void dfs( int s, int n );
void push( int item );
  int pop();

void main()
{
    int n, i, s, j;
    printf( "Enter the number of vertices: " );
    scanf( "%d", &n );

    for ( i = 1;i <= n;i++ )
	{
	    for ( j = 1;j <= n;j++ )
		{
		    printf( "Enter 1 if %d has a node with %d or enter 0 ", i, j );
		    scanf( "%d", &a[ i ][ j ] );
		}
	}

    printf( "The Adjacency matrix is: \n" );

    for ( i = 1;i <= n;i++ )
	{
	    for ( j = 1;j <= n;j++ )
		{
		    printf( " %d", a[ i ][ j ] );
		}

	    printf( "\n" );
	}

	for ( i = 1;i <= n;i++ )
		vis[ i ] = 0;

	   printf( "Enter the source vertex: " );
	    scanf( "%d", &s );

	dfs( s, n );
}


void dfs( int s, int n )
{
    int i, k;
    push( s );
    vis[ s ] = 1;
    k = pop();

    if ( k != 0 )
	printf( " %d ", k );

    while ( k != 0 )
	{
	    for ( i = 1;i <= n;i++ )
		if ( ( a[ k ][ i ] != 0 ) && ( vis[ i ] == 0 ) )
		    {
			push( i );
			vis[ i ] = 1;
		    }

	    k = pop();

	    if ( k != 0 )
		printf( " %d ", k );
	}

    for ( i = 1;i <= n;i++ )
	if ( vis[ i ] == 0 )
	    dfs( i, n );
}

void push( int item )
{
    if ( top == 19 )
	printf( "Full!" );
    else
	stack[ ++top ] = item;
}

int pop()
{
    int k;

    if ( top == -1 )
	return ( 0 );
    else
	{
	    k = stack[ top-- ];
	    return ( k );
	}
} 