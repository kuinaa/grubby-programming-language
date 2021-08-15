/* Mini Programming Language Syntax Analyzer
 * Grubbi Language
 *
 * Bengco, Dana Kirstie
 * Chua, Jericka
 * Tablanza, Krys
 * Waquez, Emerson
 * BSCS 3 - 2
 */
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define null NULL
#include "Grubbyrules.h"


FILE *deriv, *error, *error2;

int errSyn=false;
int firstChild=true;
int firstNode = true;
int pointerIndex = 0;
int tempIndexTree = 0;


struct tokens {
	char lexeme[30];
	char token[15];
	int line;
	struct tokens *next, *prev;
} *head, *tail, *cur, *tempNode=NULL, *headStart = NULL, *marker = NULL;

struct variables
{
	char varLexeme[30];
	char varType[10];
	char varValue[30];
	int isConstant;
	int varUsed;
	int scope;
	variables *next;
}; variables *varHead = NULL, *varCurrent = NULL, *varTail = NULL, *varTemp, *varDelete, *varTemp2;

struct stack {
	char symbol[15];
	struct stack *next;
} *top = NULL, *newNode=NULL, *temp=NULL;

struct parseTree
{
	int rule;
	int line;
	int isTerminal;
	char value[20];
	char type[10];
	char symbol[15];
	char lexeme[30];
	struct parseTree *child, *parent, *sibling, *siblingL;
}; parseTree *treeCurrent = NULL, *tempLeaf1=NULL, *tempLeaf=NULL, *treeRoot=NULL, *tempTree=NULL, *treePointer[500], *temps=NULL;


void clearList();
void updateTree (char token[20], int rule);
void create();
void push(char data[20]);
void pop();
char* topsym();
void display();
int getTops (char tops[15]);
int getToks (char toks[15]);
void parse();
void insertTok();
void insertTok();


void SynMain () {
	char ch;
	printf("READING TOKENS FROM SYMBOL TABLE \n.=========================================\n");
	insertTok();
	char blnk[30]={0};
	strcpy(cur->lexeme,blnk);
	parse();
	cur = head;
	while(cur!=NULL)
	{
		tail = cur;
		cur = cur->next;
		free(tail);
	}
	head=NULL;
	tail=NULL;
	cur=NULL;
	if (errSyn==false){
		
		for(int x = 0; x<pointerIndex;x++)
		{
			strcpy(treePointer[x]->type,"");
			strcpy(treePointer[x]->value,"");
		}
	}
	clearList();
}



void clearList (){
	cur = head;
	while(cur!=NULL)
	{
		tail = cur;
		cur = cur->next;
		free(tail);
	}
	head=NULL;
	tail=NULL;
	cur=NULL;
	struct stack *temp1=NULL;
	while(top!=NULL)
	{
		temp1 = top;
		top = top->next;
		free(temp1);
	}
	top =NULL;
	newNode=NULL;
	temp=NULL;
	temp1=NULL;
	for(int x = 0; x<=pointerIndex;x++)
	{
		if(treePointer[x] != NULL)
		{
			free(treePointer[x]);
			treePointer[x] = NULL;
		}
	}
	treeCurrent = NULL; tempLeaf1=NULL; tempLeaf=NULL; treeRoot=NULL; tempTree=NULL;
	
}

void create(){
    top = NULL;
}

void push(char data[15]){
  	newNode = (struct stack*)malloc(sizeof(struct stack));
   	strcpy(newNode->symbol,data);
   	if(top == NULL)
    	newNode->next = NULL;
   	else
      	newNode->next = top;
   	top = newNode;
}

void pop(){
    if(top == NULL)
      	printf("\nStack is Empty!!!\n");
   	else{
      	temp = top;
      	top = temp->next;
      	free(temp);
   	}
}

char* topsym(){
    return(top->symbol);
}
void display(){
    if(top == NULL)
      	printf("\nStack is Empty!!!\n");
   	else{
      	temp = top;
      	while(temp->next != NULL){
		    fprintf(deriv,"%s ",temp->symbol);
		 	printf("%s ",temp->symbol);
		 	temp = temp -> next;
    	}
      	printf("%s",temp->symbol);
		fprintf(deriv,"%s ",temp->symbol);
   }
 }
 
int getTops (char tops[15]){
	int index=0;
	while (index<29){
		if (strcmp(tops,nterms[index])==0){
			return index;
		}
		index++;
	}
	return -1;
}

int getToks (char toks[15]){
	int index=0;
	while (index<46){
		if (strcmp(toks,terms[index])==0){
			return index;
		}
		index++;
	}	
	return -1;
}
void insertTok(){
	FILE *input;
	input = fopen("SYMBOLTABLE.gruv","r");
	char ch, ch1;
	int started=0;
	while ((ch=fgetc(input))!=EOF){
		char tok[15] = {0};
		char val[30] = {0};
		char line[10] = {0};
		int vals = 0;
		if (started==1){
			val[vals]=ch1;
			vals++;
		}
		started=1;
		while (ch!='\t'){
			val[vals]=ch;
			vals++;
			ch=fgetc(input);
		}
		ch=fgetc(input);
		int toks=0;
		while (ch!='\t'){
			tok[toks]=ch;
			toks++;
			ch=fgetc(input);
		}
		ch=fgetc(input);
		int lines=0;
		while (ch!='\n'){
			line[lines]=ch;
			lines++;
			ch=fgetc(input);
		}
		int lineNo = atoi(line);
			if(head == NULL)
			{
				head = (tokens*)malloc(sizeof(tokens));
				strcpy(head->token,tok);
				strcpy(head->lexeme,val);
				head->line = lineNo;
				head->next=NULL;
				head->prev=NULL;
				tail=head;
				cur = head;
				headStart = head;
			}
			else
			{
				cur = (tokens*)malloc(sizeof(tokens));
				strcpy(cur->token,tok);
				strcpy(cur->lexeme,val);
				cur->line = lineNo;
				cur->next=NULL;
				cur->prev=tail;
				tail->next=cur;
				tail=cur;
			}
			ch1=fgetc(input);
	}
	fclose(input);
}


void updateTree (char token[15], int rule) {
	if(errSyn == false)
	{
		tempLeaf = (parseTree*)malloc(sizeof(parseTree));
		tempIndexTree++;

		tempLeaf->parent = treeCurrent;
												
		strcpy(tempLeaf->symbol,token);	
		strcpy(tempLeaf->lexeme,cur->lexeme);
		tempLeaf->line = cur->line;	
		tempLeaf->isTerminal = false; 
		tempLeaf->rule = rule; 
		tempLeaf->child = NULL;	

		if(firstNode == true)
		{
			tempLeaf1 = tempLeaf; 
			tempLeaf->siblingL = NULL;  
			treeCurrent->child = tempLeaf;
			tempLeaf->sibling = NULL;   
			tempLeaf1->sibling = NULL;
			firstNode = false;
		}
		else
		{
			if (strcmp(tempLeaf->symbol,"VAR_ID")==0)
				strcpy(tempLeaf->lexeme,cur->next->lexeme);
			if (strcmp(tempLeaf->lexeme,"(")==0)
				strcpy(tempLeaf->lexeme,cur->next->next->lexeme);
			if (strcmp(tempLeaf->lexeme,"length")==0)
				strcpy(tempLeaf->lexeme,cur->next->next->lexeme);
			tempLeaf1->sibling = tempLeaf;
			tempLeaf->siblingL = tempLeaf1;
			tempLeaf1 = tempLeaf;
			tempLeaf->sibling = NULL;
			tempLeaf1->sibling = NULL;
		}
        treePointer[pointerIndex++] = tempLeaf;
	}
}

void parse(){
	error = fopen ("SYNTAX ERROR.gruv","w");
	char out[1000]={0};
	deriv = fopen("PROCESS OF PARSING.gruv","w");
//	getch();
	printf("\n-----------------\nTOKENS ARE BEING READ AND BEING ANALYZED BY THE SYNTAX ANALYZER...\n");
	create();
	push("$");
	push("begin");
	cur = head;	
	display();

	treeRoot = (parseTree*)malloc(sizeof(parseTree));
	treeRoot->isTerminal = false;
	strcpy(treeRoot->symbol,"begin");
	strcpy(treeRoot->lexeme,"begin");
	treeRoot->parent = NULL;
	treeRoot->sibling = NULL;
	treeRoot->siblingL = NULL;
	treeRoot->child = NULL;
	treeCurrent = treeRoot;			 

    treePointer[pointerIndex++] = treeCurrent;

	while (top!=NULL){
		fprintf(deriv,"\n");
		printf("\n");
		char *toks = cur->token;	
		char *tops = topsym();

		int isTerm = 0;
		for (int x=0;x<46;x++){
			if (strcmp(tops,terms[x])==0){
				isTerm=1;
				break;
			}
		}
		// TERMINAL TOP---------------------------------------------------
		if (isTerm==1){ 
			if (strcmp(tops,toks)==0){	
				strcat(out,cur->lexeme);
				strcat(out," ");
				
				pop();
				cur=cur->next;
				if (errSyn==false){
					treeCurrent->isTerminal = true;
				}
			
			}
			else if (strcmp(tops,"empty")==0){
				pop();
			}
			else{ 	// ERROR RECOVERY
				errSyn=true;
				char err[100] = {0};
				strcpy(err,getError(tops));
				printf("\n---------- SYNTAX ERROR at line %d : %s is expected but %s is found\n",cur->line,tops,cur->lexeme);
				fprintf(error,"SYNTAX ERROR at line %d : %s is expected but %s is found\n",cur->line,tops,cur->lexeme);
				do {
					if (strcmp(cur->next->token,tops)==0){
						cur=cur->next;
						toks=cur->token;
					}
					else {
						pop();
						tops=topsym();
					}
				} while (strcmp(toks,tops)!=0);
			}
			int isRoot=false;
				if(errSyn == false){
					if(treeCurrent->sibling != NULL){
						treeCurrent = treeCurrent->sibling;
					}
					else {
						while(treeCurrent->sibling == NULL) {
							if(strcmp(treeCurrent->parent->symbol,"begin")==0){
							   isRoot=true;
							   break;
							}
							treeCurrent = treeCurrent->parent;
						}
						if (isRoot==false)
							treeCurrent = treeCurrent->sibling;
					}
				}
		}
		// NONTERMINAL TOP ----------------------------------------------
		else {
			int topsIndex=0, toksIndex=0;
			topsIndex = getTops(tops);
			toksIndex = getToks(toks);
			int rule=parseTable[topsIndex][toksIndex];
			if (rule>=0&&rule<75){
				pop();
				char str[50] = {0};
				strcpy(str,rules[rule]);
				//-------------------------------------------
				int flag=0;
				char *token;
				char *prod[10];
				int qt=0;
				token = strtok(str," ");
				while(token!=NULL)
				{
					
					prod[qt]=token;
					updateTree(prod[qt],rule);
					qt++;
					token = strtok(NULL," ");
					flag++;
				}
				for(int k=qt-1;k>=0;k--){
					push(prod[k]);
				}
					if (errSyn==false){
						treeCurrent = treeCurrent->child;
						firstNode = true;
					}
			}
			else { 	// ERROR RECOVERY
				errSyn=true;
				char err[100] = {0};
				strcpy(err,getError(tops));
				printf("\n---------- SYNTAX ERROR at line %d : %s\n\n", cur->line,err);
				fprintf(error,"SYNTAX ERROR at line %d : %s\n", cur->line,err);
				do {
					cur=cur->next;
					toks = cur->token;

					toksIndex=getToks(toks);
					topsIndex=getTops(tops);
					rule = parseTable[topsIndex][toksIndex];
				} while (rule==-1);
				if (rule==75){ 
					pop();
					cur=cur->next;
				}
			}
		}
		printf (out);
		fprintf(deriv,out);
		display();
	}
	
	if (errSyn==false)
		printf("\n-----------------\n\nSUCCESS!");
	else
		printf("\n-----------------\n\nERROR/S FOUND!");
	fclose(error);
	fclose(deriv);
}

