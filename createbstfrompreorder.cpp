#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int val;
	TreeNode *left,*right;
	TreeNode(int data){
		this->val=data;
		left=right=NULL;
	}
};
TreeNode *build(vector<int>&a,int &i,int bound){
	if(i==a.size()||a[i]>bound)return NULL;
	TreeNode *root=new TreeNode(a[i++]);
	root->left=build(a,i,root->val);
	root->right=build(a,i,bound);
	return root;
}
TreeNode *bstFromPreorder(vector<int>&a){
	int i=0;
	return build(a,i,INT_MAX);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int>a={8,5,1,7,10,12};
    TreeNode *ans=bstFromPreorder(a);
    cout<<ans->val;
}