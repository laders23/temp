#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum OPTION{
	Null,
	HELP,
	LIST,
	LISTCOUNT,
	REPLACE,
	ANALYSIS,
} OPTION;

void list(){
	char buff[256];
	FILE* fp = fopen("analysis.c","r");

	while(!feof(fp)){
		fgets(buff,256,fp);
		printf("%s",buff);
	}
	printf("\n");

}

void listcount(){
	int count = 0;
	char buff[256];
	FILE* fp = fopen("analysis.c","r");

	while(!feof(fp)){
		fgets(buff,256,fp);
		count++;
	}
	printf("total line count = %d\n",count);
}

void replace(){
	char buff[255];
	char buff_copy[255];

	int count = 0;
	FILE* fp = fopen("analysis.c","r");
	FILE* copy_fp = fopen("copy.txt","a");
	while(!feof(fp)){
		fgets(buff,255,fp);
	char* p = strstr(buff,"int ");
	if(p){
		strncpy(p,"double ",7);
		count++;
	}
	fputs(buff,copy_fp);
	}
	fclose(fp);
	fclose(copy_fp);

	FILE* open_copy = fopen("copy.txt","r");
	while((fgets(buff_copy,255,copy_fp) != NULL))
		printf("%s",buff_copy);
	printf("total change int->double : %d \n",count);
}

void analysis(){
	FILE* fp = fopen("analysis.c","r");
	int count_variable = 0, count_void = 0;
	char buff[255];
	while(!feof(fp)){
		fgets(buff,255,fp);
		if(strstr(buff,"int ")!=NULL)
			count_variable++;
		if(strstr(buff,"double ")!=NULL)
			count_variable++;
		if(strstr(buff,"void")!=NULL){
			count_void++;
		}
	}
	printf("count variable : %d\n",count_variable);
	printf("count void : %d\n",count_void);
}

void option_handler(OPTION opt){
	int count = 0;
	switch(opt){
		case Null:
		printf("input option\n");
			break;
		case HELP:
			printf("file_name -help = explain this function\n");
			printf("file_name -list = this source code print\n");
			printf("file_name -linecount = this source code line count\n");
			printf("file_name -replace = int convert to double\n");
			printf("file_name -analysis = count using variable\n");
			break;
		case LIST:
			list();
			break;
		case LISTCOUNT:
			listcount();
			break;
		case REPLACE:
			replace();
			break;
		case ANALYSIS:
			analysis();
			break;
		default:
			break;
	}
}

/*void line_count(){
	while(eof == 0){
	
	}
	}*/

int g_value = 10;

void func1() {
	printf("i'm function 1\n");
	
}

void func2() {
	printf("i'm function 2\n");
}

double g_dbl_value = 20;

void main(int argc, char* argv[]) {
	if(argc == 1){
	if(strcmp(argv[0],argv[0])==0)	
		option_handler(Null);
	}

	if(argc == 2){
		if(strcmp(argv[1], "-help")==0)
			option_handler(HELP);
	}

	if(argc == 3){
		if(strcmp(argv[1],"-list") == 0 && strcmp(argv[2],"analysis.c") == 0)	
			option_handler(LIST);
		else if(strcmp(argv[1], "-listcount") == 0 && strcmp(argv[2], "analysis.c") == 0)
			option_handler(LISTCOUNT);
			}
	if(argc == 5){
		if(strcmp(argv[1], "-replace") == 0 && strcmp(argv[2],"analysis.c")==0 &&strcmp(argv[3],"int")== 0 && strcmp(argv[4],"double") == 0)
			option_handler(REPLACE);
	}
	if(argc == 3){
		if(strcmp(argv[1], "-analysis") == 0 && strcmp(argv[2],"analysis.c") == 0)
			option_handler(ANALYSIS);
	}
	
	int data1 = 10;
	int data2 = 20;
	int data3 = data1 * data2;	

	double dbl_data = 1.1;


	func1();
	func2();

	printf("%d %lf\n",data3, dbl_data);
	
	}

