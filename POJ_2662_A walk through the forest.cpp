const int NNODE = 1000 + 3;
const int INF   = 1000000000;

#include <iostream>
#include <cstring>
using namespace std;

int ninter;
int adj[NNODE][NNODE], opt[NNODE], path[NNODE];

void Spfa( int v )
{
	bool Inqueue[NNODE]={false};
	int  front=0, rear=1, u;
	int  queue[NNODE]={v};

	for ( int i=1; i<=ninter; ++i )
		opt[i] = INF;
	opt[v] = 0;
	while ( front != rear ){
		u = queue[front];
		Inqueue[u] = false;
		for ( int i=1; i<=ninter; ++i ){
			if ( opt[i] > opt[u] + adj[u][i] ){
				opt[i] = opt[u] + adj[u][i];
				if ( !Inqueue[i] ){
					Inqueue[i] = true;
					queue[rear++] = i;
					rear %= NNODE;
				}
			}
		}
		front = ( front + 1 ) % NNODE;
	}
}

void Dfs( int v )
{
	int sum=0;

	if ( path[v] == -1 ){
		path[v] = 0;
		for ( int i=1; i<=ninter; ++i ){
			if ( adj[v][i] != INF && opt[i] < opt[v] ){
				adj[v][i] = adj[i][v] = INF;
				Dfs( i );
				path[v] += path[i];
			}
		}
	}
}

int main( )
{
	int nroad, start, end, cost;

	while ( cin >> ninter && ninter != 0 ){
		cin >> nroad;
		memset( path, -1, sizeof(path) );
		path[2] = 1;
		for ( int i=1; i<=ninter; ++i )
			for ( int j=1; j<=ninter; ++j )
				adj[i][j] = INF;
		for ( int i=1; i<=nroad; ++i ){
			cin >> start >> end >> cost;
			if ( adj[start][end] > cost ){
				adj[start][end] = adj[end][start] = cost;
			}
		}
		Spfa( 2 );
		Dfs( 1 );
		cout << path[1] << endl;
	}
	return 0;
}
