#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <String.h>

void disp_game(void);
void disp_rules(void);
void disp_choice(void);
void disp_cont(void);
void disp_gbye(void);
void err_msg(void);
void invld_place(void);
void reminder(void);
void ask_choose_coordinate_h(void);
void ask_choose_coordinate_v(void);
void ask_expand_h(void);
void ask_expand_v(void);
void ellipses(void);
void log_shot_msg(FILE* outfile, int x, int y, int player);
void log_hit_msg(FILE* outfile);
void log_miss_msg(FILE* outfile);
void log_win_lose(FILE* outfile, int player);
int replay(void);


void hori_or_verti(int *direction);
void ask_which_ship(int* ship, char* ship_type, char select[][45]);
void manual_or_automatic(int *manual_or_automatic);
void manual_arr(char p_board[][10]);
void auto_arr(char p_board[][10]);
void overlap_check_h(char ship_type, int* x, int* y, char p_board[][10]);
void overlap_check_v(char ship_type, int* x, int* y, char p_board[][10]);
void null_board(char p_board[][10]);
void disp_player_board(char p_board[][10]);
void check_sunk_ship(char p_board[][10], FILE* outfile);

typedef struct player_stats
{
	int num_hit;
	int num_miss;
	int num_shots;
	double hit_miss_rat;
	int win_or_lose;
} p_stats;

void shoot(char p_board[][10], char p_strat_board[][10], char enemy_board[][10], p_stats* hit, p_stats* miss, p_stats* shot, FILE* outfile);
void check_defeat(char p_board[][10], p_stats* w_or_l);
void calc_stats(p_stats p1_hit, p_stats p1_miss, p_stats p1_shot, p_stats* p1_h_m_rat, p_stats p2_hit, p_stats p2_miss, p_stats p2_shot,
	p_stats* p2_h_m_rat, int* tot_hits, int* tot_miss, int* tot_shots);



#endif