/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
This is to certify that this project is my own work, based on my personal efforts 
in studying and applying the concepts learned. 
I have constructed the functions and their respective algorithms and corresponding 
code by myself. The program was run, tested,
and debugged with my own efforts. I further certify that I have not copied in part 
or whole or otherwise plagiarized the work 
of other students and/or persons. 
<Nigel Roi D. Nograles>, DLSU ID# <12236112>
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/*
 Description: <This program is a game called MERGE2WIN that will test the 
player's knowledge about the powers of 2! The game has three
 difficulties, rookie, skilled, and expert. Rookie is the easiest 
difficulty, while expert is the hardest difficulty. The game will 
 contain randomized values which the player would have to deal with 
while under the conditions of the difficulty chosen, in order to
 win the game with the most stars/points. Have fun!>
 For more details:
 At the beginning of the game, the user is presented with three boxes, 
A, B, and C, and a randomly generated TARGET value.
 When the game starts, the player is asked to press a key, which 
initiates the generation of a TOKEN.
 The user is then asked to choose a BOX to place the TOKEN in. The 
value of the BOX is updated as follows:
 If TOKEN < BOX, then BOX becomes TOKEN.
 If TOKEN > BOX, then BOX becomes TOKEN divided by BOX.
 If TOKEN = BOX, then merge TOKEN with BOX, such that BOX doubles in value. 
 Every time this happens, a STAR is awarded to the player, as long as BOX does 
not exceed TARGET.
 Rookie is allotted an unlimited number of TOKENS to play the game. A 
Skilled player is allotted up to 20 TOKENS, while an Expert has up to 10 TOKENS. 
 At the end of the game, a congratulatory message is displayed to the 
winning player. The number of TOKENS used, and the number of STARS accumulated
 are also displayed.
 If the player fails to reach the TARGET when they have consumed all 
the TOKENS, they are asked if they want to play again. The Rookie, having an 
unlimited
 number of TOKENS has the option to restart, continue, or quit playing 
the game after every 50 TOKENS.
-----------------------------------------------------------------------
-----------------------------------------------------------------------------------
------
 Backup: https://www.onlinegdb.com/edit/Bf9x7frxj
 Programmed by: <Nigel Roi D. Nograles> <X22A>
 Last modified: <December 4, 2022>
 Version: <1.5>
 [Acknowledgements: <// range of values for the randomly generated number for 
boxes a, b, and c, https://www.youtube.com/watch?v=ZaZxHzRn-AY, >]
*/
// Forward Declaration
void boxes_value (int *target, int *a, int *b, int *c);
int generate_target_value ();
int generate_token_value ();
int choose_difficulty (int *x);
int get_total_tokens (int difficulty);
int get_token_value (long total_tokens, int target);
int checkWinConditions (int difficulty, int a, int b, int c, int target);
int bonusStars (int total_tokens_used, int total_stars);
void displayValues (int difficulty, int token, int total_stars, int target,
					long total_tokens, int total_tokens_used, int a, int b,
					int c);
int getAvalue (int token, int a);
int getBvalue (int token, int b);
int getCvalue (int token, int c);
int
main ()
{
// Initialization of variables
  int a, b, c;
  int target;
  int token;
  long total_tokens = 0;
  int total_tokens_used = 0;
  int total_stars = 0;
  int difficulty = 0;
  int play = 1;
  char input;
  int input2;
  int choice;
  int win;
  int counter = 0;
  int continuation = 0;

/* srand(time(NULL)); makes use of the computer's internal clock to control 
the choice of the seed. This means that this makes the program
 be able to generate new random values for each run.
*/
  srand (time (NULL));
// Start of game
  printf ("\n\n\n\n\n\n================================================\n");
  printf ("\n---> Hello and welcome to MERGE2WIN! <---\n");
  printf ("\n================================================\n");
  printf ("\n\nPress enter or input a key to start: \n");

  scanf ("%c", &input);
  do
	{
	  boxes_value (&target, &a, &b, &c);	// Generates the values for boxes a, b, and c, and target 

// Shows the values of the boxes to the players.
	    printf ("\n\n\n");

	  printf ("\n===================BOXES====================\n\n");
	  printf ("Value of Box A: [%d]\n", a);
	  printf ("Value of Box B: [%d]\n", b);
	  printf ("Value of Box C: [%d]\n", c);
	  printf ("\n===================BOXES====================\n\n");
// Resets the total number of stars, total tokens used, and counter for total  tokens used.(if the player decided to go for more runs)

	  total_stars = 0;
	  total_tokens_used = 0;
	  counter = 0;
	  win = 0;

	  do
		{
		  difficulty = choose_difficulty (&difficulty);	// Player chooses difficulty
		}
	  while (difficulty != 1 && difficulty != 2 && difficulty != 3);
	  total_tokens = get_total_tokens (difficulty);	// Get value of total tokens using the value of difficulty
	  printf ("\n\n\nGenerate your first token by entering any number!\n");	// First generation of token!
	  scanf ("%d", &input2);
	  do
		{


		  if (total_tokens != 0)
			{					// Token is generated while the player has tokens.
			  token = get_token_value (total_tokens, target);	// Token is generated.
			}
		  do
			{
			  displayValues (difficulty, token, total_stars, target, total_tokens, total_tokens_used, a, b, c);	// Displays the values of the game.
			  printf ("\nInput [1] for Box A, Input [2] for Box B, and Input [3] for Box C\
n\n");							// Players makes a choice where to input token.
			  printf ("[1] Box A\n");
			  printf ("[2] Box B\n");
			  printf ("[3] Box C\n");
			  scanf ("%d", &choice);
			  if (choice < 1 || choice > 3)
				{
				  printf ("\nInvalid input\n");
				}
			}
		  while (choice < 1 || choice > 3);
		  if (choice == 1)
			{					// Choice == 1 meaning the choice is box a.
			  if (token == a)
				{
				  total_stars += 1;
				}
			  a = getAvalue (token, a);	// Gets new value of box A
			}
		  if (choice == 2)
			{					// Choice == 2 meaning the choice is box b.
			  if (token == b)
				{
				  total_stars += 1;
				}
			  b = getBvalue (token, b);	// Gets new value of box B
			}
		  if (choice == 3)
			{					// Choice == 3 meaning the choice is box c.
			  if (token == c)
				{
				  total_stars += 1;
				}
			  c = getCvalue (token, c);	// Gets new value of box C
			}
		  if (choice == 1 || choice == 2 || choice == 3)
			{
			  total_tokens_used = total_tokens_used + 1;	// After the player makes a choice, the total tokens used is incremented by 1. 
			  counter = counter + 1;	// Counter to know if the player has already used 50 tokens (only applicable in rookie difficulty) 
			  total_tokens -= 1;	// After the player makes a choice, the total tokens remaining 	is decremented by 1.
			}
		  win = checkWinConditions (difficulty, a, b, c, target);	// Checks if the player has won the game.
		  if (win == 1)
			{
			  printf ("\n============================================\n");
			  printf ("\n\n Congratulations!!! You won! \n\n");
			  printf ("\n============================================\n");
			  total_stars = bonusStars (total_tokens_used, total_stars);	// If the player has won the game, bonus stars MAY be awarded to the player.
			  total_tokens = 0;	// total tokens is set to 0 to terminate the loop of play.
			}
// Everytime the player has played 50 tokens without being able to win the player  will be given the choice to continue, restart,
//			or exit the game.
		 if (win == 0 && counter == 50)
			{
			  printf("\nIt has been a very long game.. do you wish to [1] continue, [2] restart, [3] exit?\n");
			  scanf ("%d", &continuation);
			  if (continuation == 2)
				{
// resets all values
				  total_tokens = 0;
				  difficulty = 0;
				  total_stars = 0;
				  total_tokens_used = 0;
				  play = 1;
				  printf ("\n\n\n\n\n\n\n\n");
				}
			  if (continuation == 3)
				{
// resets all values
				  total_tokens = 0;
				  difficulty = 0;
				  total_stars = 0;
				  total_tokens_used = 0;
				  play = 0;
				  printf ("\n\nThank you for playing!");
				}
			  counter = 0;		// reset counter
			}
		  }
		  while (total_tokens != 0);
		  if (continuation == 0)
			{
// After the loop of play is terminated, the total tokens used and the total stars gained by the player are displayed. 
		
			  printf("\n============================================\n");
			  printf ("\n\nTotal Tokens Used: %d\n", total_tokens_used);
			  printf ("Total Stars: %d\n\n", total_stars);
			  printf ("\n============================================\n\n\n");
			  printf ("Play again? Input any number to play. Exit? Input [0]\n\n\n");	// The player is asked the option to play again.
			  printf ("[0] Exit\n");
			  scanf ("%d", &play);
			  if (play == 0)
				{				// Exit Game
				  printf ("\n\nThank you for playing!");	// If the player exit the game, the message will be displayed. 
				}
			  if (play != 0)
				{				// If the player wishes to play again, the values are reset. The game restarts.
				  total_stars = 0;
				  total_tokens_used = 0;
				}
			  }
			  }
			  while (play != 0);	// The variable play has been initialized to 1 at the start to start the game.
			 
// end of program;
			    return 0;
			  }
// Functions start at line 367
// Functions
/* This function computes for the randomized values of boxes a, b, c.
 Precondition: Values of boxes are 2^k where k is between 1 and 12. Values of the
boxes are also
 less than or equal to the target where the value target 2^x is greater than 
256, where x is less
 than or equal to 12.
 @param *a is the value of the box a
 @param *b is the value of the box b
 @param *c is the value of the box c
 @param *target is the value of the target
*/
			  void boxes_value (int *target, int *a, int *b, int *c)
			  {
				int upper_box = 12, lower_box = 1;
				*target = generate_target_value ();
				*a =
				  pow (2,
					   ((rand () % (upper_box - lower_box + 1)) + lower_box));
				do
				  {
					if (*a > *target)
					  {
						*a =
						  pow (2,
							   ((rand () % (upper_box - lower_box + 1)) +
								lower_box));
					  }
				  }
				while (*a > *target);
				*b =
				  pow (2,
					   ((rand () % (upper_box - lower_box + 1)) + lower_box));
				do
				  {
					if (*b > *target)
					  {
						*b =
						  pow (2,
							   ((rand () % (upper_box - lower_box + 1)) +
								lower_box));
					  }
				  }
				while (*b > *target);
				*c =
				  pow (2,
					   ((rand () % (upper_box - lower_box + 1)) + lower_box));
				do
				  {
					if (*c > *target)
					  {
						*c =
						  pow (2,
							   ((rand () % (upper_box - lower_box + 1)) +
								lower_box));
					  }
				  }
				while (*c > *target);
			  }
/* This function computes for the value of the target
 Precondition: Target value is from 2^8 (256) to 2^12 (4096)
 @return the random value of the target
*/
			  int generate_target_value ()
			  {
// lowest value is 8 since 2 raised to 8 is 256.
				int target = pow (2, ((rand () % (12 - 8 + 1)) + 8));
				return target;
			  }
/* This function computes for the value of the token
 Precondition: Token value is 2^m where m is from 2 to 12
 @return the random value of token
*/
			  int generate_token_value ()
			  {
				int upper_box = 12, lower_box = 1;
				int token =
				  pow (2,
					   ((rand () % (upper_box - lower_box + 1)) + lower_box));
				return token;
			  }
/* This function asks the user to choose the difficulty
 Precondition: There are three difficulties, rookie, skilled, and expert, value 
of 1 for rookie, value of 2 for skilled, value of 3 for expert.
 @param *x is a pointer to point at parameter difficulty in main
 @return the value of difficulty (1, 2, or 3)
*/
			  int choose_difficulty (int *x)
			  {
				int difficulty = 0;
				do
				  {

					printf("\n\n\nChoose Difficulty: Input [1] for Rookie, Input [2] for Skilled, Input [3] for Expert\n\n\n\n");
					printf("\n============================================\n\n");
					printf ("[1] Rookie: Unlimited Tokens\n");
					printf ("[2] Skilled: 20 Tokens\n");
					printf ("[3] Expert: 10 Tokens\n");
					printf("\n============================================\n\n");
					scanf ("%d", &difficulty);
				  }
				while (difficulty != 1 && difficulty != 2 && difficulty != 3);
				return difficulty;
			  }
/* This function gets the total tokens based on the difficulty chosen.
 Precondition: Rookie will get 999999 or (unlimited tokens), Skilled will get
20 tokens, and Expert will get 10 tokens.
 @param difficulty is the difficulty chosen in function choose_difficulty.
 @return the value of total tokens
*/
			  int get_total_tokens (int difficulty)
			  {
				int total_tokens = 0;
				if (difficulty == 1)
				  {
					printf
					  ("\n============================================\n\n");
					printf ("\nDifficulty Chosen: Rookie\n\n");
					printf
					  ("\n============================================\n\n");
					total_tokens = 99999999;
				  }
				if (difficulty == 2)
				  {
					printf
					  ("\n============================================\n\n");
					printf ("\nDifficulty Chosen: Skilled\n\n");
					printf
					  ("\n============================================\n\n");
					total_tokens = 20;
				  }
				if (difficulty == 3)
				  {
					printf
					  ("\n============================================\n\n");
					printf ("\nDifficulty Chosen: Expert\n\n");
					printf
					  ("\n============================================\n\n");
					total_tokens = 10;
				  }
				return total_tokens;
			  }
/* This function gets the token value from the function generate_token_value, and 
will continue to generate
 Precondition: The token will be generated if total tokens is not equal to 
zero, and the token generated must be
 less than or equal to the value of target
 @param total_tokens is the value generated from the function 
get_total_tokens
 @param target is the value generated from the function generate_target_value
in function boxes_value
 @return the value of token
*/
			  int get_token_value (long total_tokens, int target)
			  {
				int token;
				if (total_tokens != 0)
				  {
					token = generate_token_value ();

					do
					  {
						if (token > target)
						  {
							token = generate_token_value ();
						  }
					  }
					while (token > target);
				  }
				return token;
			  }
/* This function determines if the user has won the game
 Precondition: The user will be the winner if the condition based on the 
difficulty chosen is satisfied.
 Conditions:
 Rookie Difficulty:
 If at least one box value is equal to the target value, the user wins.
 Skilled Difficulty:
 If at least two box values are equal to the target value, the user wins.
 Expert Difficulty:
 If all three box values are equal to the target value, the user wins.
 @param difficulty is the difficulty chosen in function choose_difficulty
 @param a is the value generated for box a in the function boxes_value
 @param b is the value generated for box b in the function boxes_value
 @param c is the value generated for box c in the function boxes_value
 @param target is the value generated for target in the function boxes_value
 @return the value of win
*/
			  int checkWinConditions (int difficulty, int a, int b, int c,
									  int target)
			  {
				int win = 0;
				if (difficulty == 1)
				  {
					if (a == target || b == target || c == target)
					  {
						win = 1;
					  }
				  }
				if (difficulty == 2)
				  {
					if ((a == target && b == target)
						|| (a == target && c == target) || (b == target
															&& c == target))
					  {
						win = 1;
					  }
				  }
				if (difficulty == 3)
				  {
					if (a == target && b == target && c == target)
					  {
						win = 1;
					  }
				  }
				return win;

			  }
/* This function determines how much bonus stars the player will win based on 
conditions.
 Precondition: The player will have the chance to have bonus stars if the 
player has won the game.
 Conditions:
 If the total tokens used is less than 10, a bonus of 10 stars will be 
awarded.
 If the total tokens used is between 10 and 20, a bonus of 5 stars will be 
awarded.
 If the total tokens used is more than 20, no bonus stars will be awarded.
 @param total_tokens_used is the amount of total tokens used. This parameter 
in main is incremented
 by 1 each time the player has made the choice which box to put in the token
 @param total_stars is the amount of total stars gained. This parameter in 
main is incremented by 1
 each time the player merges the box and the token.
 @return the value of total stars
*/
			  int bonusStars (int total_tokens_used, int total_stars)
			  {
				if (total_tokens_used < 10)
				  {
					total_stars = total_stars + 10;
				  }
				if (total_tokens_used > 10 && total_tokens_used < 20)
				  {
					total_stars = total_stars + 5;
				  }
				return total_stars;
			  }
/* This function displays the values of the token, total stars, target, total 
tokens, total tokens used,
 value of boxes a, b, and c.
 Precondition: The remaining tokens for the player will be displayed based on
the difficulty chosen
 If the difficulty is rookie, show the player that he or she has unlimited 
tokens
 If the difficulty is either skilled or expert, show the player the value of 
total_tokens
 @param difficulty is the difficulty chosen in function choose_difficulty
 @param token is the value generated from the function get_token_value
 @param total_stars is the amount of total stars gained. This parameter in 
main is incremented by 1
 each time the player merges the box and the token.
 @param target is the value generated for target in the function boxes_value
 @param total_tokens is the value generated from the function 
get_total_tokens
 @param total_tokens_used is the amount of total tokens used. This parameter 
in main is incremented
 by 1 each time the player has made the choice which box to put in the token
 @param a is the value generated for box a in the function boxes_value
 @param b is the value generated for box b in the function boxes_value
 @param c is the value generated for box c in the function boxes_value
*/
			  void displayValues (int difficulty, int token, int total_stars,
								  int target, long total_tokens,
								  int total_tokens_used, int a, int b, int c)
			  {
				printf
				  ("\n\n\n\n============================================\n");
				printf ("\n-> Token Value: [%d] <-\n", token);
				printf ("\n============================================\n");
				printf ("Total Stars: [%d]\n", total_stars);
				printf ("\n============================================\n");
				printf ("\nTarget Value: [%d]\n", target);
				printf ("\n============================================\n");
				if (difficulty == 1)
				  {
					printf ("\nRemaining Tokens: [Unlimited]\n");
				  }
				if (difficulty == 2 || difficulty == 3)
				  {
					printf ("\nRemaining Tokens: [%ld]\n", total_tokens);
				  }
				printf ("\n============================================\n");
				printf ("\nTotal tokens used: [%d]\n\n\n", total_tokens_used);
				printf ("\nChoose box to put in value of token: [%d] \n",
						token);
				printf ("\n============================================\n\n");
				printf ("Value of Box A: [%d]\n", a);
				printf ("Value of Box B: [%d]\n", b);
				printf ("Value of Box C: [%d]\n", c);
				printf ("\n============================================\n");
			  }
/* This function get the new value of box A based on the current value of a, and 
the value of token
 Precondition:
 If token is equal to box value, a becomes a multiplied by 2, meaning the 
values are merged.
 If token is greater than box value, a becomes token divided by a.
 If token is less than box value, then a becomes the token.
 @param token is the value generated from the function get_token_value
 @param a is the value generated for box a in the function boxes_value
*/
			  int getAvalue (int token, int a)
			  {
				if (token == a)
				  {
					a = 2 * a;
				  }
				else
				  {
					if (token > a)
					  {
						a = token / a;
					  }
					else
					  {
						a = token;
					  }
				  }
				return a;
			  }
/* This function get the new value of box B based on the current value of b, and 
the value of token
 Precondition:
 If token is equal to box value, b becomes b multiplied by 2, meaning the 
values are merged.
 If token is greater than box value, b becomes token divided by b.
 If token is less than box value, then b becomes the token.
 @param token is the value generated from the function get_token_value
 @param b is the value generated for box b in the function boxes_value
*/
			  int getBvalue (int token, int b)
			  {
				if (token == b)
				  {
					b = 2 * b;
				  }
				else
				  {
					if (token > b)
					  {
						b = token / b;
					  }
					else
					  {
						b = token;
					  }
				  }
				return b;
			  }
/* This function get the new value of box A based on the current value of a, and 
the value of token
 Precondition:
 If token is equal to box value, c becomes c multiplied by 2, meaning the 
values are merged.
 If token is greater than box value, c becomes token divided by c.
 If token is less than box value, then c becomes the token.
 @param token is the value generated from the function get_token_value
 @param c is the value generated for box c in the function boxes_value
*/
			  int getCvalue (int token, int c)
			  {
				if (token == c)
				  {
					c = 2 * c;
				  }
				else
				  {
					if (token > c)
					  {
						c = token / c;
					  }
					else
					  {
						c = token;
					  }
				  }
				return c;
			  }
