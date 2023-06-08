#include<iostream>
#include<stack>
using namespace std;

struct node{
	char data;
	node* left;
	node* right;
	node(char data)
	{
		this->data =data;
		left=nullptr;
		right=nullptr;	
	}
};

node* constructtree(string prefixexpr)
{
	stack<node* > st;
	int lenght = prefixexpr.length();
	for (int i=lenght-1;i>=0;i--)
	{
		char token = prefixexpr[i];
		node* newnode = new node(token);
		if(isalnum(token))
		{
			st.push(newnode);
		}
		else
		{
			newnode->left = st.top();
			st.pop();
			newnode->right = st.top();
			st.pop();
			st.push(newnode);
		}
	}
	return st.top();
}

void postordertraversal(node* root)
{
	if(root==nullptr){
		return;
	}
	postordertraversal(root->left);
	postordertraversal(root->right);
	cout<<root->data<<" ";
}

void deletetree(node* root)
{
	if(root==nullptr)
	{
		return;
	}
	deletetree(root->left);
	deletetree(root->right);
	delete root;
}
int main()
{
	string prefix;
	cout<<"prefix expression: ";
	cin>>prefix;
	
	node* root = constructtree(prefix);
	cout<<"Post-order traversal: ";
	postordertraversal(root);
	cout<<endl;
	
	deletetree(root);
	cout<<"the tree is deleted";
	return 0;
}
