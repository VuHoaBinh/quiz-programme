#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
// Num of answer
#define num 4

typedef struct Question{
	int id;
	char content[256];
	char answerData[4][100];
	char answer;
}Ques;

struct AVLNODE{
	int balFactor;
	Ques key;
	AVLNODE *left, *right;
};
typedef AVLNODE* tree;

tree CreateNode(Ques x){
	tree p = new AVLNODE;
	if(p == NULL)
		return NULL;
	p->key = x;
	p->left = p->right = NULL;
	p->balFactor = 0;
	return p;
}

void InputQues(Ques &x, int id){
	x.id = id;
	
	printf("Input question: ");fflush(stdin);
	gets(x.content);
	char choice;
	int k;
	for(int i = 0; i < num; i++){
		printf("Input answer %c: ", i+65);
		fflush(stdin);
		gets(x.answerData[i]);
	}
	
	bool flag = false;
	do {
		printf("Correct answer is: ");
		fflush(stdin);
		scanf("%c", &x.answer);
		switch (x.answer) {
			case 'A':
			case 'a':
			case 'B':
			case 'b':
			case 'C': 
			case 'c':
			case 'D':
			case 'd':
				flag = true;
			break;
			default:
				printf ("Please input a,b,c,d (uppercase)!"); 
		}	
	} while (!flag);
}
void OutputQues(Ques x){
	printf("Question %d: %s\n",x.id, x.content);
	for(int i = 0; i < num; i++){
		printf ("%c. %s\n", i + 65, x.answerData[i]);
	}
	printf("\n");
}


void Init(tree &t){
	t = NULL;
}

void LeftRotate(tree &p){
	tree q;
	q = p->right;
	p->right = q->left;
	q->left = p;
	p = q;
}

void RightRotate(tree &p){
	tree q;
	q = p->left;
	p->left = q->right;
	q->right = p;
	p = q;
}

void LeftBalance(tree &p){
	switch(p->left->balFactor){
		case 1:
			RightRotate(p);
			p->balFactor = 0;
			p->right->balFactor = 0;
			break;
		case 2:
			LeftRotate(p->left);
			RightRotate(p);
			switch(p->balFactor){
				case 0:
					p->left->balFactor = 0;
					p->right->balFactor = 0;
					break;
				case 1:
					p->left->balFactor = 0;
					p->right->balFactor = 2;
					break;
				case 2:
					p->left->balFactor = 1;
					p->right->balFactor = 0;
					break;
			}
			p->balFactor = 0;
			break;
	}
}

void RightBalance(tree &p){
	switch(p->right->balFactor){
		case 1:
			RightRotate(p->right);
			LeftRotate(p);
			switch(p->balFactor){
				case 0:
					p->left->balFactor = 0;
					p->right->balFactor = 0;
					break;
				case 1:
					p->left->balFactor = 1;
					p->right->balFactor = 0;
					break;
				case 2:
					p->left->balFactor = 0;
					p->right->balFactor = 2;
					break;
			}
			p->balFactor = 0;
			break;
		case 2:
			LeftRotate(p);
			p->balFactor = 0;
			p->left->balFactor = 0;
			break;
	}
}

//Insert Node
int InsertNode(tree &t, Ques x, int id){
	x.id = id;
	int res;
	if(t == NULL){
		t = CreateNode(x);
		if(t == NULL)
			return -1;
		return 2;
	}
	else{
		if(t->key.id == x.id)
			return 0;
		else if(t->key.id > x.id){
			res = InsertNode(t->left, x, id);
			if(res < 2)
				return res;
			switch(t->balFactor){
				case 0:
					t->balFactor = 1;
					return 2;
				case 1:
					LeftBalance(t);
					return 1;
				case 2:
					t->balFactor = 0;
					return 1;
			}
		}
		else{
			res = InsertNode(t->right, x, id);
			if( res < 2)
				return res;
			switch(t->balFactor){
				case 0:
					t->balFactor = 2;
					return 2;
				case 1:
					t->balFactor = 0;
					return 1;
				case 2:
					RightBalance(t);
					return 1;
			}
		}
	}
}

//Input List
void CreateTree(tree &t){
	int n;
	Ques x;
	Init(t);
	printf("Enter the number of question: "); 
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i ++){
		InputQues(x, i);
		InsertNode(t,x, i);
	}
}

//Ouput List
void NLR(tree t){
	if(t){
		OutputQues(t->key);
		NLR(t->left);
		NLR(t->right);
	}
}

//Read file
void ReadFile(tree &t){
	FILE* fp = fopen("EnglishQuestions.txt","r+");// 
	Ques x;
	if(fp == NULL){
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp, "%d %[^\n]",&x.id, &x.content);
			for (int i = 0; i < num; i++) {
				fscanf(fp, "\n%[^\n]", &x.answerData[i]);
			}
		fscanf(fp, "\n%c", &x.answer);
		InsertNode(t,x,x.id); 
	}
	fclose(fp);	
}

// Write file
bool writeSupport (tree t, FILE *fp) {
	if (t!=NULL) {
		fprintf(fp,"%d %s",t->key.id, t->key.content);
		for (int i = 0; i< num; i++) {
			fprintf(fp, "\n%s", t->key.answerData[i]);
		}
		fprintf (fp, "\n%c\n", t->key.answer);
		writeSupport(t->left, fp);
		writeSupport(t->right, fp);
	}else
		return false;
}

void WriteFile(tree t) {
	FILE * fp = fopen ("EnglishQuestions.txt", "a+");
	Ques x;
	
	if (fp == NULL) {
		exit(1);
	}
	
	bool flag = true;
	while (flag) {
		flag = writeSupport(t, fp);
	}
	
	fclose(fp);
}
// Search
tree searchNodeByID (tree t, int IDSearch) {
	if (t) {
		if(t->key.id == IDSearch) return t;
		else if(t->key.id > IDSearch)
			return searchNodeByID(t->left, IDSearch);
		else
			return searchNodeByID(t->right, IDSearch);
	}
	return NULL;
}

// Update
void updateNodeByID (tree &t, int IDUpdate) {
	tree index = searchNodeByID(t, IDUpdate);
	if (t) {
		if (index) {
			InputQues(t->key, IDUpdate);
			InsertNode(t, t->key, IDUpdate);
		}
	}
}

void Menu(){
	printf(">>>------------------------------------------	MULTI-CHOICE QUESTION MANAGEMENT PROGRAM	------------------------------------------<<<");
	printf("\n1. Enter question list.");
	printf("\n2. Enter question list by File");
	printf("\n3. Export question list.");
	printf("\n4. Search questions by ID.");
	printf("\n5. Update question information by ID.");
	printf ("\n6. Delete questions ");
	printf("\nYour choice: "); 
}

int main(){
	tree t;
	Init(t);
	int key;
	bool entered = false;
	while(true){
		Menu();
		scanf("%d", &key);
		switch(key){
			case 0:
				printf("Goodbye!");
				return 0;
			case 1:
				CreateTree(t);
				WriteFile(t);
				entered = true;
				break;
			case 2:
				ReadFile(t);
				entered = true;
				break;
			case 3:
				if(entered){
					NLR(t);
				}else
					printf("\nPlease enter question list !");
				getch();
				break;
			case 4:
				if(entered){
					int IDSearch;
					printf("\nEnter ID to search: "); scanf("%d", &IDSearch);
					tree result = searchNodeByID(t, IDSearch);
					if(result){
						OutputQues(result->key);
					}else{
						printf("\nQuestion not found!");
					}
				}else
					printf("\nPlease enter question list !");
				getch();
				break;
			case 5:
				if(entered){
					int IDUpdate;
					printf("\nEnter ID to update: "); scanf("%d", &IDUpdate);
					updateNodeByID(t, IDUpdate);
				} else
					printf("\nPlease enter question list !");
				getch();
				break;
			case 6:
				break;
		}
	} 
}


    


