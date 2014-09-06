#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void make_file();
void delete_file();
void view_file();
void find_string();
void replace_string();
void rename_file();

void printline();

int main()
{
	printline();
	printf("\t\t\t******Your Handy Text Editor******");
	printline();
	printf("\n");
	
	while(1)
	{
		printf("\t1. File\t\t2. Edit\t\t3. Exit\n\n\t");
		int choice;
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\t(a) Create New\n\t(b) View\n\t(c) Delete\n\t(d) Rename\n\t)");
			        char ch;
			        fflush(stdin);
			        ch=getchar();
			        ch=toupper(ch); 
			
			        if(ch=='A')
			        make_file();
			        
			        else if(ch=='B')
			        view_file();
			
		        	else if(ch=='C')
		        	delete_file();
		        	
		        	else if(ch=='D')
		        	rename_file();
			
			        else printf("\tNot a Valid Option\n");
			        
					break;
			
			
			case 2: printf("\t(a) Find\n\t");
			        fflush(stdin);
			        ch=getchar();
			        ch=toupper(ch); 
			
			        if(ch=='A')
			        find_string();
			        
			        else printf("\tNot a Valid Option\n");
			        
			        break;	
					
					
			default: printf("\tNot a Valid Option\n");
			         break;
			
					
			case 3: return 0;
					       	        
		}
    } 
    
    return 0;
}


void printline()
{
	int i;
	printf("\n");
	for(i=0; i<80; i++)
	printf("-");
	printf("\n");
}


void make_file()
{
	system("cls");
	printf("\tEnter File Name: ");
	char *file_name;
	file_name=(char*)malloc(30);
	fflush(stdin);
	scanf("%s",file_name);
	
	FILE *make_file;
	make_file=fopen(file_name,"w+");
	if(make_file==NULL)
	{
		printf("\tError Creating File\n");
	}
	else printf("\tFile Created Succesfully\n");
	
	printf("\n\tEnter Text to Save in File. Press CTRL+Z+ENTER when DONE!\n\n\t");
	fflush(stdin);
	
	int ch;
	while((ch=fgetc(stdin)) != EOF)
	fputc(ch,make_file);
	fclose(make_file);
	printf("\tText Saved Successfully\n");
	free(file_name);
	return;
}


void view_file()
{
	system("cls");
	printf("\tEnter File Name: ");
	char *file_name;
	file_name=(char*)malloc(30);
	fflush(stdin);
	gets(file_name);
	FILE *view_file;
	
	if((view_file=fopen(file_name,"r"))==NULL)
	printf("\tError Opening a File\n");
	else
	{
		int ch;
		while((ch=fgetc(view_file))!=EOF)
		fputc(ch,stdout);
		fclose(view_file);
	}
	free(file_name);
	return;
}


void delete_file()
{
	system("cls");
	printf("\tEnter File Name to Delete: ");
	char *file_name;
	file_name=(char*)malloc(30);
	fflush(stdin);
	gets(file_name);
	if((remove(file_name))==0)
	printf("\tRemoved Succesfully\n");
	else
	printf("\tError While Deleting\n");
	free(file_name);
	return;
}


void rename_file()
{
	system("cls");
	printf("\tEnter Old File Name: ");
	char *old_name;
	old_name=(char*)malloc(30);
	fflush(stdin);
	gets(old_name);
	printf("\tEnter New File Name: ");
	char *new_name;
	new_name=(char*)malloc(30);
	fflush(stdin);
	gets(new_name);
	if((rename(old_name,new_name))==0)
	printf("\tRenamed File Successfully\n");
	else
	printf("\tError While Renaming\n");
	free(old_name);
	free(new_name);
	return;
}


void find_string()
{
	system("cls");
	printf("\tEnter File Name: ");
	char *file_name;
	file_name=(char*)malloc(30);
	fflush(stdin);
	gets(file_name);
	
	FILE *fp;
	fp=fopen(file_name,"r");
	char *str;
	str=(char*)malloc(30);
	printf("\tEnter String to Find: ");
	fflush(stdin);
	gets(str);
	char temp[1024];
	int line=1;
	while(fgets(temp,1024,fp)!= NULL)
	{
		if((strstr(temp,str))!=NULL)
		{
			printf("Match Found on line %d - %s",line,temp);
		}
			line++;
	}
	
	fclose(fp);
	free(file_name);
	free(str);
}
