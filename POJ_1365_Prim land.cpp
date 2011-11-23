const int MAXN = 32767+100;

#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

vector<int> prim;
set<int>    prim_set;

void CreatePrim( );
void Input( );
void Proceed( int );

int main( )
{
	CreatePrim( );
	Input( );
	
	return 0;
}

void CreatePrim( )
{
	int  i, j;
	bool isNotPrim[MAXN]={1,1};
	
	for ( i=2; i<MAXN; ++i )
	{
		if ( !isNotPrim[i] )
		{
			prim.push_back( i );
			prim_set.insert( i );
		}
		for ( j=0; j<prim.size( ) && i*prim[j]<MAXN; ++j )
		{
            isNotPrim[i*prim[j]] = true;
			if( !( i%prim[j] ) )
				break;
		}
	}
	
	return ;
}

void Input( )
{
	char ch;
	int  i;
	int  base, exp, val;
	
	while ( true )
	{
        val = 1;
        
		while ( cin >> base && base != 0 )
		{
			ch = getchar( );
     		cin >> exp;
	  		if ( exp == 0 )
	  		    base = 1;
	  		for ( i=0; i<exp; ++i )
	            val *= base;
			ch = getchar( );
			if ( ch != ' ' )
			    break;
		}
		if ( base == 0 )
		    break;
		else
			Proceed( --val );
	}
	
	return ;
}

void Proceed( int num )
{
	bool first=true;
    int  hash[MAXN]={0}, i=num;
    
	for ( ; i>1; )
	{
		if ( num%i == 0 && prim_set.count( i ) )
		{
			num/=i;
			hash[i]++;
		}
		else
			i--;
	}
	for ( i=MAXN-1; i>=2; --i )
	{
		if ( hash[i] != 0 )
		{
			if ( first )
			{
				cout << i << " " << hash[i];
				first = false;
			}
			else
			    cout << " " << i << " " << hash[i];
		}
	}
	cout << endl;
	
	return ;
}
