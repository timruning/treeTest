#include<stdio.h>
using namespace std;
class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int k):val(k),left(NULL),right(NULL),parent(NULL){}
};
Node* findNext(Node* nodeA){
	if(nodeA->left!=NULL){
		return nodeA->left;
	}else if(nodeA->right!=NULL){
		return nodeA->left;
	}else{
		Node* result=nodeA->parent;
		Node* p=nodeA;
		while(result!=NULL){
			if(p==result->left) return result->right;
			else{
				p=result;
				result=result->parent;
			}
		}
		return result;
	}
}
int main(){
	Node* node1=new Node(1);	
	Node* node2=new Node(2);
	Node* node3=new Node(3);
	Node* node4=new Node(4);
	Node* node5=new Node(5);
	Node* node6=new Node(6);
//	Node* node7=new Node(7);
//	Node* node8=new Node(8);
	node1->left=node2;
	node1->right=node3;
	node2->parent=node1;
	node2->right=node4;
	node3->parent=node1;
	node3->left=node5;
	node3->right=node6;
	node4->parent=node2;
	node5->parent=node3;
	node6->parent=node3;
	Node* result=findNext(node4);
	if(result!=NULL)
		printf("%d\n",result->val);	
	else{
		printf("it is NULL!\n");
	}
}
