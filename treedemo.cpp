#include<iostream>
#include<time.h>
using namespace std;
struct Node
{
	char data; // contain data 
	Node *left; // contain left node
	Node *right; // contain right node
};
Node *createnode(char x)
{
	Node *p = new Node();	// create node p
	p -> data = x;
	p -> left = NULL;
	p -> right = NULL;
	return p;
}
Node *Q[20];
void PreOrder(Node *r)// G T P
{
	if(r != NULL){
		cout << r -> data << " ";
		PreOrder(r -> left); // trai 
		PreOrder(r -> right); // phai 
	}
}	
void inOrder(Node *r){ //T G P
	if(r != NULL){
		inOrder(r -> left);
		cout << r -> data << " ";
		inOrder(r -> right);
	}
}
void postOrder(Node *r){ //T P G
	if(r != NULL){
		postOrder(r -> left);
		postOrder(r -> right);
		cout << r -> data << " ";
	}
}
int front = 0;
int rear = 0;
void Enqueue(Node *x){
	Q[rear] = x;
	rear++ ;// sau
}
Node *Dequeue(){
	Node *x = Q[front];
	front++;
	return x;
}
int isEmpty(){
	if(front == rear){
		return 1;
	}
	else{
		return 0;
	}
}

void BFT(Node *root){
	Enqueue(root);
	while(isEmpty() == 0){
		Node *p = Dequeue();
		if(p -> left){
			Enqueue(p -> left);
		}
		if(p -> right){
			Enqueue(p -> right);
		}
		cout << p -> data << " ";
	}
}
int Demnode(Node *root){
	if(root == NULL)
		return 0;
	else 
		return (1+ Demnode(root -> left) + Demnode(root -> right));
	
}
int Docao(Node *r){
	if(r==NULL) return 0;
	
	int caoTrai = Docao(r->left);
	int caoPhai = Docao(r->right);
	if(caoTrai>caoPhai) 
	return (1+caoTrai);
	return (1+caoPhai);
}

//int soNode(Node *r)
//{
//	if(r==NULL)
//			return 0;
//	else 
//		return 1 + soNode(r->left) + soNode(r->right);
//}
//int Docao(Node *r){
//	if(r==NULL) return 0;
//	
//	int caoTrai = Docao(r->left);
//	int caoPhai = Docao(r->right);
//	if(caoTrai>caoPhai) 
//	return (1+caoTrai);
//	return (1+caoPhai);
//}
void TongNguyen(int n){
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum = sum + i;
	}
}
void Tongthuc(float n){
	int sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum = sum + i;
	}
}
int main(){
	Node *root; // Goc cua cay
	Node *p = createnode('*');
	root = p;
	// them dau - 
	p = createnode('-');
	root -> left = p;
	// them dau / 
	p = createnode('/');
	root -> right = p;
	// them so 8
	p = createnode('8');;
	root -> left -> left = p;
	// them so 5
	p = createnode('5');
	root -> left -> right = p;
	// them dau +
	p = createnode('+');
	root -> right -> left = p;
	// them so 2
	p = createnode('2');
	root -> right -> left -> right = p;
	// them so 4
	p = createnode('4');
	root -> right -> left -> left = p;
	// them so 3
	p = createnode('3');
	root -> right -> right = p;
	cout << " 1) Duyet theo chieu sau : " << endl;
	cout << " - PreOrder : ";
	PreOrder(root);
	cout << endl;
	cout << " - Inorder : ";
	inOrder(root);
	cout << endl;
	cout << " - PostOrder : ";
	postOrder(root);
	cout << endl;
	cout << " 2) Duyet rong : " << endl;
	cout << " - BFT : ";
	BFT(root);
	cout << endl;
	cout << " 3) Dem node : " << endl;
	cout << " - So node trong tree is : " << Demnode(root);
	cout << endl;
	cout << " 4) Tinh Do cao : " << endl;
	cout << " - Do cao cua node la : " << Docao(root);
	float batdau , ketthuc , thoigianchay;
	batdau = clock(); // Nhin dong ho 
	int n = 90000000;
	TongNguyen(n); // Tinh tong 9000000 so nguyen 
	ketthuc = clock(); // Nhin dong ho
	thoigianchay = ketthuc - batdau;
	cout << "\n - Thoi gian tinh tong 9000000 so nguyen la : " ;
	cout << thoigianchay << "ms";
	Tongthuc(n); // Tinh tong 9000000 so nguyen 
	ketthuc = clock(); // Nhin dong ho
	thoigianchay = ketthuc - batdau;
	cout << "\n - Thoi gian tinh tong 9000000 so thuc la : " ;
	cout << thoigianchay << "ms";
return 0 ;
}

