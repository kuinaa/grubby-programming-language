/* Mini Programming Language Lexical Analyzer
 * Grubbi Language
 *
 * Bengco, Dana Kirstie
 * Chua, Jericka
 * Tablanza, Krys
 * Waquez, Emerson
 * BSCS 3 - 2
 */
 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "GrubbySyntax.cpp"

FILE *input, *lexError, *tokens;

struct node {
	char data;
	struct node *next;
} *head2, *tail2, *cur2;

int line=1;
int errLex = 0;

void clearLex();
void insert1(char data);
void lexicalnew();
void identifier();

void insert1(char data){
	cur2 = (node *) malloc(sizeof(node));
	cur2->data = data;
	cur2->next = NULL;

	if (head2 == NULL) {
		head2 = cur2;
	}
	else {
		tail2->next = cur2;
	}
	tail2 = cur2;
}

void Lexicalnew() {
	
	lexError = fopen ("LexerErrors.gruv","w");
	
	tokens = fopen ("SYMBOLTABLE.gruv","w");
	
	cur2=head2;
	
	while(cur2 != NULL) {
		
		
		if (cur2->data == '\n') {
			cur2 = cur2 -> next;
			line++;
		}
		
		else if (cur2->data=='\t') {
			cur2 = cur2->next;
		}
		
		else if (cur2->data==' '){
			cur2 = cur2->next;
		}
		else if (cur2->data=='^'){
			cur2=cur2->next;
			if (cur2->data=='l'){
				cur2=cur2->next;
				if (cur2->data=='n'){
					fprintf(tokens,"^ln\tNEWLINE\t%d\n",line);
					cur2=cur2->next;
				}
				else {
					errLex = 1;
					fprintf(lexError,"Line %d: ^n",line);
					int flag =0;
					while (flag==0) {
						fputc(cur2->data,lexError);
						cur2 = cur2->next;
						if (cur2->data=='\n'||cur2->data=='\t'||cur2->data==' ')
							flag=1;
					}
					fprintf(lexError," not recognized\n");
				}
			}
			else if (cur2->data=='h'){
				cur2=cur2->next;
				if (cur2->data=='t'){
					fprintf(tokens,"^ht\tTAB\t%d\n",line);
					cur2=cur2->next;
				}
				else {
					errLex = 1;
					fprintf(lexError,"Line %d: ^h",line);
					int flag =0;
					while (flag==0) {
						fputc(cur2->data,lexError);
						cur2 = cur2->next;
						if (cur2->data=='\n'||cur2->data=='\t'||cur2->data==' ')
							flag=1;
					}
					fprintf(lexError," not recognized\n");
				}
			}
			else if (isdigit(cur2->data)||cur2->data==' '||cur2->data=='\n'){
				fprintf(tokens,"^\tEXP\t%d\n",line);
			}
			else {
				errLex = 1;
				fprintf(lexError,"Line %d: ^",line);
				int flag =0;
				while (flag==0) {
					fputc(cur2->data,lexError);
					cur2 = cur2->next;
					if (cur2->data=='\n'||cur2->data=='\t'||cur2->data==' ')
						flag=1;
				}
				fprintf(lexError," not recognized\n");
			}
		}
		else if (cur2->data == 'b'){
			fprintf(tokens,"b");
			cur2 = cur2->next;
			if (cur2->data == 'o'){
				fprintf(tokens,"o");
				cur2 = cur2->next;
				if (cur2->data=='o'){
					fprintf(tokens,"o");
					cur2 = cur2->next;
					if (cur2->data=='l'){
						fprintf(tokens,"l");
						cur2 = cur2->next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
							|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
							|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
							|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
							|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
							|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tBOOL\t%d\n",line);
						}
						else {
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2->data=='l'){
			fprintf(tokens,"l");
			cur2=cur2->next;
			if (cur2->data=='e'){
				fprintf(tokens,"e");
				cur2=cur2->next;
				if (cur2->data=='n'){
					fprintf(tokens,"n");
					cur2=cur2->next;
					if (cur2->data=='g'){
						fprintf(tokens,"g");
						cur2=cur2->next;
						if(cur2->data=='t'){
							fprintf(tokens,"t");
							cur2=cur2->next;
							if (cur2->data=='h'){
								fprintf(tokens,"h");
								cur2=cur2->next;
								if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
									|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
									|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
									|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
									|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
									|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
									fprintf(tokens,"\tLENGTH\t%d\n",line);
								}
								else{
									identifier();
								}
							}
							else {
								identifier();
							}
						}
						else{
							identifier();
						}
					}
					else{
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2 -> data == 'c'){
			fprintf(tokens,"Line %d: c",line);
			cur2 = cur2 -> next;
			if (cur2 -> data == 'h'){
				fprintf(tokens,"h");
				cur2 = cur2 -> next;
				if (cur2 -> data == 'a'){
					fprintf(tokens,"a");
					cur2 = cur2 -> next;
					if (cur2 -> data == 'r'){
						fprintf(tokens,"r");
						cur2 = cur2 -> next;						
							if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
									|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
									|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
									|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
									|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
									|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tCHAR\n");							
						}
						else identifier();
					}
					else identifier();
				}
				else identifier();
			}
			else if (cur2 -> data == 'o'){
				fprintf(tokens,"o");
				cur2 = cur2 -> next;
				if (cur2 -> data == 'n'){
					fprintf(tokens,"n");
					cur2 = cur2 -> next;
					if (cur2 -> data == 's'){
						fprintf(tokens,"s");
						cur2 = cur2 -> next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
									|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
									|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
									|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
									|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
									|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tCONS\n");
						}
						else identifier();
					}
					else identifier();
				}
				else identifier();
			}
		}
		else if (cur2->data == 'e'){
			fprintf(tokens,"e");
			cur2 = cur2->next;
			if (cur2->data=='l') {
				fprintf(tokens,"l");
				cur2 = cur2->next;
				if (cur2->data=='s') {
					fprintf(tokens,"s");
					cur2 = cur2->next;
					if (cur2->data=='i'){
						fprintf(tokens,"i");
						cur2 = cur2->next;
						if (cur2->data=='f'){
							fprintf(tokens,"f");
							cur2 = cur2->next;
							if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
								|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
								|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
								|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
								|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
								|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
									fprintf(tokens,"\tELSIF\t%d\n",line);
							}
							else {
								identifier();
							}
						}
						else {
							identifier();
						}
					}
					else if (cur2->data=='e'){
						fprintf(tokens,"e");
						cur2 = cur2->next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
							|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
							|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
							|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
							|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
							|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
								fprintf(tokens,"\tELSE\t%d\n",line);
						}
						else {
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}

		else if(cur2->data == 'f'){
			fprintf(tokens,"f");
			cur2=cur2->next;
			if (cur2->data=='a'){
				fprintf(tokens,"a");
				cur2=cur2->next;
				if (cur2->data=='l'){
					fprintf(tokens,"l");
					cur2=cur2->next;
					if (cur2->data=='s'){
						fprintf(tokens,"s");
						cur2=cur2->next;
						if (cur2->data=='e'){
							fprintf(tokens,"e");
							cur2=cur2->next;
							if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
								|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
								|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
								|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
								|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
								|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
								fprintf(tokens,"\tFALSE\t%d\n",line);
							}
							else {
								identifier();
							}
						}
						else{
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2->data=='i'){
			fprintf(tokens,"i");
			cur2=cur2->next;
			if(cur2->data=='f'){
				fprintf(tokens,"f");
				cur2=cur2->next;
				if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
					|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
					|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
					|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
					|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
					|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
					fprintf(tokens,"\tIF\t%d\n",line);
				}
				else {
					identifier();
				}
			}
			else if (cur2->data=='n'){
				fprintf(tokens,"n");
				cur2=cur2->next;
				if (cur2->data=='p'){
					fprintf(tokens,"p");
					cur2=cur2->next;
					if (cur2->data=='u'){
						fprintf(tokens,"u");
						cur2=cur2->next;
						if (cur2->data=='t'){
							fprintf(tokens,"t");
							cur2=cur2->next;
							if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
								|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
								|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
								|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
								|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
								|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
								fprintf(tokens,"\tINPUT\t%d\n",line);
							}
							else{
								identifier();
							}
						}
						else{
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else if (cur2->data=='t'){
					fprintf(tokens,"t");
					cur2=cur2->next;
					if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
						|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
						|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
						|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
						|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
						|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
						fprintf(tokens,"\tINT\t%d\n",line);
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2->data=='o'){
			fprintf(tokens,"o");
			cur2=cur2->next;
			if (cur2->data=='u'){
				fprintf(tokens,"u");
				cur2=cur2->next;
				if (cur2->data=='t'){
					fprintf(tokens,"t");
					cur2=cur2->next;
					if (cur2->data=='p'){
						fprintf(tokens,"p");
						cur2=cur2->next;
						if(cur2->data=='u'){
							fprintf(tokens,"u");
							cur2=cur2->next;
							if (cur2->data=='t'){
								fprintf(tokens,"t");
								cur2=cur2->next;
								if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
									|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
									|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
									|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
									|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
									|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
									fprintf(tokens,"\tOUTPUT\t%d\n",line);
								}
								else{
									identifier();
								}
							}
							else {
								identifier();
							}
						}
						else{
							identifier();
						}
					}
					else{
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		
		else if (cur2->data=='r'){
			fprintf(tokens,"r");
			cur2=cur2->next;
			if (cur2->data=='e'){
				fprintf(tokens,"e");
				cur2=cur2->next;
				if (cur2->data=='a'){
					fprintf(tokens,"a");
					cur2=cur2->next;
					if (cur2->data=='l'){
						fprintf(tokens,"l");
						cur2=cur2->next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
							|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
							|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
							|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
							|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
							|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tREAL\t%d\n",line);
						}
						else{
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2->data=='s'){
			fprintf(tokens,"s");
			cur2=cur2->next;
			if (cur2->data=='t'){
				fprintf(tokens,"t");
				cur2=cur2->next;
				if (cur2->data=='o'){
					fprintf(tokens,"o");
					cur2=cur2->next;
					if(cur2->data=='p'){
						fprintf(tokens,"p");
						cur2=cur2->next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
							|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
							|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
							|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
							|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
							|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tSTOP\t%d\n",line);
						}
						else {
							identifier();
						}
					}
					else{
						identifier();
					}
				}
				else if (cur2->data=='r'){
					fprintf(tokens,"r");
					cur2=cur2->next;
					if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
						|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
						|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
						|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
						|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
						|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
						fprintf(tokens,"\tSTR\t%d\n",line);
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}

		else if (cur2->data=='t'){
			fprintf(tokens,"t");
			cur2=cur2->next;
			if (cur2->data=='r'){
				fprintf(tokens,"r");
				cur2=cur2->next;
				if (cur2->data=='u'){
					fprintf(tokens,"u");
					cur2=cur2->next;
					if (cur2->data=='e'){
						fprintf(tokens,"e");
						cur2=cur2->next;
						if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
							|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
							|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
							|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
							|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
							|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
							fprintf(tokens,"\tTRUE\t%d\n",line);
						}
						else{
							identifier();
						}
					}
					else{
						identifier();
					}
				}
				else{
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		else if (cur2->data=='w'){
			fprintf(tokens,"w");
			cur2=cur2->next;
			if (cur2->data=='h'){
				fprintf(tokens,"h");
				cur2=cur2->next;
				if (cur2->data=='i'){
					fprintf(tokens,"i");
					cur2=cur2->next;
					if (cur2->data=='l'){
						fprintf(tokens,"l");
						cur2=cur2->next;
						if (cur2->data=='e'){
							fprintf(tokens,"e");
							cur2=cur2->next;
							if (cur2->data == ' ' || cur2->data == '/' || cur2->data == '<' || cur2->data == '>' || cur2->data == '='
								|| cur2->data == '!' || cur2->data == '|' || cur2->data == '&' || cur2->data == ';' 
								|| cur2->data == '\"' || cur2->data == ')' || cur2->data == '(' || cur2->data == '}' 
								|| cur2->data == '{' || cur2->data == ',' || cur2->data == ']' || cur2->data == '[' 
								|| cur2->data == '+' || cur2->data == '-' || cur2->data == '*' || cur2->data == '%' 
								|| cur2->data == '^' || cur2->data == '\n' || cur2->data == '\t'){
								fprintf(tokens,"\tWHILE\t%d\n",line);
							}
							else {
								identifier();
							}
						}
						else {
							identifier();
						}
					}
					else {
						identifier();
					}
				}
				else {
					identifier();
				}
			}
			else {
				identifier();
			}
		}
		
		else if (cur2->data == '/'){
			cur2=cur2->next;
			if (cur2->data == '/'){	
				cur2=cur2->next;
				while (cur2->data!='/'){
					cur2=cur2->next;
				};
				cur2=cur2->next;
				cur2=cur2->next;
			}
			else {
				fprintf(tokens,"/\tDIV\t%d\n",line);
			}
		}
		
		else if (cur2->data=='<'){
			fprintf(tokens,"<");
			cur2=cur2->next;
			if (cur2->data=='='){
				fprintf(tokens,"=\tLTE\t%d\n",line);
				cur2=cur2->next;
				if (cur2->data=='-') {
					fprintf(tokens,"-");
					cur2=cur2->next;
				}
				else if (cur2->data==' '){
					cur2 = cur2->next;
				 	if (cur2->data=='-') {
						fprintf(tokens,"-");
						cur2=cur2->next;
					}
				}
			}
			else {
				fprintf(tokens,"\tLT\t%d\n",line);
				
				if (cur2->data=='-') {
					fprintf(tokens,"-");
					cur2=cur2->next;
				}
				else if (cur2->data==' '){
					cur2 = cur2->next;
				 	if (cur2->data=='-') {
						fprintf(tokens,"-");
						cur2=cur2->next;
					}
				}
			}
		}
		else if (cur2->data=='>'){
			fprintf(tokens,">");
			cur2=cur2->next;
			if (cur2->data=='='){
				fprintf(tokens,"=\tGTE\t%d\n",line);
				cur2=cur2->next;
				if (cur2->data=='-') {
					fprintf(tokens,"-");
					cur2=cur2->next;
				}
				else if (cur2->data==' '){
					cur2 = cur2->next;
				 	if (cur2->data=='-') {
						fprintf(tokens,"-");
						cur2=cur2->next;
					}
				}
			}
			else {
				fprintf(tokens,"\tGT\t%d\n",line);
				if (cur2->data=='-') {
					fprintf(tokens,"-");
					cur2=cur2->next;
				}
				else if (cur2->data==' '){
					cur2 = cur2->next;
				 	if (cur2->data=='-') {
						fprintf(tokens,"-");
						cur2=cur2->next;
					}
				}
			}
		}
		else if (cur2->data=='='){
			fprintf(tokens,"=");
			cur2=cur2->next;
			if (cur2->data=='='){
				fprintf(tokens,"=\tEQ\t%d\n",line);
				cur2=cur2->next;
			}
			else if (cur2->data=='-') {
				fprintf(tokens,"\tEQUALS\t%d\n",line);;
				fprintf(tokens,"-");
				cur2=cur2->next;
			}
			else if (cur2->data==' '){
				cur2 = cur2->next;
			 	if (cur2->data=='-') {
			 		fprintf(tokens,"\tEQUALS\t%d\n",line);
					fprintf(tokens,"-");
					cur2=cur2->next;
				}
				else{
					fprintf(tokens,"\tEQUALS\t%d\n",line);
				}
			}
			else {
				fprintf(tokens,"\tEQUALS\t%d\n",line);
			}
		}
			
		else if (cur2->data=='!'){
			fprintf(tokens,"!");
			cur2=cur2->next;
			if (cur2->data=='='){
				fprintf(tokens,"=\tNEQ\t%d\n",line);
				cur2=cur2->next;
			}
			else {
				fprintf(tokens,"\tNOT\t%d\n",line);
			}
		}
		
		else if (cur2->data=='|'){
			cur2=cur2->next;
			if (cur2->data=='|'){
				fprintf(tokens,"||\tOR\t%d\n",line);
				cur2=cur2->next;
			}
			else {
				errLex = 1;
				fprintf(lexError,"Line %d: single '|' character invalid\n", line);
			}
		}
		else if (cur2->data=='&'){
			cur2=cur2->next;
			if (cur2->data=='&'){
				fprintf(tokens,"&&\tAND\t%d\n",line);
				cur2=cur2->next;
			}
			else {
				errLex = 1;
				fprintf(lexError,"Line %d: single '&' character invalid\n",line);
			}
		}
		else if (cur2->data==';'){
			fprintf(tokens,";\tSEMI\t%d\n",line);
			cur2=cur2->next;
		}
		else if (cur2->data=='\"'){
			fprintf(tokens,"\"",line);
			cur2=cur2->next;
				while (cur2->data!='\"'){
					if (cur2->data=='^'){
						cur2=cur2->next;
						if (cur2->data=='n'){
							cur2=cur2->next;
							if (cur2->data=='l'){
								fprintf(tokens,"\"\tSTR_VAL\t%d\n",line);
								fprintf(tokens,"^nl\tNEWLINE\t%d\n\"",line);
								cur2=cur2->next;
							}
							else {
								fprintf(tokens,"^n%c",cur2->data);
							}
						}
						else if (cur2->data=='h'){
							cur2=cur2->next;
							if (cur2->data=='t'){
								fprintf(tokens,"\tSTR_VAL\t%d\n",line);
								fprintf(tokens,"^ht\tTAB\t%d\n\"",line);
								cur2=cur2->next;
							}
							else {
								fprintf(tokens,"^h%c",cur2->data);
							}
						}
						else {
							fprintf(tokens,"^%c",cur2->data);
						}
					}
					fputc(cur2->data,tokens);
					cur2=cur2->next;
				};
				fprintf(tokens,"\"\tSTR_VAL\t%d\n",line);
				cur2=cur2->next;
		}

		else if (cur2->data=='\''){
			fprintf(tokens,"\'");
			cur2=cur2->next;
				while (cur2->data!='\''){
					fputc(cur2->data,tokens);
					cur2=cur2->next;
				};
				fprintf(tokens,"\'\tCHAR_VAL\t%d\n",line);
				cur2=cur2->next;
		}
		
		// ',' ------------------------------------------------------------------
		else if (cur2->data==','){
			fprintf(tokens,",\tCMSEP\t%d\n",line);
			cur2=cur2->next;
		}
		else if (cur2->data=='+'){
			fprintf(tokens,"+\tPLUS\t%d\n",line);
			cur2=cur2->next;
		}
		else if (cur2->data=='-'){
			fprintf(tokens,"-\tMINUS\t%d\n",line);
			cur2=cur2->next;
		}
		else if (cur2->data=='*'){
			fprintf(tokens,"*\tMULTI\t%d\n",line);
			cur2=cur2->next;
		}
		
		else if (cur2->data=='%'){
			fprintf(tokens,"%%\tMOD\t%d\n",line);
			cur2=cur2->next;
		}
		
		else if (cur2->data=='('){
			fprintf(tokens,"(\tLPRN\t%d\n",line);
			cur2=cur2->next;
		
			if (cur2->data=='-') {
				fprintf(tokens,"-");
		
				cur2=cur2->next;
			}
			else if (cur2->data==' '){
				cur2 = cur2->next;
			 	if (cur2->data=='-') {
					fprintf(tokens,"-");

					cur2=cur2->next;
				}
			}
		}
		
		// ')' ------------------------------------------------------------------
		else if (cur2->data==')'){
			fprintf(tokens,")\tRPRN\t%d\n",line);
			cur2=cur2->next;
		}
		else if (cur2->data=='{'){
			fprintf(tokens,"{\tLBRC\t%d\n",line);
			cur2=cur2->next;
		}
		
		// '}' ------------------------------------------------------------------
		else if (cur2->data=='}'){
			fprintf(tokens,"}\tRBRC\t%d\n",line);
			cur2=cur2->next;
		}
		
		else if (isdigit(cur2->data)){
			int check;
			while(cur2->data != ' ' && cur2->data != '/' && cur2->data != '<' && cur2->data != '>' && cur2->data != '='
				&& cur2->data != '!' && cur2->data != '|' && cur2->data != '&' && cur2->data != ';' 
				&& cur2->data != '\"' && cur2->data != ')' && cur2->data != '(' && cur2->data != '}' 
				&& cur2->data != '{' && cur2->data != ',' && cur2->data != ']' && cur2->data != '[' 
				&& cur2->data != '+' && cur2->data != '-' && cur2->data != '*' && cur2->data != '%' 
				&& cur2->data != '^' && cur2->data != '\n' && cur2->data != '\t' && !isalpha(cur2->data)) {
				if (cur2->data=='.') {
					check=1;
				}
					fputc(cur2->data,tokens);
					cur2=cur2->next;
			};
			if (check==1){
				fprintf(tokens,"\tREAL_VAL\t%d\n",line);
				check=0;
			}
			else {
				fprintf(tokens,"\tINT_VAL\t%d\n",line);
			}
		}
		
			
			else {
			if (cur2->data >= 'A' && cur2->data <= 'Z') {
				identifier();
		   	}
		   	else if (cur2->data >= 'a' && cur2->data <= 'z'){
				identifier();
			}
			else {
				errLex = 1;
				fprintf(lexError, "Line %d: %c not recognized\n",line,cur2->data);
				cur2 = cur2->next;
			}
		}
	
	}
	
	fprintf(tokens,"$\t$\t0\n");
	fprintf(tokens,"@");
	fclose(lexError);
	fclose(tokens);
}

void identifier(){
	
	while(cur2->data != ' ' && cur2->data != '/' && cur2->data != '<' && cur2->data != '>' && cur2->data != '='
	&& cur2->data != '!' && cur2->data != '|' && cur2->data != '&' && cur2->data != ';' 
	&& cur2->data != '\"' && cur2->data != ')' && cur2->data != '(' && cur2->data != '}' 
	&& cur2->data != '{' && cur2->data != ',' && cur2->data != ']' && cur2->data != '[' 
	&& cur2->data != '+' && cur2->data != '-' && cur2->data != '*' && cur2->data != '%' 
	&& cur2->data != '^' && cur2->data != '\n' && cur2->data != '\t' && cur2->data !='.') {
		fputc(cur2->data,tokens);
		cur2=cur2->next;
	};
		fprintf(tokens,"\tVAR_ID\t%d\n",line);
}

void clearLex(){
	cur2 = head2;
	while(cur2!=NULL)
	{
		tail2 = cur2;
		cur2 = cur2->next;
		free(tail2);
	}
	head2=NULL; free(head2);
	tail2=NULL; free(tail2);
	cur2=NULL;	free(cur2);
}
// MAIN ----------------------------------------------------------------------------
int main(){
	char ch;
	char filename[20];
	printf("Enter file name: ");
	scanf("%[^\n]c",filename);
	strcat(filename, ".gruv");
	printf("ENTERING THE LEXER =================================>\n\n",filename);
	input = fopen(filename,"r");
	if (input!=null){
			
		while ((ch=fgetc(input))!=EOF){
			insert1(ch);
			printf("%c",ch);
		}
		cur2 = (node *) malloc(sizeof(node));
		cur2->data = ' ';
		cur2->next = NULL;
	
		if (head2 == NULL) {
			head2 = cur2;
		}
		else {
			tail2->next = cur2;
		}
		tail2 = cur2;
		fclose(input);
		Lexicalnew();
		clearLex();
		getch();
		if (errLex==0) {
			printf("\n\n\n.NO ERRORS FOUND ===========> PROCEEDING TO GRUBBY SYNTAX ANALYZER\n");
			SynMain();
		}
		else {
			printf("SORRY ERROR DETECTED PLEASE CHECK LEXERERROR.gruv");

		}
	}
	else {
		printf("FILE NOT FOUND!");
		
	}
	return 0;
}
