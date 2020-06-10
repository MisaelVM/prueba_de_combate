#include "combat.h"
#include<cstdlib>
#include<ctime>
int main(){
	srand((unsigned)time(0));
	int players_team=2;
	int enemies_team=3;
    
	Player players[players_team];	
	players[0].set_values('s',50,100,40,13);//(name, hp, exp_next, damage,speed)
	players[1].set_values('w',40,200,10,10);
	
	Enemy enemies[enemies_team];
	enemies[0].set_values('e',50,10,50,11); //(name,hp,damage,exp_drops,speed)
	enemies[1].set_values('E',50,10,25,12);
	enemies[2].set_values('b',50,5,25,9);
	
	Combat enemy_appears(players,enemies, players_team, enemies_team);
	
    return 0;
}

