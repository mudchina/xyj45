// Room: /d/wiz/courthouse.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
	set("short", "·¨Ôº");
	set("long", @LONG
ÕâÀïÊÇ[31m·çÔÆ[37mµÄÎ×Ê¦ÉóÎÊ[33m»úÆ÷ÈË[37mµÄ·¨Ôº£¬ÄãÒ»¶¨ÊÇ±»ÈË¼ì¾Ù»òÊÇ
ÐÐÎªÌ«Ïñ»úÆ÷ÈË£¬²Å»áÀ´µ½ÕâÀï£¬Èç¹ûÄã´ð²»³öÉóÅÐ¹ÙµÄÈý¸öÎÊÌâ£¬»á
±»×öÉÏ¼ÇºÅ£¬³¬¹ýÈý´ÎµÄÈË½«»á±»´¦ÒÔ¼«ÐÌ£¬ºÃºÃ»Ø´ð°É¡£
LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}
void init()
{	object ob;
	if(interactive(ob = this_player()))
		test_me(ob);
}	
void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
}
