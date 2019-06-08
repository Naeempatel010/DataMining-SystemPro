#include<stdio.h>
#include<string.h>
char op[2],arg1[5],arg2[5],result[5];
void main()
{
	FILE *fp1,*fp2;
	fp1 = fopen("input.txt","r");
	fp2 = fopen("output.txt","w");

	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s",op,arg1,arg2,result);

		fprintf(fp2,"\nMOV AX,@data,\n INT 21h\n");
		if(strcmp(op,"+")==0)
		{
			fprintf(fp2,"\nMOV BX,%s ,\nMOV CX, %s,\n ADD BX,CX ,\n MOV AH,09h \n INT 21h\n",arg1,arg2);


		}
		else if(strcmp(op,"-")==0)
		{
			fprintf(fp2,"MOV BX,%s ,\nMOV CX, %s,\n SUB BX,CX ,\n MOV AH,09h \n INT 21h\n",arg1,arg2);
		}
		else if(strcmp(op,"*")==0)
		{
			fprintf(fp2,"MOV AX,%s ,\nMOV BX, %s,\n MUL BX ,\n MUL AH,09h \n INT 21h\n",arg1,arg2);
		}
		
		else if(strcmp(op,"/")==0)
		{
				fprintf(fp2,"MOV AX,%s ,\nMOV BX, %s,\n DIV BX ,\n MOV AH,09h \n INT 21h\n",arg1,arg2);
		}		
		else{

			fprintf(fp2, "BAD OBJECT FILE");
		}
	}

	fclose(fp1);
	fclose(fp2);


}