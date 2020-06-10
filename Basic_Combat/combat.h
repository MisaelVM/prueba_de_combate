#ifndef COMBAT_H
#define COMBAT_H

#include "player.h"
#include "enemy.h"

class Combat{
	private:
		int *turn;
		int combat_size;
		int position;
		int players_size;
		int enemies_size;
		bool playerturn;
		bool escape;
		bool playerdefeated;
		bool enemydefeated;
		
	public:
		Combat();
		Combat(Player players[], Enemy enemies[], const int players_team, const int enemies_team);
		virtual ~Combat();
		
		void put_speed(Player players[], Enemy enemies[]);
		void sort_speed();
		void show_array();
		
		void change_array();
		void search_turn(Player players[], Enemy enemies[]);
		void initCombat(Player players[], Enemy enemies[]);
		void remove(Player players[], Enemy enemies[], int n);
};

#endif