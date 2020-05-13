#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<windows.h>
struct node
{
	int label;
	char *name;
	struct node *next;
};

void clean_stdin();
void addToList(struct node *x, int data);
void traverseGraph();
void initNames();
void displayNames();
void mutual_friends(struct node *x, struct node *y);
void addFriendsTONetwork();
void link_friends();
void show_mutual_friends();
int isfriend(struct node* x ,int data);
void delay(int number_of_seconds);
void addFriendByName();
void appendFriends();



char names[20][15];
int MAXV;

struct node vertices[20]; //array of nodes



int main()
{   system("cls");
    printf("\t\t\t\t\t\tSocial Network\n");
    printf("\t\t\t\t\t\t____________\n\n\n\n");
	int choice;
	char term;
	/*
    char term;
    if(scanf("%d%c", &choice, &term) != 2 || term != '\n')
        printf("failure\n");
    */


	addFriendsTONetwork();
	displayNames();
	//delay(1);
	for(int i=0;i<MAXV;i++)
        {
		vertices[i].label = i;
		vertices[i].name = names[i];
		vertices[i].next = NULL;
	}
	printf("\n \n");


    do
    {
        //delay(0.5);
        system("cls");
printf("\n\n\t\t\t\t\t\tSocial Network\n\t\t\t\t\t\t____________\n\n\n\n 1.add friends\n 2.display friendship among people\n 3.Find mutual friends\n 4.Display people in the network\n 5.Append people to list\n press 6 to exit\n\n ");

     if(scanf("%d%c", &choice, &term) != 2 || term != '\n')
        printf("Enter a valid key\n");

     else
     {
         if(choice>=1 && choice<=6)
        {
		 switch(choice)
		{


		    case 1:
		    {
		        addFriendByName();

		    }
		    break;


		    case 2:
		    {
		        traverseGraph();
		    }
		    break;


		    case 3:
		    {
		       show_mutual_friends();
		    }
		    break;

		    // Find the given key.
		    case 4:
		    {
		        displayNames();
		    }
		    break;

		    case 5:
		    {
		        appendFriends();
		    }
		    break;



		    default:
		        break;
        	}
        }

     }


	printf("\n\n---------------------------------------------\n\n");

    fflush(stdin);
    //delay(1);
    system("cls");
    }
    while(choice != 6);

	return 0;
}
//char names[20][15];
//int MAXV;

struct node vertices[20]; //array of nodes


void addToList(struct node *x, int data)
{

	int flag = isfriend(x ,data);//checking if the friendship already exists

	if(flag==0 && data<MAXV)//checking the condition that there is no friendship
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
			flag=1; //friendship found
		}
	temp=temp->next;


	}
	return flag;
}

void link_friends()
{
    int x,y;
    printf("Friends with unique code\n");
    for(int i=0;i<MAXV;i++){
		printf(" %s  code is  %d\n",names[i],i);
	}
	printf("\nenter the friends code whom you wish to add as friends\n");
	scanf("%d %d",&x,&y);
	addToList(&vertices[x], y); // adding back to the list

}
void addFriendByName()
{
    char name1[20],name2[20];
    printf("\nChoose two friends from the list\n\n");
	for(int i=0;i<MAXV;i++){
		printf("%s \n", names[i]);
	}
    //displayNames();

    printf("\nchoose 2 friends from the above list to add them as friends\n");
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
	printf("enter the 2 friends  whose mutual friends u want to see\n");
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
		printf("%s is friend of --> ", temp->name);
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
	printf("\nPeople present in the Network\n\n");
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




