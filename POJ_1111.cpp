const int MAXN = 20 + 3;

#include <cstdio>
#include <cstring>

char map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int  width, height;
int  startX, startY;

bool Input( ) {

    int ret;
    
    scanf("%d%d%d%d", &height, &width, &startX, &startY);

    if (width==0 && height==0) {

        ret = false;

    } else {

        memset( map, '.', sizeof(map) );
        memset( visited, false, sizeof(visited) );
        for ( int i = 1; i <= height; ++i ) {

            scanf("%s", map[i]+1 );

        }
        ret = true;
    }

    return ret;
}

int Dfs( int curX, int curY ) {

    int  ret = 0;

    visited[curX][curY] = true;

    for ( int i = curX-1; i <= curX+1 ; ++i ) {
        for ( int j = curY-1; j <= curY+1; ++j ) {
            if ((i==curX || j==curY) && map[i][j]!='X' )
                ++ret;
            if ( !visited[i][j] && map[i][j]=='X' ) {
                ret += Dfs( i, j );
            }
        }
    }   

    return ret;

}


void Solve( ) {

    printf( "%d\n", Dfs( startX, startY ) );    

}


int main() {

#ifndef ONLINE_JUDGE
    freopen( "/Users/zbw/Desktop/test.txt", "r", stdin );
#endif
    while (Input( )) {

        Solve( );

    }

    return 0;

}
