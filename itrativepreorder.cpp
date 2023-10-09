#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;

	Node *left;

	Node *right;

	Node(int val){

		this->data=val;

		left=right=NULL;
	}
	
};
void itretavivepreorder(Node *root,vector<int>&ans){

    stack<Node*>s;

    s.push(root);

    while(!s.empty()){

       root=s.top();

       s.pop();

       ans.push_back(root->data);
       //as stack follows lifo first we will push right then left
       if(root->right!=NULL)s.push(root->right);

       if(root->left!=NULL)s.push(root->left);
       

    }

}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    Node *root=new Node(1);

    root->left=new Node(2);

    root->right=new Node(7);

    root->left->left=new Node(3);

    root->left->right=new Node(4);

    root->left->right->left=new Node(5);

    root->left->right->right=new Node(6);

    vector<int>ans;

    itretavivepreorder(root,ans);

    for(auto it:ans){

    	cout<<it<<" ";
    }

}