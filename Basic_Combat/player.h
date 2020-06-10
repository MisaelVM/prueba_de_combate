#ifndef Player_H
#define Player_H

class Player{
	private:
		char name;
		int level;
		int exp;
		int expNext;
	
		int hp;
		int hpmax;
		int damage;
		int speed;
		
	public:
		Player();
		Player(char n, int h, int expNext, int da, int spe);
		virtual ~Player();
		
		void set_values(char n, int h, int expNext, int da, int spe);
		int get_damage();
		char get_name();
		
		void gain_level(const int expEnemy);
		void update_Stats();
		void show_stats();
		int get_exp();
		
		void take_damage(const int damage);
		int get_hp();
		int get_speed();
};
#endif