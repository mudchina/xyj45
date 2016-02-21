// human.c
// From ES2
// Modified by Xiang@XKX

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"后心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) );
}

void setup_human(object ob)
{
	mapping my;
	int qi_age;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

	if( userp(ob) || undefinedp(my["max_gin"]) ) {

		if( my["age"] <= 14 ) my["max_gin"] = 100;
		else if( my["age"] <= 30 ) my["max_gin"] = 100 + (my["age"] - 14) * my["int"];
		else if( my["age"] >= 60 ) my["max_gin"] -= (my["age"] - 60) * 5;
		else my["max_gin"] = my["int"] * 16 + 100;

		//To do about Taoism

		if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		
		if( my["age"] <= 14 ) my["max_kee"] = 100;
		else if( my["age"] <= 30 ) my["max_kee"] = 100 + (my["age"] - 14) * my["con"];
		else if( my["age"] >= 60 ) my["max_kee"] -= (my["age"] - 60) * 5;
		else my["max_kee"] = my["con"] * 16 + 100;
		
		// 道家练气：３０岁前补气，３０岁后长气
		if((qi_age=(int)ob->query_skill("taoism", 1)) > 39);
		{
			qi_age = qi_age/2;
			if (my["age"] <= 30) qi_age -= my["age"];
			else qi_age -= 30;
			
			if (qi_age > 0) my["max_kee"] += qi_age *((int)ob->query_skill("taiji-shengong", 1)/10); 
		}
		
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
