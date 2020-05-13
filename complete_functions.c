#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include"function.h"




char names[20][15];
int MAXV;

struct node vertices[20]; //array of nodes


void addToList(struct node *x, int data)
{

	int flag = isfriend(x ,data);//checking if the friendship already exists

	if(flag==0 && data<MAXV)//checking the conditions
	{
		struct node *y = (struct node *)(malloc(sizeof(struct node)));
		if(y!=NULL)
		{
			y->label = data;
			y->name = names[data];
			if(x->next != NULL)
			{
			    y->next = x->next;
			    x->next = y;
			}

			else
			{
		   	y->next = NULL;
			x->next = y;
	       		}



		}

	}
	else
	{   if(data>MAXV)
            printf("\nEntered unique code is invalid\n");
        else
            printf("\nThey are already Friends\n");
	}
}

int isfriend(struct node* x ,int data)
{
	int flag = 0;// assuming no friendships
	struct node* temp =x;
	temp=temp->next;
	while(temp!=NULL)
	{	
		if(strcmp(temp->name,names[data])==0)
		{
			flag=1;
		}
	temp=temp->next;


	}
	return flag;
}

void link_friends()
{
    int x,y;
    printf("Frinds with unique code\n");
    for(int i=0;i<MAXV;i++){
		printf(" %s  code is  %d\n",names[i],i);
	}
	printf("\nenter the frinds code whom you wish to add as friends\n");
	scanf("%d %d",&x,&y);
	addToList(&vertices[x], y);

}
void addFriendByName()
{
    char name1[20],name2[20];
    printf("\nChoose two friends from the list\n\n");
	for(int i=0;i<MAXV;i++){
		printf("%s \n", names[i]);
	}
    //displayNames();

    printf("\nEnter the names of 2 friends from the list to add them as friends\n");
    scanf("%s %s",name1,name2);
    int x,y;
    x=100;
    y=100;
    int i=0;
    for(i=0;i<MAXV;i++)
    {
        if(strcmp(name1,names[i])==0)
        {
            x=i;

        }
        if(strcmp(name2,names[i])==0)
        {
            y=i;

        }
    }
    if(x==100 || y==100 || x==y)
    {
        if(strcmp(name1,name2)==0 )
        {
            if(x==100)
            {
                printf("\nplease enter 2 different names and choose from the list\n");

            }
            else
            {
                printf("\nplease enter 2 different names\n");
            }
        }
        else
        {
         printf("\nPlease Check the spelling of the word\n");
        }
        addFriendByName();


    }
    else
    {
      addToList(&vertices[x], y);
    }

}

void show_mutual_friends()
{
    char name1[20],name2[20];
    int x,y;
    x=100;
    y=100;
    int i=0;
    printf("\nList of friends\n");
    for(i=0;i<MAXV;i++)
	{
		printf(" %s \n",names[i]);
	}
	printf("enter the 2 friends  whose mutual friends u need to see\n");
	//scanf("%d %d",&x,&y);
	scanf("%s %s",name1,name2);
	i=0;
    for(i=0;i<MAXV;i++)
    {
        if(strcmp(name1,names[i])==0)
        {
            x=i;

        }
        if(strcmp(name2,names[i])==0)
        {
            y=i;

        }
    }
	if(x==100 || y==100 || x==y)
    {
        if(strcmp(name1,name2)==0 )
        {
            if(x==100)
            {
                printf("\nplease enter 2 different names and choose from the list\n");

            }
            else
            {
                printf("\nplease enter 2 different names\n");
            }
        }
        else
        {
         printf("\nPlease Check the spelling of the word\n");
        }
        show_mutual_friends();




    }
    else
        mutual_friends(&vertices[x],&vertices[y]);

}

void traverseGraph(){

	int array_size = sizeof(vertices) / sizeof(vertices[0]);

	printf("\n");
	printf(" Friendship between people \n");
	printf("\n");
	for(int i=0;i<MAXV;i++)
    {
		struct node *temp = &vertices[i];
		printf("%s is friend to --> ", temp->name);
		if(temp->next != NULL)
        {
			temp = temp->next;
			while(temp != NULL)
			{
				printf("%s", temp->name);
				if(temp->next != NULL)
					printf(", ");
				temp = temp->next;
			}
		}
		printf("\n\n---------------------------------------------\n\n");
	}
	delay(2);
}


void displayNames()
{
	printf("\nPeople in a small Network\n\n");
	for(int i=0;i<MAXV;i++){
		printf("%s \n", names[i]);
	}
	printf("\n\n---------------------------------------------\n\n");
	delay(3);
}

void mutual_friends(struct node *x, struct node *y)
{
    printf("\n\n---------------------------------------------\n\n");
   struct node *temp,*temp2;
   temp=x;
   temp2=y;
   printf("Mutual Friends between %s and %s is \n",temp->name,temp2->name);
   temp=temp->next;
   temp2=temp2->next;
   for(;temp!=NULL;temp=temp->next)
   {
       temp2=y;
       temp2=temp2->next;
       for(;temp2!=NULL;temp2=temp2->next)
        {
            if(strcmp(temp->name,temp2->name)==0)
                printf("%s \n",temp->name);

        }
   }
   delay(3);




}


void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}


void addFriendsTONetwork()
{
        fflush(stdin);
        int i;
        int choice;
        char term;
        printf("\nEnter no of people:\n");
        //scanf("%d",&MAXV);
        if(scanf("%d%c", &MAXV, &term) != 2 || term != '\n')
            {
                printf("\nEnter a valid key\n");

                addFriendsTONetwork();

            }
         else

         {
                if(MAXV==0)
                {
                    printf("\nPlease enter atleast 1 person\n\n");
                        addFriendsTONetwork();

                }
                else
                {
                    printf("Enter %d names:\n",MAXV);
                    for (i=0;i<MAXV;i++)
                    {
                        scanf("%s",names[i]);
                    }
                 }
           }
}

void appendFriends()
{
    char name[20];
    printf("\n enter the name of new person to be added to network\n");
    scanf("%s",names[MAXV]);
    MAXV++;

	vertices[MAXV-1].label = MAXV;
    vertices[MAXV-1].name = names[MAXV-1];
    vertices[MAXV-1].next = NULL;
}

