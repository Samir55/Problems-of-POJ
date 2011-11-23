#define NAMELEN  20+3
#define PRINT    "print"
#define FIRE     "fire"

typedef struct TREENODE
{
	char   name[NAMELEN];
	struct TREENODE* next_sibling;
	struct TREENODE* pre_sibling;
	struct TREENODE* first_vassal;
}   node;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short found;

int Insert( node* root ,char* hire, char* hired )
{
	node* cur;
	node* i;

	if ( strcmp( root->name, hire ) == 0 )
	{
		cur = (node*)malloc( sizeof(node) );
		strcpy( cur->name, hired );
		cur->next_sibling = cur->first_vassal = NULL;
		if ( root->first_vassal == NULL )
		{
			cur->pre_sibling = NULL;
			root->first_vassal = cur;
		}
		else
		{
			for ( i=root->first_vassal; i->next_sibling!=NULL; i=i->next_sibling );
			cur->pre_sibling = i;
			i->next_sibling = cur;
		}
		
		return 1;
	}
	else
	{
		if ( root->first_vassal != NULL && Insert( root->first_vassal, hire, hired ) == 1 )
		    return 1;
		root = root->next_sibling;
		if ( root != NULL && Insert( root, hire, hired ) == 1 )
		    return 1;
		return 0;
	}
}

node* Modify( node* root )
{
	if ( root->first_vassal == NULL )
	{
		root->first_vassal = root->next_sibling;
		if ( root->next_sibling != NULL )
			root->next_sibling->pre_sibling = NULL;
		root->next_sibling = NULL;
	}
	else
	{
		root->first_vassal = Modify( root->first_vassal );
		root->first_vassal->next_sibling = root->next_sibling;
		if ( root->next_sibling != NULL )
			root->next_sibling->pre_sibling = root->first_vassal;
	}

	return root;
}

node* Delete( node* root, char* fired )
{
	if ( root != NULL )
	{
		if ( strcmp( root->name, fired ) == 0 )
		{
			if ( root->first_vassal != NULL )
			{
				root->first_vassal = Modify( root->first_vassal );
				if ( root->pre_sibling != NULL )
					root->pre_sibling->next_sibling = root->first_vassal;
				root->first_vassal->pre_sibling = root->pre_sibling;
				if ( root->next_sibling != NULL )
				    root->next_sibling->pre_sibling = root->first_vassal;
				root->first_vassal->next_sibling = root->next_sibling;
				root = root->first_vassal;
			}
			else
			{
				if ( root->pre_sibling != NULL )
					root->pre_sibling->next_sibling = root->next_sibling;
				if ( root->next_sibling != NULL )
					root->next_sibling->pre_sibling = root->pre_sibling;
				root = root->next_sibling;
			}
			found = 1;
		}
		else
		{
			root->first_vassal = Delete( root->first_vassal, fired );
			root->next_sibling = Delete( root->next_sibling, fired );
		}
	}

	return root;
}

void Print( node* root, int depth )
{
	int i;
	
	if ( root != NULL )
	{
		for ( i=0; i<depth; ++i )
		    printf( "+" );
		printf( "%s\n", root->name );
		Print( root->first_vassal, depth+1 );
		Print( root->next_sibling, depth );
	}

	return ;
}

int main( )
{
	node* ceo;
	char  input[NAMELEN], hired[NAMELEN],hire[NAMELEN];
	
	scanf( "%s", input );
	ceo = (node*)malloc( sizeof(node) );
	ceo->first_vassal = ceo->next_sibling = ceo->pre_sibling = NULL;
	strcpy( ceo->name, input );
	
	while( scanf( "%s", input) != EOF )
	{
		if ( strcmp( input, FIRE ) == 0 )
		{
			found = 0;
			scanf( "%s", input );
			ceo = Delete( ceo, input );
		}
		else if ( strcmp( input, PRINT ) == 0 )
		{
			Print( ceo, 0 );
			printf( "------------------------------------------------------------\n");
		}
		else
		{
			scanf( "%s%s", hire, hired );
			Insert( ceo, input, hired );
		}
	}
	
	return 0;
}
