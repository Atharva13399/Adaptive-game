#include <stdio.h>
#include<stdlib.h>


// Structure decleration.//--------------------------------------------------------------------------------------------------------------------------------------------------//
struct node;
struct board;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Function decleration.//---------------------------------------------------------------------------------------------------------------------------------------------------//
struct node* new_random_node_p1(struct node * current_state);
struct node* new_random_node_p2(struct node * current_state);
struct node* new_input_node(struct node * current_state);
struct node* check_random_node_p1(struct node * current_state);
struct node* check_random_node_p2(struct node * current_state);
struct node* check_input_node(struct node * current_state);
struct node* is_present_in(struct node * current_state);
void display();
int state_of_game(struct board);
int compare_array(char a[], char b[]);
int compare_array_int(int a[], int b[]);
int assign_weight(int weight_to_add,struct node * current_node);
void find_and_assign(int choice,struct node * child,int end_game);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Structure Definition. //---------------------------------------------------------------------------------------------------------------------------------------------------//
struct board
{
    char field[9];
    int player[9];
    int comp[9];
    int state;
};

struct pair
 {
 	int weight;
 	struct node* link;
 	struct board node_configuration;
 };

struct node
{
    int weight;
    struct pair options[9];
    struct node* parent;
    int choice;
    struct board b;
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


//Decleration of Global variables.//------------------------------------------------------------------------------------------------------------------------------------------//
struct board b;
struct node* head;
int end_game;
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


//Function Definitions//------------------------------------------------------------------------------------------------------------------------------------------------------//

// A function to create computer nodes (As X).
struct node* new_random_node_p1(struct node * current_state)
{
	// Decleration.
	int move = -1,i;
	
	// Creating a node named child.
	struct node* child;
	child = (struct node*)malloc(sizeof(struct node));
	
	// Generating a random move for the computer.
	while(move == -1)
	{
		i = rand()%9;
		move = b.comp[i];
	}
	
	// Making changes in global variable board b.
	b.comp[i] = -1;
	b.player[i] = -1;
	b.field[i] = 'X';

	// Weight
		// In back tracking.
	
	// Appending the array (of pairs) of the current node.
	// The pointer.
	( current_state -> options[(current_state -> choice)].link) = child;
	// The board configuration of child is known to current_node.
	( current_state -> options[(current_state -> choice)].node_configuration) = b;
	// Weight
		// In back tracking.

	// Assigning Parent.
	(child -> parent) = current_state;

	// Increment choice.
	if((current_state -> choice) < 8)
		(current_state -> choice) ++;
	printf("%d\n",current_state -> choice );

	// Display of screen
	//printf("Comp move is (Player 1):\n");
	//display();

	// Return statement.
	
	return child;
}

// A function to create computer nodes (As O).
struct node* new_random_node_p2(struct node * current_state)
{
	// Decleration.
	int move = -1,i;
	
	// Creating a node named child.
	struct node* child;
	child = (struct node*)malloc(sizeof(struct node));
	
	// Generating a random move for the computer.
	while(move == -1)
	{
		i = rand()%9;
		move = b.comp[i];
	}
	
	// Making changes in global variable board b.
	b.comp[i] = -1;
	b.player[i] = -1;
	b.field[i] = 'O';

	// Weight
		// In back tracking.
	
	// Appending the array (of pairs) of the current node.
	// The pointer.
	( current_state -> options[(current_state -> choice)].link) = child;
	// The board configuration of child is known to current_node.
	( current_state -> options[(current_state -> choice)].node_configuration) = b;
	// Weight
		// In back tracking.

	// Assigning Parent.
	(child -> parent) = current_state;

	// Increment choice.
	if((current_state -> choice) < 8)
		(current_state -> choice) ++;

	// Display of screen
	//printf("Comp move is (As player 1):\n");
	//display();

	// Return statement.
	return child;
}

// A function to take input nodes.
struct node* new_input_node(struct node * current_state)
{
	// Decleration
	int move,i;
	
	// Creating a node named child.
	struct node* child;
	child = (struct node*)malloc(sizeof(struct node));
	
	// Taking an input.
	printf("Enter a move\n");
	scanf("%d", &move);
	while( (b.player[move] == -1) || (move >8) || (move < 0))
	{
		printf("Enter a valid input\n");
		scanf("%d", &move);
	}

	// Making changes in global variable board b.
	b.comp[move] = -1;
	b.player[move] = -1;
	b.field[move] = 'X';
	

	// Weight
		// In back tracking.
	
	// Appending the array (of pairs) of the current node.
	// The pointer.
	( current_state -> options[(current_state -> choice)].link) = child;
	// The board configuration of child is known to current_node.
	( current_state -> options[(current_state -> choice)].node_configuration) = b;
	// Weight
		// In back tracking.

	// Assigning Parent.
	(child -> parent) = current_state;

	// Increment choice.
	if((current_state -> choice) < 10)
		(current_state -> choice)++;

	// Display of screen.
	display();

	// Return statement.
	return child;
}

// A function to check if a node is present.
struct node* check_random_node_p1(struct node * current_state)
{
	if (is_present_in(current_state))
		return is_present_in(current_state);
	else
		return new_random_node_p1(current_state);
}

// A function to check if a node is present.
struct node* check_random_node_p2(struct node * current_state)
{
	if (is_present_in(current_state))
		return is_present_in(current_state);
	else
		return new_random_node_p2(current_state);
}

// A function to check if a node is present.
struct node* check_input_node(struct node * current_state)
{
	if (is_present_in(current_state))
		return is_present_in(current_state);
	else
		return new_input_node(current_state);
}

// A function to check if a node is present.
struct node* is_present_in(struct node * current_state)
{
	for (int i = 0; i < (current_state -> choice); i++)
		if ( compare_array( (current_state -> options[i].node_configuration.field) , b.field))
			return  (current_state -> options[i].link);
	return NULL;
}

// Function to display board.
void display()
{
	printf("%c|%c|%c\n",b.field[0],b.field[1],b.field[2]);
	printf("%c|%c|%c\n",b.field[3],b.field[4],b.field[5]);
	printf("%c|%c|%c\n",b.field[6],b.field[7],b.field[8]);
}

int state_of_game(struct board b)
{
	int current,i;
    if (b.field[0] == 'X' && b.field[1] == 'X' && b.field[2] == 'X')
    {
       current = -1;
    }
	else if (b.field[3] == 'X' && b.field[4] == 'X' && b.field[5] == 'X')
    {
     	current = -1;   
	}
    else if (b.field[6] == 'X' && b.field[7] == 'X' && b.field[8] == 'X')
    {
       current = -1;
    }
    else if (b.field[0] == 'X' && b.field[3] == 'X' && b.field[6] == 'X')
    {
       current = -1;
    }
	else if (b.field[1] == 'X' && b.field[4] == 'X' && b.field[7] == 'X')
    {
       current = -1;
	}
    else if (b.field[2] == 'X' && b.field[5] == 'X' && b.field[8] == 'X')
    {
       current = -1;
    }
    else if (b.field[0] == 'X' && b.field[4] == 'X' && b.field[8] == 'X')
    {
       current = -1;
    }
	else if (b.field[4] == 'X' && b.field[2] == 'X' && b.field[6] == 'X')
    {
       current = -1;
	}
    else if (b.field[0] == 'O' && b.field[1] == 'O' && b.field[2] == 'O')
    {
       current = 1;
    }
    else if (b.field[3] == 'O' && b.field[4] == 'O' && b.field[5] == 'O')
    {
       current = 1;
    }
	else if (b.field[6] == 'O' && b.field[7] == 'O' && b.field[8] == 'O')
    {
       current = 1;
	}
    else if (b.field[0] == 'O' && b.field[3] == 'O' && b.field[6] == 'O')
    {
       current = 1;
    }
    else if (b.field[2] == 'O' && b.field[5] == 'O' && b.field[8] == 'O')
    {
       current = 1;
    }
	else if (b.field[1] == 'O' && b.field[4] == 'O' && b.field[7] == 'O')
    {
       current = 1;
	}
    else if (b.field[0] == 'O' && b.field[4] == 'O' && b.field[8] == 'O')
    {
       current = 1;
    }
    else if (b.field[6] == 'O' && b.field[2] == 'O' && b.field[4] == 'O')
    {
       current = 1;
    }
    else 
    	current = 0;

    for (i = 0; i < 9; i++)
	{
		b.comp[i]=b.player[i]=i;
		b.field[i]=i+48;
	}
    return current;
}

int compare_array(char a[], char b[])
{
	
	for (int i = 0; i < 9; ++i)
		if(a[i] != b[i])
			return 0;
	return 1;

}

int compare_array_int(int a[], int b[])
{
	for (int i = 0; i < 9; ++i)
		if(a[i] != b[i])
			return 0;
	return 1;
}

int assign_weight(int weight_to_add,struct node * current_node)
{
	struct node * temp = current_node;
	while(temp -> parent != NULL)
	{
		temp -> weight += weight_to_add;
		temp = temp -> parent;
	}
	temp = current_node;
	while(temp -> parent != NULL)
	{
		find_and_assign(temp -> parent -> choice,temp ,end_game);
		temp = temp -> parent;
	}
	return 0;
}

void find_and_assign(int choice,struct node * child,int end_game)
{
	for (int i = 0; i < child -> parent -> choice; ++i)
		if((child -> parent -> options[i].link) == child)
			(child -> parent -> options[i].weight) += end_game;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//


// Main function.//--------------------------------------------------------------------------------------------------------------------------------------------------//
int main()
{
	int i;
	int j;
	struct node* temp;
	int complete[9];

	for (int i = 0; i < 9; ++i)
		complete[i] = -1;
	
	head = (struct node*)malloc(sizeof(struct node)); 
	head -> parent = NULL;
	
	temp = head;
	
	for (i = 0; i < 9; i++)
	{
		b.comp[i]=b.player[i]=i;
		b.field[i]=i+48;
	}
	
	for (j = 0; j < 100; ++j)
	{
		printf("Game number %d\n",(j+1) );
		while( state_of_game(b) == 0 )
		{
			temp = check_random_node_p1(temp);
			printf("Player 1 move\n");
			if (compare_array_int(complete,b.comp))
				break;
			temp = check_random_node_p2(temp);
			printf("Player 2 move\n");
			if (compare_array_int(complete,b.comp))
				break;	
		}
		end_game = state_of_game(b);
		assign_weight(end_game,temp);
		for (i = 0; i < 9; i++)
		{
			b.comp[i]=b.player[i]=i;
			b.field[i]=i+48;
		}
		temp = head;
		printf("END OF ONE GAME\n");
	}
	return 0;
}