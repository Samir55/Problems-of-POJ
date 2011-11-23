const int NPEOPLE = 100 + 3;
const int INF     = 10000 + 5;
const int NEGAINF = 0;

#include <iostream>
#include <cstring>
using namespace std;

int npeople;
int adj[NPEOPLE][NPEOPLE];

bool Initialize( )
{
	int nconnect, end, cost;

	cin >> npeople;
	if ( npeople == 0 )
		return false;
	else{
		for ( int i=1; i<=npeople; ++i ){
			for ( int j=1; j<=npeople; ++j ){
				if ( i == j )
					adj[i][j] = 0;
				else
					adj[i][j] = INF;
			}
		}
		for ( int start=1; start<=npeople; ++start ){
			cin >> nconnect;
			for ( int i=1; i<=nconnect; ++i ){
				cin >> end >> cost;
				adj[start][end] = cost;
			}
		}
		return true;
	}
}

bool Detect( )
{
	bool seperate=false;

	for ( int i=1; i<=npeople && !seperate; ++i ){
		seperate = true;
		for ( int j=1; j<=npeople; ++j ){
			if ( j != i && adj[i][j] != INF ){
				seperate = false;
				break;
			}
		}
		if ( seperate ){
			for ( int j=1; j<=npeople; ++j ){
				if ( j != i && adj[j][i] != INF ){
					seperate = false;
					break;
				}
			}
		}
	}
	if ( seperate )
		return true;
	else
		return false;

}

void Floyd_Warshall( )
{
	for ( int k=1; k<=npeople; ++k ){
		for ( int i=1; i<=npeople; ++i ){
			for ( int j=1; j<=npeople; ++j ){
				if ( adj[i][j] > adj[i][k] + adj[k][j] ){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

void Solve( )
{
	int ans_person, ans_cost=INF, max;

	Floyd_Warshall( );
	if ( Detect( ) )
		cout << "disjoint" << endl;
	else{
		for ( int i=1; i<=npeople; ++i ){
			max = NEGAINF;
			for ( int j=1; j<=npeople; ++j ){
				if ( adj[i][j] > max ){
					max = adj[i][j];
				}
			}
			if ( max != NEGAINF && max < ans_cost ){
				ans_cost = max;
				ans_person = i;
			}
		}
		cout << ans_person << " " << ans_cost << endl;
	}
}

int main( )
{
	while ( Initialize( ) )
		Solve( );
	return 0;
}
