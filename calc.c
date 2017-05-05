#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	double result =0 ;
	int (*op)(int,int);	
	
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				op = add;
				break;
				case '-':
				op = minus;
				break;
				case '*':
				op = mul;
				break;
				case '/':
				op = div;
				break;
			}		
			result = op(operand1,operand2);
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

