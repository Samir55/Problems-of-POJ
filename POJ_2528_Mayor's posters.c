#define MAXNODE 10005
#define MAXN    70000

typedef struct TREENODE
{
	short start, end;
	short color;
} 	NODE;

typedef struct DISCONCRETE
{
	long  loc;
	short num;
}   POINT;

typedef struct DISCONCRETED
{
	short start, end;
}   INPUT;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

NODE  node[MAXN];
POINT point[MAXNODE<<1];
INPUT input[MAXNODE];
short ifocc[MAXNODE];
int   ans, nposter, largest;

int cmp( const void* a, const void* b )
{
	return (*((const long*)a)) - (*((const long*)b));
}

void Preprocess( )
{
	int  i;
	long tmp_start, tmp_end, tmp;

	memset( ifocc, 0, sizeof( ifocc ) );
	scanf( "%d", &nposter );
	for ( i=0; i<nposter; ++i )
	{
		scanf( "%ld%ld", &tmp_start, &tmp_end );
		point[2*i].loc = tmp_start;
		point[2*i].num = i+1;
		point[2*i+1].loc = tmp_end;
		point[2*i+1].num = -i-1;
	}
	qsort( point, 2*nposter, sizeof( point[0] ), cmp );
	largest = 1;
	tmp = point[0].loc;
	for ( i=0; i<nposter*2; ++i )
	{
		if ( point[i].loc != tmp )
		{
			largest++;
			tmp = point[i].loc;
		}
		if ( point[i].num < 0 )
		    input[-1*point[i].num-1].end = largest;
		else
		    input[point[i].num-1].start = largest;
	}

	return ;
}

void BuildTree( int root, int start, int end )
{
	node[root].start = start;
	node[root].end = end;
	node[root].color = 0;
	if ( start != end )
	{
		BuildTree( 2*root, start, (start+end)>>1 );
		BuildTree( 2*root+1, ((start+end)>>1)+1, end );
	}

	return ;
}

void Insert( int root, int start, int end, int color )
{
	int mid;

	if ( node[root].start == start && node[root].end == end )
	{
		node[root].color = color;
		return ;
	}
	if ( node[root].color > 0 && node[root].color != color )
	{
		node[2*root].color = node[2*root+1].color = node[root].color;
		node[root].color = 0;
	}
	mid = ( node[root].start + node[root].end )>>1;
	if ( end <= mid )
	    Insert( 2*root, start, end, color );
	else if ( start > mid )
	    Insert( 2*root+1, start, end, color );
	else
	{
		Insert( 2*root, start, mid, color );
		Insert( 2*root+1, mid+1, end, color );
	}

	return ;
}

void Query( int root )
{
	if ( node[root].color != 0 )
	{
        if ( ifocc[node[root].color] == 0 )
		{
			ifocc[node[root].color] = 1;
			ans++;
		}
	}
	else
	{
		Query( 2*root );
		Query( 2*root+1 );
	}

	return ;
}

int main( )
{
	int  i;
	int  ncase;

	scanf( "%d", &ncase );
	while ( ncase-- )
	{
		ans = 0;
		Preprocess( );
		BuildTree( 1, 1, largest );
		for ( i=0; i<nposter; ++i )
			Insert( 1, input[i].start, input[i].end, i+1 );
		Query( 1 );
		printf( "%d\n", ans );
	}

	return 0;
}
