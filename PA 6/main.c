/* 
   Name: Denise Tanumihardja
   Class: Cpts 121
   Project: Programming Assignment 5 (PA 5)
   Date: 8 March 2020
   Description: The program runs a game of Batttleship. The player will be asked to place their fleet, which consists of a Carrier (5 cells), a Battleship 
                (4 cells), a Cruiser (3 cells), a Submarine (3 cells), and a Destroyer (2 cells). They will be asked to either place it manually or let it
				be done automatically. Each player will then get a chance to shoot a specific cell once and the objective is to sink all of the opponent's 
				ships/fleet. There is only one human player as the second player will be a bot, which will randomly choose a location to shoot. The order of
				turns is randomly decided and during and after the game ends, a file with the number of total hits, misses, shots, hit-miss ratio, and 
				which player won, is generated called Battleship.log.
*/

#include "header.h"

int main(void)
{
	int num = 0;
	do
	{
		disp_game(); //Displays the game intro
		int start = 0;
		p_stats p1_stats = { 0, 0, 0, 0.0 ,0 }, p2_stats = { 0, 0, 0, 0.0, 0 };
		char p1_board[10][10], p2_board[10][10], p1_strat_board[10][10];
		FILE *outfile = NULL;
		outfile = fopen("Battleship.log", "w");
		null_board(p1_board); //Sets player 1's board to all "-"s.
		null_board(p2_board); //Sets player 2's board to all "-"s.
		null_board(p1_strat_board); //Sets player 1's strategy board to all "-"s.

		disp_choice(); //Displays the choices to proceed by the player.
		scanf("%d", &num);
		while (num < 1 || num > 3) //Checks for invalid input.
		{
			system("cls");
			err_msg();
			disp_choice();
			scanf("%d", &num);
		}

		switch (num)
		{
		case 1: //Play game
		{
			system("cls");
			srand((unsigned int)time(NULL));
			int manu_auto = 0;
			manual_or_automatic(&manu_auto); //Determines if the player wants to manually place their fleet or let the computer do it.
			if (manu_auto == 0)
			{
				manual_arr(p1_board); //Lets the player manually arrange their fleet.
			}
			else
				auto_arr(p1_board); //Automatically arranges the player's fleet.

			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("~ Player 2's board has been generated ~\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			auto_arr(p2_board); //Automatically arranged the bot's fleet.

			disp_cont();
			getch();
			
			start = rand() % 2;
			if (start == 0) //Player 1 starts first
			{
				do
				{
					system("cls");
					printf("~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Player 1 start! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~\n");

					shoot(p1_board, p1_strat_board, p2_board, &p1_stats, &p1_stats, &p1_stats, outfile);
					check_sunk_ship(p2_board, outfile);
					check_defeat(p2_board, &p1_stats);

					disp_cont();
					getch();
					system("cls");

					printf("~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Player 2 start! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~\n");
					ellipses();
					ellipses();
					ellipses();
					disp_cont();
					getch();

					int x = 0, y = 0;
					x = rand() % 10;
					y = rand() % 10;
					while (p1_board[y][x] == '*' || p1_board[y][x] == 'm')
					{
						x = rand() % 10;
						y = rand() % 10;
					}

					log_shot_msg(outfile, x, y, 2);

					if (p1_board[y][x] == '-')
					{
						p1_board[y][x] = 'm';
						printf("~~~~~~~~~~~~~~~~~~~~~~\n");
						printf("~ %d, %d is a miss! ~~\n", x, y);
						printf("~~~~~~~~~~~~~~~~~~~~~~\n");
						p2_stats.num_miss++;
						log_miss_msg(outfile);
					}
					else
					{
						p1_board[y][x] = '*';
						printf("~~~~~~~~~~~~~~~~~~~~~\n");
						printf("~ %d, %d is a hit! ~~\n", x, y);
						printf("~~~~~~~~~~~~~~~~~~~~~\n");
						p2_stats.num_hit++;
						log_hit_msg(outfile);
					}
					p2_stats.num_shots++;

					check_sunk_ship(p1_board, outfile);
					check_defeat(p1_board, &p2_stats);

					disp_cont();
					getch();

				} while (p1_stats.win_or_lose == 0 && p2_stats.win_or_lose == 0);

				system("cls");
				if (p1_stats.win_or_lose == 1) //If player 1 wins
				{
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Congrats, Player 1 wins! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					log_win_lose(outfile, 1);
					disp_cont();
					getch();
				}
				else if (p2_stats.win_or_lose == 1) //If the bot wins.
				{
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Too bad, Player 2 wins! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					log_win_lose(outfile, 2);
					disp_cont();
					getch();
				}

				int tot_hit = 0, tot_miss = 0, tot_shot = 0; 
				calc_stats(p1_stats, p1_stats, p1_stats, &p1_stats, p2_stats, p2_stats, p2_stats, &p2_stats, &tot_hit, &tot_miss, &tot_shot);

				fprintf(outfile, "\nThroughout the game, there had been %d shots, %d hits and %d misses!\n", tot_shot, tot_hit, tot_miss);
				fprintf(outfile, "Player 1's hit to miss ratio was %.2lf%!\n", p1_stats.hit_miss_rat);
				fprintf(outfile, "Player 2's hit to miss ratio was %.2lf%!\n", p2_stats.hit_miss_rat);

			}
			else //Player 2 (bot) starts first
			{
				do
				{
					system("cls");
					printf("~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Player 2 start! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~\n");
					ellipses();
					ellipses();
					ellipses();
					disp_cont();
					getch();

					int x = 0, y = 0;
					x = rand() % 10;
					y = rand() % 10;
					while (p1_board[y][x] == '*' || p1_board[y][x] == 'm')
					{
						x = rand() % 10;
						y = rand() % 10;
					}

					log_shot_msg(outfile, x, y, 2);

					if (p1_board[y][x] == '-')
					{
						p1_board[y][x] = 'm';
						printf("~~~~~~~~~~~~~~~~~~~~~~\n");
						printf("~ %d, %d is a miss! ~~\n", x, y);
						printf("~~~~~~~~~~~~~~~~~~~~~~\n");
						p2_stats.num_miss++;
						log_miss_msg(outfile);
						disp_cont();
						getch();
					}
					else
					{
						p1_board[y][x] = '*';
						printf("~~~~~~~~~~~~~~~~~~~~~\n");
						printf("~ %d, %d is a hit! ~~\n", x, y);
						printf("~~~~~~~~~~~~~~~~~~~~~\n");
						p2_stats.num_hit++;
						log_hit_msg(outfile);
						disp_cont();
						getch();
					}
					p2_stats.num_shots++;

					check_sunk_ship(p1_board, outfile);
					check_defeat(p1_board, &p2_stats);
					system("cls");

					printf("~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Player 1 start! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~\n");

					shoot(p1_board, p1_strat_board, p2_board, &p1_stats, &p1_stats, &p1_stats, outfile);
					check_sunk_ship(p2_board, outfile);
					check_defeat(p2_board, &p1_stats);

				} while (p1_stats.win_or_lose == 0 && p1_stats.win_or_lose == 0);

				system("cls");
				if (p1_stats.win_or_lose == 1) //If player 1 wins
				{
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Congrats, Player 1 wins! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					log_win_lose(outfile, 1);
					disp_cont();
					getch();
				}
				else if (p2_stats.win_or_lose == 1) //If the bot wins.
				{
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					printf("~ Too bad, Player 2 wins! ~\n");
					printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					log_win_lose(outfile, 2);
					disp_cont();
					getch();
				}

				int tot_hit = 0, tot_miss = 0, tot_shot = 0;
				calc_stats(p1_stats, p1_stats, p1_stats, &p1_stats, p2_stats, p2_stats, p2_stats, &p2_stats, &tot_hit, &tot_miss, &tot_shot);

				fprintf(outfile, "\nThroughout the game, there had been %d shots, %d hits and %d misses!\n", tot_shot, tot_hit, tot_miss);
				fprintf(outfile, "Player 1's hit to miss ratio was %.2lf%!\n", p1_stats.hit_miss_rat);
				fprintf(outfile, "Player 2's hit to miss ratio was %.2lf%!\n", p2_stats.hit_miss_rat);
			}
			fclose(outfile);
			system("cls");

			//Determines if the player wants to play again or not
			int decide = 0;
			decide = replay();
			if (decide == 1)
				system("cls");
			else
				num = 4;
		}
		break;
		case 2: //Displays the rules
		{
			system("cls");
			disp_rules();
			disp_cont();
			getch();
			system("cls");
		}
		break;
		case 3: num = 4; //Exits the game
			break;
		}
	} while (num >= 1 && num <= 3);

	system("cls");
	disp_gbye();

	return 0;
}