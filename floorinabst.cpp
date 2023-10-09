#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node*left,*right;
		node(int val){
			this->data=val;
			left=right=NULL;
		}
};
int findfloor(node *root,int key){
	int floor=-1;
	while(root!=NULL){
		if(root->data==key){
			floor=root->data;
			return floor;
		}
		else if(key>root->data){
			floor=root->data;
			root=root->right;
		}
		else if(key<root->data){
			root=root->left;
		}
	}
	return floor;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    node *root =new node(10);
    root->left=new node(5);
    root->right=new node(15);
    root->left->left=new node(2);
    root->left->right=new node(8);
    root->left->right->left=new node(6);
    root->right->left=new node(13);
    root->right->right=new node(17);
    int ans=findfloor(root,14);
    cout<<ans<<endl;
}