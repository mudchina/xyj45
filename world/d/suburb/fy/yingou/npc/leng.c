// garrison.c

#include <ansi.h>

inherit NPC;
#define LOWER_LIMIT 20000
#define DUMP_PLACE  "/d/suburb/fy/laowu/road0.c"
void create()
{
        set_name("冷若霜", ({ "leng", "lengruoshuang" }) );
        set("long",
"这位美人人如其名，给人一种高不可攀，冷若冰霜的感觉．
但她是太有媚力，太令人着迷，你真想和她认识认识（ｋｎｏｗ）\n");
        set("attitude", "heroism");
	set("title", HIW "冰山" NOR);
        set("str", 27);
        set("cor", 26);
	set("gender", "女性");
        set("cps", 25);
	set("per", 30);
	set("age",19);
        set("combat_exp", 100000);

        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/goldcloth")->wear();
}

void init()
{
	add_action("do_know","know");
}

int do_know()
{
	object me;
	object dump;
	me = this_player();
	if((int) me->query("combat_exp") >= LOWER_LIMIT)
	{
	tell_object(me,"冷若霜叹了口气，＂看来今天只好拉你作替死鬼了．＂\n");
	tell_object(me,"冷若霜趁你不备，悄悄拂了一下你的睡穴．\n");
	me->unconcious();
	me->set("marks/冷若霜", 1);
	me->save();
	dump = find_object(DUMP_PLACE);
	if (!dump) dump = load_object(DUMP_PLACE);
	if(dump) me->move(dump);
	}	
	else
	{
	if(me->query("gender") == "男性")
message_vision("$N反反正正打了$n几记大耳光，斥骂道：
＂滚开！你这种臭男人我见得多了！看见你都感到恶心！滚！＂\n",this_object(),me);	
	else
message_vision("$N向$n挤出一丝勉强的笑容，道：
＂好妹妹！你帮不到我．＂\n",this_object(),me);
	}
	return 1;
}

