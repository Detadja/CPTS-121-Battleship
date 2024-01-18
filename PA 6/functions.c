#include "header.h"

//Displays the welcome intro.
void disp_game(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Welcome to Battleship! ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Displays the rules.
void disp_rules(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ The rules are simple: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ You will place five ships: A Carrier that occupies 5 spaces, a Battleship that occupies 4 spaces, ~~\n");
	printf("~~ a Cruiser that occupies 3 spaces, a Submarine that occupies 3 spaces and a Destroyer that occupies ~\n");
	printf("~~ 2 spaces. You place these ships on a 10 x 10 grid, which you can either place manually or let the ~~\n");
	printf("~~ computer place it for you. However, if you choose manual, then be sure to place them only either ~~~\n");
	printf("~~ horizontally or vertically; you cannot place them diagonally. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ When the game begins, you and the second player (a bot) will take turns to shoot. Depending on the ~\n");
	printf("~~ coordinate either you or the bot chose, if either one of you hit, then depending on the size of ~~~~\n");
	printf("~~ the ship size, it can take that amount of hits (Ex: The Cruiser can take 3 hits before sinking). ~~~\n");
	printf("~~ Of course, you cannot hit the same place twice. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ The player who has completely destroyed the other's fleet wins the game. ~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |  0 1 2 3 4 5 6 7 8 9 | ~~ Here is the board. The top row of numbers represents the horizontal ~~~~\n");
	printf("~~ |0 - - - - - - - - - - | ~~ axis coordinates, and the left column represents the vertical axis ~~~~~\n");
	printf("~~ |1 - - - - - - - - - - | ~~ coordinates. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |2 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |3 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |4 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |5 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |6 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |7 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |8 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~ |9 - - - - - - - - - - | ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Displays the choices to proceed after the intro.
void disp_choice(void)
{
	printf("~~~~~~~~~~~~~~~~\n");
	printf("~ 1. Play Game ~\n");
	printf("~ 2. Rules ~~~~~\n");
	printf("~ 3. Exit Game ~\n");
	printf("~~~~~~~~~~~~~~~~\n\n");
}

//Display a prompting message to continue the game.
void disp_cont(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Press the ENTER key to continue ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Displays the goodbye message.
void disp_gbye(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Thank you for playing! ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Displays an error message when the player is prompted to input something.
void err_msg(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ That's not a valid option ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

//Displays an error message when the player is manually placing their fleet.
void invld_place(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ You cannot put it there, they'll overlap ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Reminds the player to becareful of their placement choice.
void reminder(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ REMINDER: Depending on where you picked, it will either automatically ~\n");
	printf("~ place your ship or ask you to extend it left or right, or up or down. ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Asks the player to choose a horizontal coordinate on their board.
void ask_choose_coordinate_h(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Please choose a horizontal coordinate between 0-9. ~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
//Asks the player to choose a vertical coordinate on their board.
void ask_choose_coordinate_v(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Please choose a vertical coordinate between 0-9. ~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Asks the player if they want to expand their ship left or right.
void ask_expand_h(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Do you want to expand your ship to the left or right? (L | R) ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Asks the player if they want to expand their ship up or down.
void ask_expand_v(void)
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Do you want to expand your ship upwards or downwards? (U | D) ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

//Displays ellipses.
void ellipses(void)
{
	printf("~~~~~~~~~\n");
	printf("~ . . . ~\n");
	printf("~~~~~~~~~\n");
}

//Logs the player's shot and location.
void log_shot_msg(FILE* outfile, int x, int y, int player)
{
	fprintf(outfile, "Player %d shoots at %d, %d!\n\n", player, x, y);
}

//Logs the player's hit.
void log_hit_msg(FILE* outfile)
{
	fprintf(outfile, "It hits!\n\n");
}

//Logs the player's miss.
void log_miss_msg(FILE* outfile)
{
	fprintf(outfile, "It misses!\n\n");
}

void log_win_lose(FILE* outfile, int player)
{
	fprintf(outfile, "Player %d wins!", player);
}


//Asks the player which ship they want to place.
void ask_which_ship(int *ship, char *ship_type, char select[][45])
{
	int choice = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Which ship do you want to place? ~\n");
	puts(select[0]);
	puts(select[1]);
	puts(select[2]);
	puts(select[3]);
	puts(select[4]);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf("%d", &choice);

	while (choice < 1 || choice > 5) //Checks for invalid input.
	{
		system("cls");
		err_msg();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Which ship do you want to place? ~\n");
		puts(select[0]);
		puts(select[1]);
		puts(select[2]);
		puts(select[3]);
		puts(select[4]);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf("%d", &choice);
	}

	if (choice == 1)
	{
		*ship = 5;
		*ship_type = 'C';
		strcpy(select[0], "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	else if (choice == 2)
	{
		*ship = 4;
		*ship_type = 'B';
		strcpy(select[1], "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	else if (choice == 3)
	{
		*ship = 3;
		*ship_type = 'R';
		strcpy(select[2], "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	else if (choice == 4)
	{
		*ship = 3;
		*ship_type = 'S';
		strcpy(select[3], "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
	else
	{
		*ship = 2;
		*ship_type = 'D';
		strcpy(select[4], "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	}
}

//Asks the player if they would like to arrange their ship horizontally or vertically.
void hori_or_verti(int* direction)
{
	char dir = '\0';
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Would you like to place your ship horizontally or vertically? (H | V) ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf(" %c", &dir);

	while (dir != 'h' && dir != 'H' && dir != 'v' && dir != 'H') //Checks for invalid input
	{
		system("cls");
		err_msg();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Would you like to place your ship horizontally or vertically? (H | V) ~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf(" %c", &dir);
	}

	if (dir == 'h' || dir == 'H')
		*direction = 0;
	else
		*direction = 1;

}

//Asks the user if they want to arrange their board manually or let the computer do it and returns a number indicating one of those choices.
void manual_or_automatic(int *manual_or_automatic)
{
	char choice = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Do you want your fleet to be randomized or do you want to choose on your own? (A | M) ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf(" %c", &choice);
	while (choice != 'a' && choice != 'A' && choice != 'm' && choice != 'M') //Checks for invalid input.
	{
		system("cls");
		err_msg();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Do you want your fleet to be randomized or do you want to choose on your own? (A | M) ~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf(" %c", &choice);
	}

	if (choice == 'a' || choice == 'A')
		*manual_or_automatic = 1;
	else
		*manual_or_automatic = 0;
}

//Checks to see if the ships overlap each other or not, when the player chose to place them horizontally.
void overlap_check_h(char ship_type, int *x, int *y, char p_board[][10])
{
	int check = 0, hor = 0, ver = 0;
	hor = *x;
	ver = *y;

	while (check == 0)
	{
		int num_dash = 0;
		if (ship_type == 'C')
		{
			if (hor <= 3)
			{
				for (int index = 0; index < 5; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor++;
				}
			}
			else if (hor >= 6)
			{
				for (int index = 0; index < 5; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor--;
				}
			}
			else
				num_dash = 5;
			if (num_dash == 5)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
				}
				ask_choose_coordinate_v();
				reminder();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
					while (x < 0 || x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", x);
					}
					ask_choose_coordinate_v();
					reminder();
					scanf("%d", y);
					while (y < 0 || y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", y);
					}
				}
			}
		}
		else if (ship_type == 'B')
		{
			if (hor <= 2)
			{
				for (int index = 0; index < 4; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor++;
				}

			}
			else if (hor >= 7)
			{
				for (int index = 0; index < 4; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor--;
				}
			}
			else
				num_dash = 4;
			if (num_dash == 4)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
				}
				ask_choose_coordinate_v();
				reminder();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
					while (x < 0 || x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", x);
					}
					ask_choose_coordinate_v();
					reminder();
					scanf("%d", y);
					while (y < 0 || y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", y);
					}
				}
			}
		}
		else if (ship_type == 'R' || ship_type == 'S')
		{
			if (hor <= 1)
			{
				for (int index = 0; index < 3; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor++;
				}
			}
			else if (hor >= 8)
			{
				for (int index = 0; index < 3; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor--;
				}
			}
			else
				num_dash = 3;
			if (num_dash == 3)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
				}
				ask_choose_coordinate_v();
				reminder();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
					while (x < 0 || x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", x);
					}
					ask_choose_coordinate_v();
					reminder();
					scanf("%d", y);
					while (y < 0 || y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", y);
					}
				}
			}
		}
		else
		{
			if (hor == 0)
			{
				for (int index = 0; index < 2; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor++;
				}
			}
			else if (hor == 9)
			{
				for (int index = 0; index < 2; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					hor--;
				}
			}
			else
				num_dash = 2;
			if (num_dash == 2)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
				}
				ask_choose_coordinate_v();
				reminder();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", x);
					while (x < 0 || x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", x);
					}
					ask_choose_coordinate_v();
					reminder();
					scanf("%d", y);
					while (y < 0 || y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", y);
					}
				}
			}
		}
	}
}

//Checks to see if the ships overlap each other or not, when the player chose to place them vertically.
void overlap_check_v(char ship_type, int* x, int* y, char p_board[][10])
{
	int check = 0, hor = 0, ver = 0;
	hor = *x;
	ver = *y;

	while (check == 0)
	{
		int num_dash = 0;
		if (ship_type == 'C')
		{
			if (ver <= 3)
			{
				for (int index = 0; index < 5; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver++;
				} 
			}
			else if (ver >= 6)
			{
				for (int index = 0; index < 5; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver--;
				}
			}
			else
				num_dash = 5;
			if (num_dash == 5)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", y);
				}
				ask_choose_coordinate_h();
				reminder();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", x);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
					while (*y < 0 || *y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", y);
					}
					ask_choose_coordinate_h();
					reminder();
					scanf("%d", x);
					while (*x < 0 || *x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", x);
					}
				}
			}
		}
		else if (ship_type == 'B')
		{
			if (ver <= 2)
			{
				for (int index = 0; index < 4; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver++;
				}
			}
			else if (ver >= 7)
			{
				for (int index = 0; index < 4; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver--;
				}
			}
			else
				num_dash = 4;
			if (num_dash == 4)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", y);
				}
				ask_choose_coordinate_h();
				reminder();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", x);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
					while (*y < 0 || *y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", y);
					}
					ask_choose_coordinate_h();
					reminder();
					scanf("%d", x);
					while (*x < 0 || *x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", x);
					}
				}
			}
		}
		else if (ship_type == 'R' || ship_type == 'S')
		{
			if (ver <= 1)
			{
				for (int index = 0; index < 3; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver++;
				}
			}
			else if (*y >= 8)
			{
				for (int index = 0; index < 3; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver--;
				}
			}
			else
				num_dash = 3;
			if (num_dash == 3)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", y);
				}
				ask_choose_coordinate_h();
				reminder();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", x);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
					while (*y < 0 || *y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", y);
					}
					ask_choose_coordinate_h();
					reminder();
					scanf("%d", x);
					while (*x < 0 || *x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", x);
					}
				}
			}
		}
		else
		{
			if (ver == 0)
			{
				for (int index = 0; index < 2; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver++;
				}
			}
			else if (ver == 9)
			{
				for (int index = 0; index < 2; index++)
				{
					if (p_board[ver][hor] == '-')
						num_dash++;
					ver--;
				}
			}
			else
				num_dash = 2;
			if (num_dash == 2)
				check = 1;
			else
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", y);
				while (*y < 0 || *y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", y);
				}
				ask_choose_coordinate_h();
				reminder();
				scanf("%d", x);
				while (*x < 0 || *x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", x);
				}

				while (p_board[*y][*x] != '-') //Checks if the initial point chosen overlaps.
				{
					system("cls");
					invld_place();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", y);
					while (*y < 0 || *y > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_h();
						scanf("%d", y);
					}
					ask_choose_coordinate_h();
					reminder();
					scanf("%d", x);
					while (*x < 0 || *x > 9) //Checks for invalid input.
					{
						system("cls");
						err_msg();
						disp_player_board(p_board);
						ask_choose_coordinate_v();
						scanf("%d", x);
					}
				}
			}
		}
	}
}

//Let's the player arrange their fleet manually.
void manual_arr(char p_board[][10])
{
	char select[5][45] = { "~ 1. Carrier ~~~~~~~~~~~~~~~~~~~~~~~" , "~ 2. Battleship ~~~~~~~~~~~~~~~~~~~~", "~ 3. Cruiser ~~~~~~~~~~~~~~~~~~~~~~~", 
		"~ 4. Submarine ~~~~~~~~~~~~~~~~~~~~~", "~ 5. Destroyer ~~~~~~~~~~~~~~~~~~~~~" };

	for (int count = 0; count < 5; count++)
	{
		int x = 0, y = 0, ship_size = 0, dir = 0;
		char ship_type = '\0';

		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Placement %d out of 5 ~\n", count + 1);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		ask_which_ship(&ship_size, &ship_type, select);
		hori_or_verti(&dir);
		system("cls");

		if (dir == 0) //Player chooses to place their ship horizontally.
		{
			disp_player_board(p_board);
			ask_choose_coordinate_h();
			scanf("%d", &x);
			while (x < 0 || x > 9) //Checks for invalid input.
			{
				system("cls");
				err_msg();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", &y);
			}
			ask_choose_coordinate_v();
			reminder();
			scanf("%d", &y);
			while (y < 0 || y > 9) //Checks for invalid input.
			{
				system("cls");
				err_msg();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", &x);
			}

			while (p_board[y][x] != '-') //Checks if the initial point chosen overlaps.
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", &x);
				while (x < 0 || x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", &y);
				}
				ask_choose_coordinate_v();
				reminder();
				scanf("%d", &y);
				while (y < 0 || y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", &x);
				}
			}

			overlap_check_h(ship_type, &x, &y, p_board);

			if (ship_type == 'C') //Player chose Carrier.
			{
				if (x <= 3) //If the player chose a coordinate below or at 3.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x++;
					}
				}
				else if (x >= 6) //If the player chose a coordinate above or at 6.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x--;
					}
				}
				else //If the player chose a coordinate at 4 or 5.
				{
					int temp_x = 0, temp_y = 0, num_dash = 0;
					temp_x = x;
					temp_y = y;

					char choice = '\0';
					ask_expand_h();
					scanf(" %c", &choice);

					while (choice != 'l' && choice != 'L' && choice != 'r' && choice != 'R') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_h();
						scanf(" %c", &choice);
					}
					if (choice == 'l' || choice == 'L') //Player chooses to expand left.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x--;
						}
					}
					else //Player chooses to expand right.
					{						
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x++;
						}
					}
				}
			}
			else if (ship_type == 'B') //Player chose Battleship.
			{
				if (x <= 2) //If the player chose a coordinate below or at 2.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x++;
					}
				}
				else if (x >= 7) //If the player chose a coordinate above or at 7.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x--;
					}
				}
				else //If the player chose a coordinate at 3, 4, 5, or 6.
				{
					char choice = '\0';
					ask_expand_h();
					scanf(" %c", &choice);

					while (choice != 'l' && choice != 'L' && choice != 'r' && choice != 'R') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_h();
						scanf(" %c", &choice);
					}
					if (choice == 'l' || choice == 'L') //Player chooses to expand left.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x--;
						}
					}
					else //Player chooses to expand right.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x++;
						}
					}
				}
			}
			else if (ship_type == 'R' || ship_type == 'S') //Player chose Cruiser or Submarine.
			{
				if (x <= 1) //If the player chose a coordinate below or at 1.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x++;
					}
				}
				else if (x >= 8) //If the player chose a coordinate above or at 8.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x--;
					}
				}
				else //If the player chose a coordinate at 2, 3, 4, 5, 6, or 7.
				{
					char choice = '\0';
					ask_expand_h();
					scanf(" %c", &choice);

					while (choice != 'l' && choice != 'L' && choice != 'r' && choice != 'R') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_h();
						scanf(" %c", &choice);
					}
					if (choice == 'l' || choice == 'L') //Player chooses to expand left.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x--;
						}
					}
					else //Player chooses to expand right.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x++;
						}
					}
				}
			}
			else //Player chose Destroyer.
			{
				if (x == 0) //If the player chose a coordinate at 0.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x++;
					}
				}
				else if (x == 9) //If the player chose a coordinate at 9.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						x--;
					}
				}
				else //If the player chose a coordinate at 1, 2, 3, 4, 5, 6, 7, or 8.
				{
					char choice = '\0';
					ask_expand_h();
					scanf(" %c", &choice);

					while (choice != 'l' && choice != 'L' && choice != 'r' && choice != 'R') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_h();
						scanf(" %c", &choice);
					}
					if (choice == 'l' || choice == 'L') //Player chooses to expand left.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x--;
						}
					}
					else //Player chooses to expand right.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							x++;
						}
					}
				}
			}
		}
		else // Player chooses to place their ship vertically.
		{
			disp_player_board(p_board);
			ask_choose_coordinate_v();
			scanf("%d", &y);
			while (y < 0 || y > 9) //Checks for invalid input.
			{
				system("cls");
				err_msg();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", &y);
			}
			ask_choose_coordinate_h();
			scanf("%d", &x);
			while (x < 0 || x > 9) //Checks for invalid input.
			{
				system("cls");
				err_msg();
				disp_player_board(p_board);
				ask_choose_coordinate_h();
				scanf("%d", &x);
			}

			while (p_board[y][x] != '-') //Checks if the initial point chosen overlaps.
			{
				system("cls");
				invld_place();
				disp_player_board(p_board);
				ask_choose_coordinate_v();
				scanf("%d", &y);
				while (y < 0 || y > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_v();
					scanf("%d", &y);
				}
				ask_choose_coordinate_h();
				reminder();
				scanf("%d", &x);
				while (x < 0 || x > 9) //Checks for invalid input.
				{
					system("cls");
					err_msg();
					disp_player_board(p_board);
					ask_choose_coordinate_h();
					scanf("%d", &x);
				}
			}

			overlap_check_v(ship_type, &x, &y, p_board);

			if (ship_type == 'C') //Player chose Carrier.
			{
				if (y <= 3) //If the player chose a coordinate below or at 3.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y++;
					}
				}
				else if (y >= 6) //If the player chose a coordinate above or at 6.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y--;
					}
				}
				else //If the player chose a coordinate at 4 or 5.
				{
					char choice = '\0';
					ask_expand_v();
					scanf(" %c", &choice);

					while (choice != 'u' && choice != 'U' && choice != 'd' && choice != 'D') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_v();
						scanf(" %c", &choice);
					}
					if (choice == 'u' || choice == 'U') //Player chooses to expand upwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y--;
						}
					}
					else //Player chooses to expand downwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y++;
						}
					}
				}
			}
			else if (ship_type == 'B') //Player chose Battleship.
			{
				if (y <= 2) //If the player chose a coordinate below or at 2.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y++;
					}
				}
				else if (y >= 7) //If the player chose a coordinate above or at 7.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y--;
					}
				}
				else //If the player chose a coordinate at 3, 4, 5 or 6.
				{
					char choice = '\0';
					ask_expand_v();
					scanf(" %c", &choice);

					while (choice != 'u' && choice != 'U' && choice != 'd' && choice != 'D') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_v();
						scanf(" %c", &choice);
					}
					if (choice == 'u' || choice == 'U') //Player chooses to expand upwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y--;
						}
					}
					else //Player chooses to expand downwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y++;
						}
					}
				}
			} 
			else if (ship_type == 'R' || ship_type == 'S') //Player chose Cruiser or Submarine.
			{
				if (y <= 1) //If the player chose a coordinate below or at 1.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y++;
					}
				}
				else if (y >= 8) //If the player chose a coordinate above or at 8.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y--;
					}
				}
				else //If the player chose a coordinate at 2, 3, 4, 5, 6 or 7.
				{
					char choice = '\0';
					ask_expand_v();
					scanf(" %c", &choice);

					while (choice != 'u' && choice != 'U' && choice != 'd' && choice != 'D') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_v();
						scanf(" %c", &choice);
					}
					if (choice == 'u' || choice == 'U') //Player chooses to expand upwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y--;
						}
					}
					else //Player chooses to expand downwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y++;
						}
					}
				}
			}
			else //Player chose Destroyer.
			{
				if (y == 0) //If the player chose a coordinate at 0.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y++;
					}
				}
				else if (y == 9) //If the player chose a coordinate at 9.
				{
					for (int index = 0; index < ship_size; index++)
					{
						p_board[y][x] = ship_type;
						y--;
					}
				}
				else //If the player chose a coordinate at 1, 2, 3, 4, 5, 6, 7 or 8.
				{
					char choice = '\0';
					ask_expand_v();
					scanf(" %c", &choice);

					while (choice != 'u' && choice != 'U' && choice != 'd' && choice != 'D') //Checks for invalid input
					{
						system("cls");
						err_msg();
						ask_expand_v();
						scanf(" %c", &choice);
					}
					if (choice == 'u' || choice == 'U') //Player chooses to expand upwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y--;
						}
					}
					else //Player chooses to expand downwards.
					{
						for (int index = 0; index < ship_size; index++)
						{
							p_board[y][x] = ship_type;
							y++;
						}
					}
				}
			}
		}
		system("cls");
	}
}

 //The player's fleet is arranged automatically.
void auto_arr(char p_board[][10])
{
	int x = 0, y = 0, dir = 0, ship_num = 0, lor = 0, dou = 0, check = 0, num_dash;
	for (int count = 0; count < 5; count++)
	{
		ship_num++; //Ensures that the same ship isn't picked twice.
		dir = (rand() % 2); //Randomly determines if the ship is going to be oriented horizontally or vertially.

		if (dir == 1) //Horizontal
		{
			y = (rand() % 10);
			x = (rand() % 10);

			if (ship_num == 1) //Carrier ship
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (x <= 3) 
				{
					for (int index = 0; index < 5; index++)
					{
						p_board[y][x] = 'C';
						x++;
					}
				}
				else if (x >= 6)
				{
					for (int index = 0; index < 5; index++)
					{
						p_board[y][x] = 'C';
						x--;
					}
				}
				else //Either position 4 or 5.
				{
					lor = (rand() % 2); //Determines if ship is extended left or right
					if (lor == 0) //Extend left 
					{
						for (int index = 0; index < 5; index++)
						{
							p_board[y][x] = 'C';
							x--;
						}
					}
					else //Extend right
					{
						for (int index = 0; index < 5; index++)
						{
							p_board[y][x] = 'C';
							x++;
						}
					}
				}
			}
			else if (ship_num == 2) //Battleship
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (x <= 2)
				{
					for (int index = 0; index < 4; index++)
					{
						p_board[y][x] = 'B';
						x++;
					}
				}
				else if (x >= 7)
				{
					for (int index = 0; index < 4; index++)
					{
						p_board[y][x] = 'B';
						x--;
					}
				}
				else //Either postion 3, 4, 5 or 6
				{
					lor = (rand() % 2); //Determines if ship is extended left or right
					if (lor == 0) //Extend left
					{
						for (int index = 0; index < 4; index++)
						{
							p_board[y][x] = 'B';
							x--;
						}
					}
					else //Extend right
					{
						for (int index = 0; index < 4; index++)
						{
							p_board[y][x] = 'B';
							x++;
						}
					}
				}
			}
			else if (ship_num == 3) //Cruiser ship
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (x <= 1)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'R';
						x++;
					}
				}
				else if (x >= 8)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'R';
						x--;
					}
				}
				else //Either position 2, 3, 4, 5, 6 or 7
				{
					lor = (rand() % 2); //Determines if ship is extended left or right
					if (lor == 0) //Extend left
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'R';
							x--;
						}
					}
					else //Extend right
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'R';
							x++;
						}
					}
				}
			}
			else if (ship_num == 4) //Submarine
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (x <= 1)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'S';
						x++;
					}
				}
				else if (x >= 8)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'S';
						x--;
					}
				}
				else //Either posiiton 2, 3, 4, 5, 6 or 7
				{
					lor = (rand() % 2); //Determines if ship is extended left or right
					if (lor == 0) //Extend left
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'S';
							x--;
						}
					}
					else //Extemd right
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'S';
							x++;
						}
					}
				}
			}
			else //Destroyer ship
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (x == 0)
				{
					for (int index = 0; index < 2; index++)
					{
						p_board[y][x] = 'D';
						x++;
					}
				}
				else if (x == 9)
				{
					for (int index = 0; index < 2; index++)
					{
						p_board[y][x] = 'D';
						x--;
					}
				}
				else //Either position 1 to 8.
				{
					lor = (rand() % 2); //Determines if ship is extended left or right
					if (lor == 0) //Extend left
					{
						for (int index = 0; index < 2; index++)
						{
							p_board[y][x] = 'D';
							x--;
						}
					}
					else //Extend right
					{
						for (int index = 0; index < 2; index++)
						{
							p_board[y][x] = 'D';
							x++;
						}
					}
				}
			}
		}
		else //Vertical
		{ 
			y = (rand() % 10);
			x = (rand() % 10);
			if (ship_num == 1) //Carrier
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (y <= 3) 
				{
					for (int index = 0; index < 5; index++)
					{
						p_board[y][x] = 'C';
						y++;
					}
				}
				else if (y >= 6)
				{
					for (int index = 0; index < 5; index++)
					{
						p_board[y][x] = 'C';
						y--;
					}
				}
				else //Either position 4 or 5.
				{
					dou = (rand() % 2); //Determines if ship is extended up or down
					if (dou == 0) //Extend up 
					{
						for (int index = 0; index < 5; index++)
						{
							p_board[y][x] = 'C';
							y--;
						}
					}
					else //Extend dowb
					{
						for (int index = 0; index < 5; index++)
						{
							p_board[y][x] = 'C';
							y++;
						}
					}
				}
			}
			else if (ship_num == 2) //Battleship
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (y <= 2)
				{
					for (int index = 0; index < 4; index++)
					{
						p_board[y][x] = 'B';
						y++;
					}
				}
				else if (y >= 7)
				{
					for (int index = 0; index < 4; index++)
					{
						p_board[y][x] = 'B';
						y--;
					}
				}
				else //Either position 3, 4, 5 or 6
				{
					dou = (rand() % 2); //Determines if ship is extended up or down
					if (dou == 0) //Extend up 
					{
						for (int index = 0; index < 4; index++)
						{
							p_board[y][x] = 'B';
							y--;
						}
					}
					else //Extend down
					{
						for (int index = 0; index < 4; index++)
						{
							p_board[y][x] = 'B';
							y++;
						}
					}
				}
			}
			else if (ship_num == 3) //Cruiser
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (y <= 1)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'R';
						y++;
					}
				}
				else if (y >= 8)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'R';
						y--;
					}
				}
				else //Either position 2, 3, 4, 5, 6 or 7
				{
					dou = (rand() % 2); //Determines if ship is extended up or down
					if (dou == 0) //Extend up 
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'R';
							y--;
						}
					}
					else //Extend down
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'R';
							y++;
						}
					}
				}
			}
			else if (ship_num == 4) //Submarine
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (y <= 1)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'S';
						y++;
					}
				}
				else if (y >= 8)
				{
					for (int index = 0; index < 3; index++)
					{
						p_board[y][x] = 'S';
						y--;
					}
				}
				else //Either position 2, 3, 4, 5, 6 or 7
				{
					dou = (rand() % 2); //Determines if ship is extended up or down
					if (dou == 0) //Extend up 
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'S';
							y--;
						}
					}
					else //Extend down
					{
						for (int index = 0; index < 3; index++)
						{
							p_board[y][x] = 'S';
							y++;
						}
					}
				}
			}
			else //Destroyer
			{
				while (p_board[y][x] != '-')
				{
					y = (rand() % 10);
					x = (rand() % 10);
				}

				if (y == 0)
				{
					for (int index = 0; index < 2; index++)
					{
						p_board[y][x] = 'D';
						y++;
					}
				}
				else if (y == 9)
				{
					for (int index = 0; index < 2; index++)
					{
						p_board[y][x] = 'D';
						y--;
					}
				}
				else //Either position 1 to 8.
				{
					dou = (rand() % 2); //Determines if ship is extended up or down
					if (dou == 0) //Extend up 
					{
						for (int index = 0; index < 2; index++)
						{
							p_board[y][x] = 'D';
							y--;
						}
					}
					else //Extend down
					{
						for (int index = 0; index < 2; index++)
						{
							p_board[y][x] = 'D';
							y++;
						}
					}
				}
			}
		}

	}
}

//Asks the player for a location to shoot and "shoots" the location specified.
void shoot(char p_board[][10], char p_strat_board[][10], char enemy_board[][10], p_stats* hit, p_stats* miss, p_stats* shot, FILE* outfile)
{
	int x = 0, y = 0;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Here's your strategy board and your main board ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	disp_player_board(p_strat_board); //Shows the strategy board for player 1.
	printf("\n");
	disp_player_board(p_board); //Shows player 1's board.
	disp_cont();
	getch();

	system("cls");
	disp_player_board(p_strat_board);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Please choose a horizontal and vertical coordinate to shoot on the opponent's board (x, y) ~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf("%d%d", &x, &y);
	while (x < 0 || x > 9 || y < 0 || y > 9) //Checks for invalid input.
	{
		system("cls");
		err_msg();
		disp_player_board(p_strat_board);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Please choose a horizontal and vertical coordinate to shoot on the opponent's board (x, y) ~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf("%d%d", &x, &y);
	}

	while (p_strat_board[y][x] == '*' || p_strat_board[y][x] == 'm') //Determines if the player chose a location they've already picked.
	{
		system("cls");
		err_msg();
		disp_player_board(p_strat_board);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Please choose a horizontal and vertical coordinate to shoot on the opponent's board (x, y) ~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf("%d%d", &x, &y);
		while (x < 0 || x > 9 || y < 0 || y > 9) //Checks for invalid input.
		{

			system("cls");
			err_msg();
			disp_player_board(p_strat_board);
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("~ Please choose a horizontal and vertical coordinate to shoot on the opponent's board (x, y) ~\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			scanf("%d%d", &x, &y);
		}
	}

	log_shot_msg(outfile, x, y, 1);

	if (enemy_board[y][x] == '-')
	{
		enemy_board[y][x] = 'm';
		p_strat_board[y][x] = 'm';
		printf("~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ %d, %d is a miss! ~~\n", x, y);
		printf("~~~~~~~~~~~~~~~~~~~~~~\n");
		miss->num_miss++;
		log_miss_msg(outfile);
	}
	else
	{
		enemy_board[y][x] = '*';
		p_strat_board[y][x] = '*';
		printf("~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ %d, %d is a hit! ~~\n", x, y);
		printf("~~~~~~~~~~~~~~~~~~~~~\n");
		hit->num_hit++;
		log_hit_msg(outfile);
	}
	shot->num_shots++;
}

//Sets the player's board to all '-'s.
void null_board(char p_board[][10])
{
	for (int row_ind = 0; row_ind < 10; row_ind++)
	{
		for (int col_ind = 0; col_ind < 10; col_ind++)
		{
			p_board[row_ind][col_ind] = '-';
		}
	}
}

//Displays the player's board, with the coordinates.
void disp_player_board(char p_board[][10])
{
	int count = 0;
	printf("  0 1 2 3 4 5 6 7 8 9\n");
	for (int row_ind = 0; row_ind < 10; row_ind++)
	{
		printf("%d ", count);
		for (int col_ind = 0; col_ind < 10; col_ind++)
		{
			printf("%c ", p_board[row_ind][col_ind]);
		}
		count++;
		putchar('\n');
	}
}

//Determines if the player or bot has lost their fleet or not.
void check_defeat(char p_board[][10], p_stats* w_or_l)
{
	int count = 0;
	for (int row_ind = 0; row_ind < 10; row_ind++)
	{
		for (int col_ind = 0; col_ind < 10; col_ind++)
		{
			if (p_board[row_ind][col_ind] == 'C' || p_board[row_ind][col_ind] == 'B' || p_board[row_ind][col_ind] == 'R' || p_board[row_ind][col_ind] == 'S' 
				|| p_board[row_ind][col_ind] == 'D')
				count++;
		}
	}

	if (count == 0)
		w_or_l->win_or_lose++;
}

//Calculates the scores/stats of the players.
void calc_stats(p_stats p1_hit, p_stats p1_miss, p_stats p1_shot, p_stats* p1_h_m_rat, p_stats p2_hit, p_stats p2_miss, p_stats p2_shot,
	p_stats* p2_h_m_rat, int* tot_hits, int* tot_miss, int* tot_shots)
{
	*tot_hits = p1_hit.num_hit + p2_hit.num_hit;
	*tot_miss = p1_miss.num_miss + p2_miss.num_miss;
	*tot_shots = p1_shot.num_shots + p2_shot.num_shots;
	p1_h_m_rat->hit_miss_rat = ((double)p1_hit.num_hit / p1_miss.num_miss) * 100;
	p2_h_m_rat->hit_miss_rat = ((double)p2_hit.num_hit / p2_miss.num_miss) * 100;
}

//Asks the player if they want to play again.
int replay(void)
{
	char decide = '\0';
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Do you want to play again? (Y | N)~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	scanf(" %c", &decide);
	while (decide != 'Y' && decide != 'y' && decide != 'N' && decide != 'n') //Checks for invalid input.
	{
		system("cls");
		err_msg();
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Do you want to play again? (Y | N)~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf(" %c", &decide);
	}
	
	if (decide == 'Y' || decide == 'y')
		return 1;
	else
		return 0;
}

//Checks to see if a ship has sunk or not.
void check_sunk_ship(char p_board[][10], FILE* outfile)
{
	int ship[5] = { 0, 0, 0, 0, 0 }, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, sinks = 0;

	for (int row_ind = 0; row_ind < 10; row_ind++)
	{
		for (int col_ind = 0; col_ind < 10; col_ind++)
		{
			if (p_board[row_ind][col_ind] == 'C')
				count1++;
			else if (p_board[row_ind][col_ind] == 'B')
				count2++;
			else if (p_board[row_ind][col_ind] == 'R')
				count3++;
			else if (p_board[row_ind][col_ind] == 'S')
				count4++;
			else
				count5++;
		}
	}

	ship[0] = count1;
	ship[1] = count2;
	ship[2] = count3;
	ship[3] = count4;
	ship[4] = count5;

	for (int index = 0; index < 5; index++)
	{
		if (ship[index] == 0)
			sinks++;
	}

	if (sinks == 1)
		fprintf(outfile, "A ship has been sunk!\n\n");
	else if (sinks == 2)
		fprintf(outfile, "Two ship has been sunk!\n\n");
	else if (sinks == 3)
		fprintf(outfile, "A ship has been sunk!\n\n");
	else if (sinks == 4)
		fprintf(outfile, "A ship has been sunk!\n\n");
	else if (sinks == 5)
		fprintf(outfile, "A ship has been sunk!\n\n");
}
