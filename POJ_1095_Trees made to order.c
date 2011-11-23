#define MAXN 25

#include <stdio.h>

int  nnode;
long long num;
long long amount[MAXN]={1,1};
long long end_pos[MAXN]={1,2};

void CreateSum( )
{
	int i, j;

	for ( i=2; i<MAXN; ++i )
	{
  		for ( j=0; j<i; ++j )
			amount[i] += amount[j] * amount[i-j-1];
		end_pos[i] = end_pos[i-1] + amount[i];
	}

	return ;
}

void FindNode( )
{
	for ( nnode=1; nnode<MAXN; ++nnode )
	    if ( end_pos[nnode] > num )
	        break;

	return ;
}

void Solve( int node, long remain )
{
	int  lnode=0, rnode=node-1;
	long tmp;

	for ( ; lnode < node; ++lnode, --rnode )
	{
		tmp = amount[lnode] * amount[rnode];
		if ( remain >= tmp )
		    remain -= tmp;
		else
		    break;
	}
	if ( lnode != 0 ) { printf( "(" ); Solve( lnode, remain/amount[rnode] ); printf( ")" ); }
	printf( "X" );
	if ( rnode != 0 ) { printf( "(" ); Solve( rnode, remain%amount[rnode] ); printf( ")" ); }

	return ;
}

int main( )
{
	CreateSum( );
	while ( scanf( "%ld", &num ) && num != 0 )
	{
		FindNode( );
		Solve( nnode, num - end_pos[nnode-1] );
		printf( "\n" );
	}

	return 0;
}
