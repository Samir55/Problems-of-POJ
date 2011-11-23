const int MAXN = 1000000 + 11;
const int INF  = 2000000000;
const int TRI  = 3;

struct node
{
	int   end, len;
	node* next;
};

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

node *adj[MAXN], *tail[MAXN], *cur;
bool inqueue[MAXN];
int  cnt[MAXN], queue[MAXN], opt[MAXN], input[MAXN][TRI];
int  nstop, nroad;
long long ans;

void Initialize( )
{
	int beg, end, cost;

	memset( cnt, 0, sizeof(cnt) );
	scanf( "%d%d", &nstop, &nroad );
	ans = 0;
	for ( int i=1; i<=nroad; ++i )
		adj[i] = NULL;
	for ( int i=1; i<=nroad; ++i ){
		scanf( "%d%d%d", &beg, &end, &cost );
		input[i][0] = end;
		input[i][1] = beg;
		input[i][2] = cost;
		cur = new node;
		cur->end = end;
		cur->len = cost;
		cur->next = NULL;
		if ( adj[beg] == NULL )
			adj[beg] = tail[beg] = cur;
		else{
			tail[beg]->next = cur;
			tail[beg] = cur;
		}
		++cnt[beg];
	}
}

void Spfa( int v )
{
	int   front=0, rear=1, u;
	node* p;

	queue[front] = v;
	for ( int i=1; i<=nstop; ++i )
		opt[i] = INF;
	opt[v] = 0;
	while ( front != rear ){
		u = queue[front];
		inqueue[u] = false;
		p = adj[u];
		for ( int i=0; i<cnt[u]; ++i, p=p->next ){
			if ( opt[p->end] > opt[u] + p->len ){
				opt[p->end] = opt[u] + p->len;
				if ( !inqueue[p->end] ){
					inqueue[p->end] = true;
					queue[rear++] = p->end;
					rear %= MAXN;
				}
			}
		}
		front = ( front + 1 ) % MAXN;
	}
}

void Reverse( )
{
	int  beg, end;
	node *cur;

	memset( cnt, 0, sizeof(cnt) );
	memset( tail, NULL, sizeof(tail) );
	for ( int i=1; i<=nroad; ++i )
		adj[i] = NULL;
	for ( int i=1; i<=nroad; ++i ){
		cur = new node;
		cur->end = input[i][1];
		cur->len = input[i][2];
		cur->next = NULL;
		beg = input[i][0];
		if ( adj[beg] == NULL )
			adj[beg] = tail[beg] = cur;
		else{
			tail[beg]->next = cur;
			tail[beg] = cur;
		}
		++cnt[beg];
	}
}

void Solve( )
{
	Spfa( 1 );
	for ( int i=2; i<=nstop; ++i )
		ans += opt[i];
	Reverse( );
	Spfa( 1 );
	for ( int i=2; i<=nstop; ++i )
		ans += opt[i];
}

void Output( )
{
	printf( "%lld\n", ans );
}

int main( )
{
	int ncase;

	scanf( "%d", &ncase );
	while ( ncase-- ){
		Initialize( );
		Solve( );
		Output( );
	}
	return 0;
}
