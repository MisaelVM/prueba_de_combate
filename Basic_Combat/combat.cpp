#include <iostream>
#include<cstdlib> //random numbers
#include "combat.h"

Combat::Combat(){
	playerturn=false;
	escape=false;
	playerdefeated=false;
	enemydefeated=false;
	position=0;
	players_size=1;
	enemies_size=1;
	
}
Combat::Combat(Player players[], Enemy enemies[], const int players_team, const int enemies_team){
	playerturn=false;
	escape=false;
	playerdefeated=false;
	enemydefeated=false;
	position=0;
	players_size=players_team;
	enemies_size=enemies_team;
	put_speed(players,enemies);
	initCombat(players,enemies);
}
Combat::~Combat(){
	delete turn;
}

//put the speed values of enemies and players into the array "turn"
void Combat::put_speed(Player players[], Enemy enemies[]){
	combat_size = players_size + enemies_size;
	turn=new int[combat_size];
	int n=0;
	while(n<combat_size){
		for(int i=0; i<players_size; i++){
			*(turn+n)=players[i].get_speed();
			n++;
		}
		for(int j=0; j<enemies_size; j++){
			*(turn+n)=enemies[j].get_speed();
			n++;
		}
	}
	sort_speed();
}

void Combat::sort_speed(){
	int key=0, i, j; //selection sort 
	for (i = 1; i < combat_size; i++){  
        key = *(turn+i);		
        j = i - 1;  
       
        while (j >= 0 && *(turn+j) > key){  
            *(turn+j+1) = *(turn+j);
            j = j - 1;  
        }  
        *(turn+j+1) = key;
    }
	for(int j=0;j<combat_size/2;j++){ //invert the sort
		int a=*(turn+j);
		*(turn+j)=*(turn + combat_size-1-j);
		*(turn+combat_size-1-j)=a;
	}		
}


void Combat::show_array(){
	for(int i=0; i<combat_size; i++)
		std::cout<<*(turn+i)<<"\t";
	std::cout<<"\n";
}

void Combat::change_array(){ //put the first value at the end of the array; 
	int copy = *(turn+0);
	for(int i=0; i<combat_size-1; i++){
		*(turn+i)=*(turn+i+1);
	}
	*(turn+combat_size-1)=copy;
}

void Combat::search_turn(Player players[], Enemy enemies[]){ 
	int turn_of = *(turn+0);
	for(int i=0; i< players_size; i++)
		if(turn_of == players[i].get_speed()){ //find where the first value of "turn" in the array "players"
			position=i;
			playerturn=true;
			break;			
		}
	for(int j=0; j<enemies_size; j++ )
		if(turn_of == enemies[j].get_speed()){
			position=j;
			playerturn=false;	
			break;
		}
	change_array();
}

void Combat::initCombat(Player players[], Enemy enemies[]){
	std::cout<<"turn based combat\n";
	int choice=0;
	int second_choice=0;
	int order=0;
	while(!escape || enemies_size>=0 || players_size>=0){ 
		show_array();
		search_turn(players, enemies);
		std::cout<<"\n";
		
		if (playerturn && enemies_size!=0 && players_size!=0){ //turn of players
			do{
				std::cout<<"turn of player: "<<players[position].get_name()<<"\n";
				std::cout<<"(0)attack\n(1)escape"<<"\n";
				std::cin>>choice;
				switch(choice){ //actions
					case 0://attack
						std::cout<<"choose the enemy\n";
						for(int i=0; i<enemies_size; i++){
							std::cout<<"("<<i<<")"<<"enemy: "<<enemies[i].get_name()<<"\n";
						}
						std::cout<<"("<<enemies_size<<")back:"<<"\n";
						std::cin>>second_choice;
						
						if(second_choice<enemies_size){ 
							std::cout<<"-"<<players[position].get_damage()<<"\n";
							enemies[second_choice].take_damage(players[position].get_damage());
							std::cout<<"enemy "<<enemies[second_choice].get_name()<<" hp:"<<enemies[second_choice].get_hp()<<"\n";
							
							if(enemies[second_choice].get_hp()==0){ //if enemy is dead
								std::cout<<"enemy: "<<enemies[second_choice].get_name()<<" defeated\n";
								enemydefeated=true;
								for(int j=0; j<players_size; j++){	
									players[j].gain_level(enemies[second_choice].get_exp());
								}
								remove(players,enemies,second_choice);
								enemydefeated=false;
							}
						}
						break;
			
					case 1://escape
						escape=true;
						break;
				}
			}while(second_choice==enemies_size && choice!=1 && enemies_size!=0); 
		}
		else if(!playerturn && enemies_size!=0 && players_size!=0){ //turn of enemies
			std::cout<<"turn of enemy: "<<enemies[position].get_name()<<"\n";
			std::cout<<"enemy attacks to: ";
			order=rand()%players_size; //choose the player
			
			std::cout<<players[order].get_name()<<"\n";
			std::cout<<"-"<<enemies[position].get_damage()<<"\n";
			players[order].take_damage(enemies[position].get_damage());//damage
			std::cout<<"player "<<players[order].get_name()<<" hp:"<<players[order].get_hp()<<"\n";
			
			if(players[order].get_hp()==0){// player is dead
				std::cout<<"player: "<<players[order].get_name()<<" defeated\n";
				playerdefeated=true;
				remove(players,enemies,order);
				playerdefeated=false;
			}
			
		}
		if(escape==true){
			std::cout<<"you run away!!!!\n";
			break;
		}
		std::cout<<"\n";
		if(enemies_size==0){
			std::cout<<"you win!\n";
			break;
		}
		if(players_size==0){
			std::cout<<"you lost!\n";
			break;
		}
	}
}

void Combat::remove(Player players[], Enemy enemies[], int n){ //remove a player or enemy
	if(enemydefeated){
		for(int i=0; i<enemies_size; i++)
            if(i==n)
                for(int j=i; j<enemies_size-1; j++)
                    enemies[j]=enemies[j+1];
		enemies_size--;
		put_speed(players,enemies);
		
	}
	if(playerdefeated){
		for(int i=0; i<players_size; i++)
            if(i==n)
                for(int j=i; j<players_size-1; j++)
                    players[j]=players[j+1];
		players_size--;
		put_speed(players,enemies);
	}
	enemydefeated=false;
	playerdefeated=false;
}