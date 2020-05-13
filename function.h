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

