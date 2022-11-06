#include<bits/stdc++.h>
using namespace std;


typedef struct SACH{
	char name_book[20];
	char author[5][20];
	char publisher[30];
	int year;
}SACH;

// tao 1 not
typedef struct NODE{
	SACH data;
	struct NODE *pNext;
}NODE;


// tao 1 cau truc danh sach
typedef struct LIST{
	NODE *pHead;
	NODE *pTail;
}LIST;

// khoi tao
void init(LIST &L){
	L.pHead = L.pTail  = NULL;
}

// tao 1 NODE
NODE *getNode(SACH s){
	NODE *p = new NODE;
	if(p==NULL){
		cout <<"ERROR"<< endl;
		return NULL;
	}
	p->data = s;
	p->pNext = NULL;
	return p; 
}

//chem 1 NODE vao dau danh
void ADDHEAD(LIST &L, NODE *new_node ){
	if(L.pHead == NULL){
		L.pHead = L.pTail = new_node;
	}else
		new_node->pNext =L.pHead;
		L.pHead = new_node ;	
}

// chem 1 phan tu vao dau danh sach
void INSERT_FIRST(LIST &L, SACH &s){
	NODE *new_node = getNode(s);
	if(new_node!=NULL){
		ADDHEAD(L,new_node);
	}
}

// nhap sach
void input(SACH &a){
	int choice;
	int authors;
	cout << "Do you want to add more books and how many?";fflush(stdin);
	cin >> choice;
	for ( int l = 1; l <= choice; l++){
		printf("Name book?");fflush(stdin);
		gets(a.name_book);
		printf("How many book's authors are there?(MAX = 5)");
		do{
			scanf("%d",&authors);
		}while (authors >5 || authors <0);
		for ( int i = 0; i < authors;i++){
			printf("Name author %d?",i+1);fflush(stdin);
			gets(a.author[i]);
		}
	}
	printf("Publisher?");fflush(stdin);
	gets(a.publisher);
	printf("Year?");
	scanf("%d",&a.year);	
}

// tao 1 danh sach bang lien ket cac phan tu
void Create_List(LIST &L,SACH &s){
	SACH s;
	char answer[5];
	while(1){
		input(s);
		INSERT_FIRST(L,s); 
		cout <<"Are you inputing the information? (Y/N)";fflush(stdin);
		gets(answer);
		if(strcmp(answer,"Y") or strcmp(answer,"Yes")){
			break;
		}
	}
}

// cancel
void cancel_list(LIST &L){
	for(NODE *p=L.pHead;p!=NULL;p=p->pNext ){
		NODE *k=L.pHead ;
		L.pHead = k->pNext ;
		delete(k);
	}
	L.pTail = NULL;
}


int main(){
	
	return 0;    
}












