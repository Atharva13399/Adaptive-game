#include <stdio.h>
#include<stdlib.h>

struct node;
struct board;

struct node* random_node(struct node * current_state);
void display();
struct node* input_node(struct node * current_state);


struct board
{
    char field[9];
    int player[9];
    int comp[9];
};

struct pair
 {
 	int weight;
 	struct node* link;
 };

struct node
{
    int weight;
    struct pair options[9];
    struct node* parent;
    int choice;
    struct board b;
};


struct board b;
struct node* head;


struct node* random_node(struct node * current_state)
{
	int move = -1,i;
	struct node* child;
	child = (struct node*)malloc(sizeof(struct node));
	while(move == -1)
	{
		i = rand()%9;
		move = b.comp[i];
	}
	b.comp[i] = -1;
	b.player[i] = -1;
	b.field[i] = 'O';
	( current_state -> options[(child -> choice)].link) = child;
	(child -> choice) ++;
	printf("Comp move is:\n");
	display();
	return child;

}

struct node* input_node(struct node * current_state)
{
	int move,i;
	struct node* child;
	child = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &move);
	while( (b.player[move] == -1) || (move >8) || (move < 0))
	{
		printf("Enter a valid input\n");
		scanf("%d", &move);
	}
	b.comp[move] = -1;
	b.player[move] = -1;
	b.field[move] = 'X';
	( current_state -> options[(child -> choice)].link) = child;
	(child -> choice)++;
	display();
	return child;
}

void display()
{
	printf("%c|%c|%c\n",b.field[0],b.field[1],b.field[2]);
	printf("%c|%c|%c\n",b.field[3],b.field[4],b.field[5]);
	printf("%c|%c|%c\n",b.field[6],b.field[7],b.field[8]);
}


int main()
{
	int i;
	struct node* temp;
	
	head = (struct node*)malloc(sizeof(struct node)); 
	temp = head;

	for (i = 0; i < 9; i++)
	{
		b.comp[i]=b.player[i]=i;
		b.field[i]=i+48;
	}
	
	display();
	

	temp = input_node(temp);
	temp = random_node(temp);
	temp = input_node(temp);
	temp = random_node(temp);
	temp = input_node(temp);
	temp = random_node(temp);
	temp = input_node(temp);
	temp = random_node(temp);
	temp = input_node(temp);

	return 0;
}