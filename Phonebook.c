#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort1();
struct entry
{
	char fname[20];
	char lname[20];
	char pnum[11];
	struct entry* next;
};

FILE *fp;

struct entry* getnode()
{
	return((struct entry*)(malloc(sizeof(struct entry))));
}

struct entry* start=NULL;

void create()
{
  int c,t,i=1;
  struct entry* temp;
	printf("\nEnter 10 entries.\n");
      do
       {
	do
	{
	printf("\n%d.",i);
	if(start==NULL)
	{
	start=getnode();
	temp=start;
	printf("\t\nEnter First Name:");
	scanf("%s",start->fname);
	
	printf("\t\nEnter Last Name:");
	scanf("%s",start->lname);
	do
	{
	printf("\t\nEnter Phone Number:");
	scanf("%s",start->pnum);
	if(strlen(start->pnum)!=10)
	{
	printf("\nPlease Enter Valid Phone Number!\n");
	}
	}while(strlen(start->pnum)!=10);
	temp->next=NULL;
	}

 
	else
	{

	temp->next=getnode();
	temp=temp->next;
	printf("\t\nEnter First Name:");
	scanf("%s",temp->fname);
	
	printf("\t\nEnter Last Name:");
	scanf("%s",temp->lname);
	
	printf("\t\nEnter Phone Number:");
	scanf("%s",temp->pnum);
	}
	i++;	
	}while(i<=3);   
	temp->next=NULL;
	
	 do
	  {
	   printf("\nDo you want to continue?\nYES:1\tNO:0\n");
	   scanf("%d",&c);
	   if(c!=1 && c!=0)
	   {
		printf("\nInvalid Input!\n");
	   }
	  }while(c!=1 && c!=0);
      }while(c!=0);
}

void writefile()
{
	struct entry* temp;
	temp=start;
	int i=1;
        fp=fopen("PhoneBook.csv","w");

	if(start==NULL)
	{
	
	}
	else
	{
		while(temp!=NULL)
		{
		fprintf(fp,"%s",temp->fname);
		fprintf(fp,",");
		fprintf(fp,"%s",temp->lname);
		fprintf(fp,",");
		fprintf(fp,"%s\n",temp->pnum);
		temp=temp->next;
		}
	}

 fclose(fp);
}

void display()
{
	struct entry* temp;
	temp=start;
	int i=1;

	if(start==NULL)
	{
		printf("\nThe phonebook is empty.\n");
	}

	else
	{
		printf("\nThe phonebook is:\n");
		
		while(temp!=NULL)
		{
		printf("\n\t%d.",i++);
		printf("\n\tFirst Name: %s",temp->fname);
		printf("\n\tLast Name: %s ",temp->lname);
		printf("\n\tPhone Number:%s ",temp->pnum);
		printf("\n");
		temp=temp->next;
		}
	}
}

void sort1()
{
	int t, flag=0;
	struct entry *curr, *loop;
	char t_fname[20];
	char t_lname[20];
	char t_pnum[11];

	curr=start; 

	while(curr->next!=NULL)
	{
	loop=curr->next;

	  while(loop->next!=NULL || flag<1)
	  {
	  flag++;
	  
	  t=strcmp(curr->fname,loop->fname);

          if(t>0)  // If second is smaller swap
          {
 	   strcpy(t_fname,curr->fname);
	   strcpy(t_lname,curr->lname);
	   strcpy(t_pnum,curr->pnum);

	   strcpy(curr->fname,loop->fname);	
	   strcpy(curr->lname,loop->lname);
	   strcpy(curr->pnum,loop->pnum);


	   strcpy(loop->fname,t_fname);
	   strcpy(loop->lname,t_lname);
	   strcpy(loop->pnum,t_pnum);

		
	  }
	  
	   if(loop->next!=NULL)
	    loop=loop->next;

	  }
	  
	 
	  t=strcmp(curr->fname,loop->fname);
          if(t>0)  // If second is smaller swap
           {
 	   strcpy(t_fname,curr->fname);
	   strcpy(t_lname,curr->lname);
	   strcpy(t_pnum,curr->pnum);

	   strcpy(curr->fname,loop->fname);	
	   strcpy(curr->lname,loop->lname);
	   strcpy(curr->pnum,loop->pnum);


	   strcpy(loop->fname,t_fname);
	   strcpy(loop->lname,t_lname);
	   strcpy(loop->pnum,t_pnum);
           }


	curr=curr->next;
	}
}

int main()
{
	int c1, ch;
  do{
	printf("\nEnter your choice\n");
	printf("\n\t Create:1\n");
	printf("\n\t Display:2\n");
	printf("\n\t Sort:3\n");
	printf("\n\t End:4\n");
	printf("\n\t Write:5\n");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:
	{
		c1=0;
		create();
		display();
		break;
	}
	case 2:
	{
		c1=0;
		display();
		break;
	}	
	case 3:
	{
		if(start==NULL)
		{
		printf("\nPhonebook is unpopulated!\n");
		break;
		}
		c1=0;
		sort1();
		display();
		break;
	}
	case 4:
	{
		c1=1;
		printf("\nThank You !\n");
		sort1();
		writefile();
		break;
	}
	case 5:
	{
		printf("Saved to .csv file");
		writefile();
		break;
	}
	default:
	{
		c1=0;
		printf("\nInvalid Input\n");
	}

	}
  }while(c1!=1);
start=NULL;
}



