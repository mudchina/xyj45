// teacher.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"张", "王", "李", "赵", "孙", "徐", "郑", "周", "吴",
"蒋", "沈", "杨", "苗", "尹", "金", "魏", "陶", "俞", "柳", "朱"});
	string *orderr = ({"包包", "宝宝", "乖乖", "小小", "珀珀",
"鸡鸡", "鸦鸦", "狗狗"});
        set_name( order[random(20)] + orderr[random(8)], ({ "kid", "small kid" }) );
	set("title", "无知小童");
	set("gender", "男性" );
	set("age", random(5)+4);
	set("int", 26);
	set("long",
		"他很小, 很好欺服.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

	set("attitude", "peaceful");
	set("combat_exp", random(5));
	setup();
}
