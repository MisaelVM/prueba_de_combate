#include <iostream>
#include "enemy.h"

Enemy::Enemy(){
	name='p';
	hp=50;
	damage=20;
	exp=5;	
	speed=11;
}

Enemy::Enemy(char na, int h, int da, int ex, int se){
	name=na;
	hp=h;
	damage=da;
	exp=ex;	
	speed=se;
}


void Enemy::set_values(char na, int h, int da, int ex, int se){
	name=na;
	hp=h;
	damage=da;
	exp=ex;	
	speed=se;
}

int Enemy::get_damage(){
	return damage;
}

int Enemy::get_exp(){
	return exp;
}

char Enemy::get_name(){
	return name; 
}

void Enemy::take_damage(int damage){
	hp -= damage;
	if(hp<=0)
		hp=0;
}

int Enemy::get_hp(){
	return hp;
}

int Enemy::get_speed(){
	return speed;
}