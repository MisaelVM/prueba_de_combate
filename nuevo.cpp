#include <iostream>
#include <math.h>
#include <string>


class table_element
{
    std::string* element_list;
    int _size;
    int** array_weakness;
public:
    table_element(std::string[], int);
    void set_debilities(std::string, std::string, std::string);
    std::string get_element(int);
    void show_table();
    ~table_element();
};

class stats
{
    std::string* stadistic_name;
    int* value;
    int _size;
public:
    stats();
    stats(std::string[], int[], int);
    stats(stats&);
    std::string get_stat_name(int);
    int get_stat_value(int);
    int get_size();
    void set_value(int[]);
    void set_v_value(int, int);
    void set_name(std::string[]);
    void sum_value(int, int);
    void show_data();
    ~stats();
};
class level
{
    double act_level;
    double experience;
    double necesary_exp;
    double total_exp;
    double max_level;
    double constant;
public:
    level();
    level(double, double, double, double, double, double);
    level(level&);
    double get_total_exp();
    double get_level();
    double get_experience();
    double get_necesary_experience();
    double get_max_level();
    double get_constant();
    void set_necesary_experience();
    void add_exp(double);
    void level_up(int);
    void validation_system();
};

class ability
{
    std::string name;
    std::string state;
    int power;
    std::string element;
    std::string state_name;
    int consume;
public:
    ability();
    ability(ability&);
    ability(std::string, std::string, int, table_element&, int, std::string, int);
    std::string get_name();
    std::string get_state();
    int get_power();
    int get_consume();
    std::string get_element();
    std::string get_state_name();
    void show_data();
};

class item
{
protected:

    std::string name;
    std::string description;
public:
    item();
    item(std::string, std::string);
    virtual std::string get_name();
    virtual std::string get_description();
    virtual void show_data();
};

class weapon : public item
{
    std::string weapon_type;
    std::string element;
    int* buff_debuff;
    int _size;
public:
    weapon();
    weapon(weapon&);
    weapon(std::string, std::string, std::string, table_element, int, int[], int);
    std::string get_name();
    std::string get_decription();
    std::string get_weapon_type();
    std::string get_element();
    int get_buff_debuff(int);
    int get_size();
    void show_data();
    ~weapon();
};

class role
{
    std::string name, code_stats, code_weapons;
    ability* hab;
    level level_of_role;
    int* level_to_use;
    int _size;
public:
    role();
    role(role&);
    role(std::string, std::string, std::string, ability[], level, int[], int);
    std::string get_name();
    std::string get_code_stats();
    std::string get_code_weapons();
    int get_size();
    level get_lvl();
    int get_level_to_use(int);
    ability& get_ability(int);
    void add_level(int);
    void display_habs();
    int get_level();
    void show_data();
    ~role();
};

class character
{
    std::string name;
    stats _stats;
    stats act_stats;
    int size_of_roles;
    level _level;
    role* roles;
    int* point_role;
    weapon* equipment;
    int num_of_equip;
    int* constant;
public:
    character();
    character(std::string, stats, int, level, role[], int, int[]);
    ability get_ability(int, int);
    int get_num_of_roles();
    int get_num_of_equip();
    std::string get_name();
    stats get_stat_global();
    level get_level();
    role get_roles(int);
    weapon get_weapon(int);

    void equip(int, weapon);
    void unequip(int);
    void modify_stats_equip_or_level();
    void modify_stats_buff_debuff(ability, int);
    void set_experience_entity(int);
    void set_experience_class(int);
    void change_class(int, int);
    void show_stats();
    ~character();
};

table_element::table_element(std::string array_elements[], int sizes)
{
    element_list = new std::string[sizes];
    _size = sizes;
    array_weakness = new int* [_size];
    for (int i = 0; i < _size; i++)
        element_list[i] = array_elements[i];
    for (int i = 0; i < sizes; i++)
        array_weakness[i] = new int[_size];
    for (int i = 0; i < _size; i++)
        for (int j = 0; j < _size; j++)
            array_weakness[i][j] = 1;
}
void table_element::set_debilities(std::string strong, std::string weak, std::string str)
{
    bool x = false, y = false, z = false;
    int s, t, u;
    for (int i = 0; i < _size; i++) {
        if (element_list[i] == strong) {
            s = i;
            x = true;
        }
        if (element_list[i] == weak) {

            t = i;
            y = true;
        }
        if (element_list[i] == str) {

            u = i;
            z = true;
        }
    }
    if (x == true && y == true && z == true) {
        if (t != u) {
            array_weakness[s][t] = 2;
            array_weakness[t][s] = 0;
            array_weakness[u][s] = 2;
        }
        else
        {
            array_weakness[s][t] = 3;
            array_weakness[t][s] = 3;
            array_weakness[u][s] = 3;
        }
    }

}
std::string table_element::get_element(int x)
{
    return element_list[x];
}
void table_element::show_table()
{
    for (int i = 0; i < _size; i++)
        std::cout << element_list[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++)
            std::cout << array_weakness[i][j] << " ";
        std::cout << "\n";
    }
}
table_element::~table_element()
{
    delete element_list;
    delete *array_weakness;
    delete array_weakness;
}

stats::stats()
{
    _size = 0;
    stadistic_name = nullptr;
    value = nullptr;
}

stats::stats(std::string _list[], int _list_value[], int _siz)
{
    _size = _siz;
    stadistic_name = new std::string[_size];
    value = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        stadistic_name[i] = _list[i];
        value[i] = _list_value[i];
    }
}

stats::stats(stats& o)
{
    _size = o.get_size();
    stadistic_name = new std::string[_size];
    value = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        stadistic_name[i] = o.get_stat_name(i);
        value[i] = o.get_stat_value(i);
    }
}

void stats::set_v_value(int pos, int new_value)
{
    value[pos] = new_value;
}

std::string stats::get_stat_name(int x)
{
    return stadistic_name[x];
}
int stats::get_stat_value(int x)
{
    return value[x];
}
int stats::get_size()
{
    return _size;
}
void stats::set_name(std::string _list[])
{
    for (int i = 0; i < _size; i++)
        stadistic_name[i] = _list[i];
}
void stats::set_value(int _list[])
{
    for (int i = 0; i < _size; i++)
        value[i] = _list[i];
}
void stats::sum_value(int pos, int sum)
{
    value[pos] += sum;
}
void stats::show_data()
{
    for (int i = 0; i < _size; i++)
        std::cout << "Stat  name: " << stadistic_name[i] << " value: " << value[i] << "\n";
}
stats::~stats()
{
    delete stadistic_name;
    delete value;
}

level::level()
{
    act_level = 1;
    experience = 0;
    necesary_exp = 10;
    total_exp = 0;
    max_level = 100;
    constant = 2.7818;
}
level::level(double x, double y, double z, double j, double w, double i)
{
    act_level = x;
    experience = y;
    necesary_exp = z;
    total_exp = j;
    max_level = w;
    constant = i;
}
level::level(level& o)
{
    act_level = o.get_level();
    experience = o.get_experience();
    necesary_exp = o.get_necesary_experience();
    total_exp = o.get_total_exp();
    max_level = o.get_max_level();
    constant = o.get_constant();
}
double level::get_total_exp()
{
    return total_exp;
}
double level::get_level()
{
    return act_level;
}
double level::get_experience()
{
    return experience;
}
double level::get_necesary_experience()
{
    return necesary_exp;
}
double level::get_max_level()
{
    return max_level;
}
double level::get_constant()
{
    return constant;
}
void level::set_necesary_experience()
{
    necesary_exp = pow(get_constant(), act_level / 10) * 100;
}
void level::add_exp(double x)
{
    std::cout << "you got " << x << " experience points\n";
    experience += x;
    total_exp += x;
    validation_system();
}
void level::level_up(int f)
{
    experience = f;
    if (act_level < max_level) {
        act_level++;
        std::cout << "you got level " << act_level << "\n";
    }
    set_necesary_experience();
    validation_system();
}
void level::validation_system()
{
    if (experience >= necesary_exp) {
        int f = (int)experience - (int)necesary_exp;
        level_up(f);
    }
}

ability::ability()
{
    name = "empty";
    state = "000000";
    power = 0;
    element = "empty";
    state_name = "empty";
    consume = 0;
}

ability::ability(ability& o)
{
    name = o.get_name();
    state = o.get_state();
    power = o.get_power();
    element = o.get_element();
    state_name = o.get_state_name();
    consume = o.get_consume();
}

ability::ability(std::string _name, std::string _state, int _power, table_element &_table, int pos, std::string name_state, int cons)
{
    name = _name;
    state = _state;
    power = _power;
    element = _table.get_element(pos);
    state_name = name_state;
    consume = cons;
}
std::string ability::get_name()
{
    return name;
}
std::string ability::get_element()
{
    return element;
}
int ability::get_power()
{
    return power;
}
int ability::get_consume()
{
    return consume;
}
std::string ability::get_state()
{
    return state;
}
std::string ability::get_state_name()
{
    return state_name;
}
void ability::show_data()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "State: " << state_name << " code effect: " << state << "\n";
    std::cout << "Power: " << power << "\n";
    std::cout << "Element: " << element << "\n";
    std::cout << "consume: " << consume << "\n";
}

item::item()
{
    name = "empty";
    description = "empty";
}
item::item(std::string _name, std::string _description)
{
    name = _name;
    description = _description;
}
std::string item::get_name()
{
    return name;
}
std::string item::get_description()
{
    return description;
}
void item::show_data()
{
    std::cout << "\n\nname: " << name << "\n";
    std::cout << "description: " << description << "\n";
}

weapon::weapon() : item()
{
    element = "empty";
    weapon_type = "empty";
    buff_debuff = nullptr;
    _size = 0;
}
weapon::weapon(std::string _name, std::string _description, std::string _weapon_type, table_element _table, int pos, int _buff_debuff[], int siz) : item(_name, _description)
{
    weapon_type = _weapon_type;
    element = _table.get_element(pos);
    buff_debuff = new int[siz];
    _size = siz;
    for (int i = 0; i < _size; i++)
        buff_debuff[i] = _buff_debuff[i];
}
weapon::weapon(weapon& o)
{
    name = o.get_name();
    description = o.get_description();
    weapon_type = o.get_weapon_type();
    _size = o.get_size();
    buff_debuff = new int[_size];
    for (int i = 0; i < _size; i++)
        buff_debuff[i] = o.get_buff_debuff(i);
}
std::string weapon::get_name()
{
    return  item::get_name();
}
std::string weapon::get_decription()
{
    return item::get_description();
}
std::string weapon::get_element()
{
    return element;
}
std::string weapon::get_weapon_type()
{
    return weapon_type;
}
int weapon::get_buff_debuff(int pos)
{
    return buff_debuff[pos];
}
int weapon::get_size()
{
    return _size;
}
void weapon::show_data()
{
    item::show_data();
    std::cout << "weapon type : " << weapon_type << "\n";
    std::cout << "element : " << element << "\n";
    for (int i = 0; i < _size; i++)
        std::cout << " " << buff_debuff[i];
    std::cout << "\n\n";
}

weapon::~weapon()
{
    delete buff_debuff;
}

role::role()
{
    _size = 0;
    name = "empty";
    code_stats = "empty";
    code_weapons = "empty";
    hab = nullptr;
    level_to_use = nullptr;
    level_of_role = level();
}

role::role(std::string _name, std::string _code_stats, std::string _code_weapon, ability abilities[], level lvl, int to_use[], int _siz)
{
    _size = _siz;
    name = _name;
    code_stats = _code_stats;
    code_weapons = _code_weapon;
    hab = new ability[_size];
    level_to_use = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        hab[i] = abilities[i];
        level_to_use[i] = to_use[i];
    }
    level_of_role = lvl;
}
role::role(role& o)
{
    name = o.get_name();
    _size = o.get_size();
    code_stats = o.get_code_stats();
    code_weapons = o.get_code_weapons();
    hab = new ability[_size];
    level_to_use = new int[_size];
    for (int i = 0; i < _size; i++)
    {
        hab[i] = ability(o.get_ability(i));
        level_to_use[i] = o.get_level_to_use(i);
    }
    level_of_role = o.get_lvl();
}
std::string role::get_name()
{
    return name;
}
std::string role::get_code_stats()
{
    return code_stats;
}
std::string role::get_code_weapons()
{
    return code_weapons;
}
int role::get_level()
{
    return (int)level_of_role.get_level();
}
void role::add_level(int exp)
{
    level_of_role.add_exp(exp);
}
level role::get_lvl()
{
    return level_of_role;
}
ability& role::get_ability(int pos)
{
    return hab[pos];
}
int role::get_level_to_use(int pos)
{
    return level_to_use[pos];
}
int role::get_size()
{
    return _size;
}
void role::display_habs()
{
    bool r = false;
    std::cout << "disponible abilities: \n\n";
    for (int i = 0; i < _size; i++)
        if (get_level() >= level_to_use[i]) {
            hab[i].show_data();
            std::cout << "level to use: " << level_to_use[i] << "\n";
            r = true;
        }
    if (!r)
        std::cout << "no abilities disponible with your level\n\n";
}
void role::show_data()
{
    std::cout << "\n\nclass name: " << name << "\n";
    std::cout << "code for stats modification: " << code_stats << "\n";
    std::cout << "code for weapon efectivity: " << code_weapons << "\n\n";
    for (int i = 0; i < _size; i++)
    {
        hab[i].show_data();
        std::cout << "level to use: " << level_to_use[i] << "\n\n";
    }
    std::cout << "level for this role: " << level_of_role.get_level() << "\n\n";
}
role:: ~role()
{
    delete hab;
    delete level_to_use;

}
character::character()
{
    name = "empty";
    _stats = stats();
    act_stats = stats();
    size_of_roles = 0;
    _level = level();
    roles = nullptr;
    point_role = nullptr;
    equipment = nullptr;
    constant = nullptr;
}
character::character(std::string _name, stats _sts, int num_of_roles, level _levl, role _list[], int equip, int con[])
{
    name = _name;
    _stats = stats(_sts);
    act_stats = stats(_sts);
    size_of_roles = num_of_roles;
    _level = level(_levl);
    roles = new role[size_of_roles];
    point_role = new int[2];
    num_of_equip = equip;
    equipment = new weapon[num_of_equip];
    for (int i = 0; i < size_of_roles; i++)
    {
        roles[i] = _list[i];
    }
    /*constant = new int[_stats.get_size()];
    for (int i = 0; i < _stats.get_size(); i++) {
        constant[i] = con[i];
    }*/

    int tam = _stats.get_size();
    constant = new int[tam];
    for (int i = 0; i < tam; i++)
        constant[i] = con[i];

    _stats.set_value(con);
    act_stats.set_value(con);
    point_role[0] = 0;
    point_role[1] = 1;
    modify_stats_equip_or_level();
}
ability character::get_ability(int pos_role, int pos)
{
    return roles[pos_role].get_ability(pos);
}
std::string character::get_name()
{
    return name;
}
int character::get_num_of_roles()
{
    return size_of_roles;
}
int character::get_num_of_equip()
{
    return num_of_equip;
}
level character::get_level()
{
    return _level;
}
stats character::get_stat_global()
{
    return _stats;
}
role character::get_roles(int pos)
{
    return roles[pos];
}
weapon character::get_weapon(int pos)
{
    return equipment[pos];
}
void character::equip(int pos, weapon new_weapon)
{
    if (pos < num_of_equip && pos >= 0)
        equipment[pos] = weapon(new_weapon);
    character::modify_stats_equip_or_level();
}
void character::unequip(int pos)
{
    if (pos < num_of_equip && pos >= 0)
        equipment[pos] = weapon();
    character::modify_stats_equip_or_level();
}
void character::modify_stats_buff_debuff(ability abi, int power)
{
    std::string eval = abi.get_state();
    int i = 0;
    int counter = 0;
    while (eval[i] != ' ')
    {
        if (eval[i] <= '9' && eval[i] >= '0') {
            counter++;
            act_stats.sum_value(counter, (_stats.get_stat_value(counter) + (_stats.get_stat_value(counter) * ((eval[i] - '0') / 10))));
            if (act_stats.get_stat_name(counter) == "life points" && (act_stats.get_stat_value(counter) > _stats.get_stat_value(counter)))
                act_stats.set_v_value(counter, _stats.get_stat_value(counter));
            if (act_stats.get_stat_name(counter) == "magic pointa" && (act_stats.get_stat_value(counter) > _stats.get_stat_value(counter)))
                act_stats.set_v_value(counter, _stats.get_stat_value(counter));
            i++;
        }
    }
    i++;
    counter = 0;
    while (eval[i] != ' ')
    {
        if (eval[i] <= '9' && eval[i] >= '0') {
            counter++;
            act_stats.sum_value(counter, (_stats.get_stat_value(counter) - (_stats.get_stat_value(counter) * ((eval[i] - '0') / 10))));
            if (act_stats.get_stat_name(counter) == "life points" && (act_stats.get_stat_value(counter) < 0))
                act_stats.set_v_value(counter, _stats.get_stat_value(counter));
            if (act_stats.get_stat_name(counter) == "magic pointa" && (act_stats.get_stat_value(counter) < 0))
                act_stats.set_v_value(counter, 0);
            i++;
        }
    }
}
#include <sstream>
void character::modify_stats_equip_or_level()
{
    std::string str = roles[point_role[0]].get_code_stats();
    for (int i = 0; i < _stats.get_size(); i++) {
        int x;
        std::stringstream converter(str[i]);
        converter >> x;
        _stats.set_v_value(i, constant[i] + (x * (int)_level.get_level()));
    }
    for (int i = 0; i < num_of_equip; i++)
        if (equipment[i].get_name() != "empty")
            for (int j = 0; j < _stats.get_size(); j++)
                _stats.sum_value(j, equipment[i].get_buff_debuff(j));
    for (int i = 0; i < _stats.get_size(); i++)
        act_stats.set_v_value(i, _stats.get_stat_value(i));
}
void character::set_experience_class(int experience)
{
    roles[point_role[0]].add_level(experience);
    character::modify_stats_equip_or_level();
}
void character::set_experience_entity(int experience)
{
    _level.add_exp(experience);
    character::modify_stats_equip_or_level();
}
void character::change_class(int pr_role, int sec_role)
{
    point_role[0] = pr_role;
    point_role[1] = sec_role;
    character::modify_stats_equip_or_level();
}
void character::show_stats()
{
    std::cout << "name: " << name << "\n";
    std::cout << "principal role: " << roles[point_role[0]].get_name() << " level of role: " << roles[point_role[0]].get_level() << "\n";
    std::cout << "second role: " << roles[point_role[1]].get_name() << " level of role: " << roles[point_role[1]].get_level() << "\n";
    std::cout << "level: " << _level.get_level() << "\n\n";
    _stats.show_data();
    roles[point_role[0]].show_data();
    roles[point_role[1]].show_data();

}
character::~character()
{
    delete roles;
    delete point_role;
    delete equipment;
    delete constant;
}
int main()
{

    std::string elements[7] = { "fire","water","thunder","wind","light","dark","neutral" };
    table_element table(elements, 7);
    table.set_debilities("fire", "wind", "water");
    table.set_debilities("wind", "thunder", "fire");
    table.set_debilities("water", "fire", "thunder");
    table.set_debilities("thunder", "water", "wind");
    table.set_debilities("light", "dark", "dark");
    table.set_debilities("dark", "light", "light");
    table.show_table(); // fire water thunder wind light dark

    std::cout << "Aquí 1\n";
    std::string _global_stats[7] = { "life points","magic points","atack","defense","magic atack","magic defense","speed" };
    int _globalvalue[7] = { 0,0,0,0,0,0,0 };
    int _seth_stats[7] = { 40,30,20,20,15,15,20 };
    stats global(_global_stats, _globalvalue, 7);

    std::cout << "Aquí 2\n";
    global.show_data();
    stats seth_stats(_global_stats, _globalvalue, 7);
    seth_stats.set_value(_seth_stats);
    seth_stats.show_data();

    std::cout << "Aquí 3\n";
    std::string type_of_weapon[6] = { "sword","spear","axe","bow","knife","crosier" };

    std::cout << "Aquí 4\n";
    level global_level;

    std::cout << "Aquí 5\n";
    global_level.add_exp(300);

    std::cout << "Aquí 6\n";
    ability sword_atack("sword atack", "0000000 0000000 00", 40, table, 6, "nothing", 0);
    ability poison_level_1("poison level 1", "0000000 1000000 03", 0, table, 6, "poison", 10);
    ability explotion("explotion", "0000000 0000000 00", 150, table, 6, "nothing", 20);
    ability down_atack("down atack", "0000000 0010000 03", 0, table, 6, "nothing", 30);

    std::cout << "Aquí 7\n";
    ability slash("slash", "0000000 0000000 00", 70, table, 6, "nothing", 0);
    ability build_defense("build defense", "0000000 0010000 03", 0, table, 6, "defense up", 10);
    ability sword_destruction("sword destruction", "0000000 0001000 03", 80, table, 6, "nothing", 50);
    ability build_atack("build atack", "0000000 0010000 03", 0, table, 6, "atack_up", 60);

    std::cout << "Aquí 8\n";
    ability group_warrior[4];
    group_warrior[0] = slash;
    group_warrior[1] = build_defense;
    group_warrior[2] = sword_destruction;
    group_warrior[3] = build_atack;

    std::cout << "Aquí 9\n";
    ability cure_level("cure level 1", "1000000 000000 01", 0, table, 4, "cure hp", 15);
    ability light_ball("light ball", "0000000 0000000 00", 40, table, 4, "nothing", 20);
    ability defense_magic_up("build magic defense", "0001000 0000000 03", 0, table, 6, "magic defense up", 25);
    ability cure_level_2("cure level 2", "2000000 0000000 01", 0, table, 4, "cure hp", 30);

    std::cout << "Aquí 10\n";
    ability group_white_mage[4];
    group_white_mage[0] = cure_level;
    group_white_mage[1] = light_ball;
    group_white_mage[2] = defense_magic_up;
    group_white_mage[3] = cure_level_2;

    std::cout << "Aquí 11\n";
    ability group_freelancer[4];
    group_freelancer[0] = sword_atack;
    group_freelancer[1] = poison_level_1;
    group_freelancer[2] = explotion;
    group_freelancer[3] = down_atack;

    std::cout << "Aquí 12\n";
    item colgante("colgante ", "colgante bonito, sin utilidad");
    colgante.show_data();

    std::cout << "Aquí 13\n";
    int stats_sword[7] = { 0,0,10,-5,0,0,0 };
    weapon sword("espada", "una espada comun", "sword", table, 6, stats_sword, 7);
    //sword.show_data();
    weapon* wea;
    wea = new weapon[6];
    for (int i = 0; i < 6; i++)
        wea[i].show_data();
    int level_to_use_freelancer[4] = { 10,20,30,40 };
    int level_to_use_warrior[4] = { 10,20,30,40 };
    int level_to_use_white_mage[4] = { 10,20,35,45 };

    std::cout << "Aquí 14\n";
    role freelancer("freelancer", "5555555", "abbbab", group_freelancer, global_level, level_to_use_freelancer, 4);
    freelancer.show_data();
    freelancer.display_habs();
    freelancer.add_level(3000);
    freelancer.display_habs();

    std::cout << "Aquí 15\n";
    role warrior("warrior", "6476345", "sasbdd", group_warrior, global_level, level_to_use_warrior, 4);
    role white_mage("white mage", "4734874", "cddcas", group_white_mage, global_level, level_to_use_white_mage, 4);

    std::cout << "Aquí 16\n";
    role* roles;
    roles = new role[3];
    roles[0] = freelancer;
    roles[1] = warrior;
    roles[2] = white_mage;

    std::cout << "Aquí 17\n";
    for (int i = 0; i < 3; i++)
    {
        roles[i].show_data();
    }
    character seth("seth", global, 3, global_level, roles, 6, _seth_stats);

    std::cout << "Aquí 18\n";
    seth.show_stats();
    std::cout << "\n\n";
    seth.change_class(2, 0);
    seth.show_stats();
    seth.set_experience_entity(3000);
    seth.show_stats();
    seth.change_class(1, 0);
    seth.show_stats();
    seth.equip(0, sword);
    seth.show_stats();
    seth.set_experience_class(2000);
    seth.show_stats();

    std::cout << "Aquí 19\n";
    character gloria("gloria", global, 3, global_level, roles, 6, _seth_stats);

    std::cout << "Aquí 20\n";
    character* group;
    group = new character[2];
    group[0] = seth;
    group[1] = gloria;

    std::cout << "Aquí 21\n";
    group[0].show_stats();
    group[1].show_stats();
}
