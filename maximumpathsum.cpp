#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node *left;
Node *right;
Node(int val){
    this->data=val;
    left=right=NULL;
}
};

int maxpath(Node *root,int &maxi){
    if(root==NULL)return 0;
    int leftsum=max(0,maxpath(root->left,maxi));
    int rightsum=max(0,maxpath(root->right,maxi));
    maxi=max(maxi,leftsum+rightsum+root->data);
    return (root->data)+max(leftsum,rightsum);
}
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
Node *root =new Node(-10);
root->left=new Node(9);
root->right=new Node(20);
root->right->left=new Node(15);
root->right->right=new Node(7);
int maxi=0;
maxpath(root,maxi);
cout<<maxi<<endl;

}