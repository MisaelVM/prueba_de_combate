#include <iostream>
#include "player.h"

Player::Player(){
	name='e';
	hp=50;
	hpmax=50;
	exp=0;
	expNext=100;
	level=1;
	damage=30;
	speed=12;
}

Player::Player(char n, int h, int Next, int da, int spe){
	name= n;
	hp=h;
	hpmax=h;
	exp=0;
	expNext=Next;
	level=1;
	damage=da;
	speed=spe;
}

Player::~Player(){
}

void Player::set_values(char n, int h, int Next, int da, int spe){
	name= n;
	hp=h;
	hpmax=h;
	expNext=Next;
	damage=da;
	speed=spe;
}

int Player::get_damage(){
	return damage;
}

char Player::get_name(){
	return name;
}

void Player::gain_level(const int expEnemy){
	exp += expEnemy;
	
	if(expNext==exp)
		update_Stats();
}

void Player::update_Stats(){
	std::cout<<"level up\n";
	expNext *= 2;
	hpmax *= 2;
	hp = hpmax;
	level++;
	damage *=2;
	speed *=2;
	show_stats();
}

void Player::show_stats(){
	std::cout<<"player: "<<name<<"\n";
	std::cout<<"hp: "<<hp<<"\n";
	std::cout<<"exp: "<<exp<<"\n";
	std::cout<<"expNext: "<<expNext<<"\n";
	std::cout<<"level: "<<level<<"\n";
	std::cout<<"damage"<<damage<<"\n";
	std::cout<<"speed"<<speed<<"\n";
	std::cout<<"\n";
}

int Player::get_exp(){
	return exp;
}

void Player::take_damage(int damage){
	hp -= damage;
	if(hp<=0)
		hp=0;
}

int Player::get_hp(){
	return hp;
}

int Player::get_speed(){
	return speed;
}
