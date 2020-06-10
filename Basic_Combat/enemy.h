#ifndef ENEMY_H
#define ENEMY_H

class Enemy{
	private:
		char name;
		int hp;
		int damage;
		int exp;
		int speed;
	
	public:
	Enemy();
	Enemy(char na, int h, int da, int ex, int se);
	void set_values(char na, int h, int da, int ex, int se);
	
	int get_damage();
	int get_exp();
	char get_name();
	
	void take_damage(int damage);
	int get_hp();
	int get_speed();
	
};

#endif 