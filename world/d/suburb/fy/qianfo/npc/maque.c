// 
// 

inherit NPC;
void create()
{
	set_name("红嘴小麻雀", ({ "maque", "que" }) );
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这是一只红嘴小麻雀\n");
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "左脚", "右脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 1);
        set("chat_msg", ({
"小麻雀＂叽～～叽叽＂地鸣叫了几声\n",
        }) );
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
}
