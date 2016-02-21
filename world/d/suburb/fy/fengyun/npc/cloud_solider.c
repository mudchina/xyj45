
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ÔÆ×ä", ({ "fengyun garrison", "garrison" }) );
        set("long",
"ÕâÊÇ¸öÕıÔÚÖ´ĞĞÊØ³ÇÈÎÎñµÄÔÆ×ä£¬ËäÈ»ºÍĞí¶àÎäÁÖÈËÎï±ÈÆğÀ´£¬ÔÆ×äÃÇµÄÎä¹¦\n"
"ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓĞ×éÖ¯¡¢ÓĞ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕĞÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕĞÈÇËûÃÇ¡£ [37m\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000+random(1000000));
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "ÔÆ×äºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "ÔÆ×äºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n"
        }) );
        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	switch( random(10)){
				case 0:
say("ÔÆ×äÉÏÉÏÏÂÏÂµØ´òÁ¿ÄãÒ»·¬£¬ÓÖºÍÇ½ÉÏÌûµÄ¹Ù¸®Í¨µı¶ÔÁË¶Ô£¬µÍÉùàÖ¹¾µÀ£ººÃÏó¾ÍÊÇÁË£®\n");
					break;
				case 1:
say("ÔÆ×ä¿´ÁËÄãÒ»ÑÛ£¬µÍÉùàÖ¹¾µÀ£º°¦£¬ÓÖÊÇÒ»¸ö½­ºşÈËÎï£®\n");
					break;
				case 2:
say("ÔÆ×äÏòÄãºÈµÀ£ºÕ¾×¡£¡°ÑÁ³¸øÎÒÌ§ÆğÀ´£¡\n");
					break;
				}
}

