#define MAXN 10
#define DIR  8
#define DIM  2

#include <stdio.h>
#include <string.h>

int main( )
{
	short checker[MAXN][MAXN],dir[DIR][DIM]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
	char start[MAXN], end[MAXN];
	int  i, found;
	int  front, rear, end_x, end_y, next_x, next_y, x[MAXN*MAXN], y[MAXN*MAXN];

	while ( scanf( "%s%s", start, end ) != EOF )
	{
		if ( strcmp( start, end ) == 0 ){
			printf( "To get from %s to %s takes 0 knight moves.\n", start, end );
			continue;
		}
		memset( checker, 0, sizeof( checker ) );
		found = front = 0; rear = 1;
		end_x = 'h' - end[0] + 1; end_y = end[1] - '0';
		x[front] = 'h' - start[0] + 1; y[front] = start[1] - '0';
		while ( front < rear && !found )
		{
			for ( i=0; i<DIR; ++i ){
				next_x = x[front] + dir[i][0];
				next_y = y[front] + dir[i][1];
				if ( next_x <= 8 && next_x >= 1 && next_y <= 8 && next_y >= 1 && checker[next_x][next_y] == 0 ){
					checker[next_x][next_y] = checker[x[front]][y[front]] + 1;
					if ( next_x == end_x && next_y == end_y ){
						found = 1;
						break;
					}
					x[rear] = next_x;
					y[rear] = next_y;
					++rear;
				}
			}
			++front;
		}
		printf( "To get from %s to %s takes %d knight moves.\n", start, end, checker[next_x][next_y] );
	}

	return 0;
}
