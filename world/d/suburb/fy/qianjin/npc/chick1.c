#include <ansi.h>
inherit NPC;

void create()
{
	set_name("昭红", ({ "girl" }) );
	set("title", HIM "风云名妓" NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
昭红是风云城的名妓，如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您一定会在这儿玩的开心的！");
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("$N轻飘飘地向$n走过来，温柔的抚弄$n的黑发．．．\n",this_object(),me);
	me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			destruct(inv[i]);
		}
	maxgin = (int)me->query("max_gin");
        maxkee = (int)me->query("max_kee");
        maxsen = (int)me->query("max_sen");
	me->set("eff_gin", maxgin);
	me->set("gin", maxgin);
        me->set("eff_kee", maxkee);
        me->set("kee", maxkee);
        me->set("eff_sen", maxsen);
        me->set("sen", maxsen);
	wo = new(__DIR__"obj/wo");
	wo->move(me);
	return 1;
}
