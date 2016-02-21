
inherit NPC;
void use_poison();

void create()
{
        set_name("鳄鱼", ({ "cor" }) );
        set("race", "野兽");
        set("age", 4);
	set("yes_carry", 1);
        set("long", "一条水桶般粗的鳄鱼。\n");

        set("limbs", ({ "头部", "身体", "尾巴", "眼睛" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 50);
	set_skill("move",300);
        set("combat_exp", 9999);
	set("bellicosity", 300 );
        set("chat_chance", 20);
	add_temp("apply/damage",30+random(20));
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,
"你觉得脸上剧痛，伸手一摸发现两个毒牙印痕。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

