#include<iostream>
#include<string>
using namespace std;

struct Node
{
	char value;
	Node* lChild;
	Node* rChild;
};

Node* recoverTree(string preStr, string inStr)
{
	Node* root=NULL;
	int pos;
	
	if(preStr.length()>0)
	{
		root=new Node;
		root->value=preStr[0];
		pos=inStr.find(root->value);
		root->lChild=recoverTree(preStr.substr(1,pos),inStr.substr(0,pos));
		root->rChild=recoverTree(preStr.substr(pos+1),inStr.substr(pos+1));
	}
	return root;
}

void postOrder(Node* root)
{
	if(root!=NULL)
	{
		postOrder(root->lChild);
		postOrder(root->rChild);
		cout<<root->value;
	}
	return ;
}

int main()
{
	string preStr,inStr;
	
	while(cin>>preStr>>inStr)
	{
		Node *root=recoverTree(preStr,inStr);
		postOrder(root);
		cout<<endl;
	}
	return 0;
}
