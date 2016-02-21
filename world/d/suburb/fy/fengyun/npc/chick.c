#include <ansi.h>
inherit NPC;

void create()
{
	set_name("土娼", ({ "girl" }) );
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
土娼是．．．如果你感兴趣的话，请（ｅｎｊｏｙ）．
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
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
"，您一定会．．．．！");
        return 1;
}

void init()
{
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
object me;
object *inv;
int maxgin,maxkee, maxsen;
int i;
	me = this_player();
message_vision("$N用手挖了挖鼻孔，然后向$n走过来．．．\n",this_object(),me);
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			destruct(inv[i]);
		}
message_vision("$N感觉不错．．．．\n", me);
	me->apply_condition("hualiu_poison",10+random(20));
	return 1;

}
