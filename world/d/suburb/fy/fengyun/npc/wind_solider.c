
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("·ç±ø", ({ "fengyun garrison", "garrison" }) );
        set("long",
"ÕâÊÇ¸öÕıÔÚÖ´ĞĞÊØ³ÇÈÎÎñµÄ·ç±ø£¬ËäÈ»ºÍĞí¶àÎäÁÖÈËÎï±ÈÆğÀ´£¬·ç±øÃÇµÄÎä¹¦\n"
"ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓĞ×éÖ¯¡¢ÓĞ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕĞÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕĞÈÇËûÃÇ¡£ [37m\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000+random(1000000));
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "·ç±øºÈµÀ£º»¹²»¿ì·ÅÏÂÎäÆ÷ÊøÊÖ¾Í¸¿£¿\n",
                "·ç±øºÈµÀ£º´óµ¨µóÃñ¾¹¸Ò¾Ü²¶£¿·´ÁË£¡·´ÁË£¡\n"
        }) );

        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 500000 ) {
                        say("·ç±øºÇºÇµÄĞ¦µÀ£ººÃËµ£¬ºÃËµ...\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                    say("·ç±øËµµÀ£ºÕâµãÇ®»¹²»¹»´óÒ¯ºÈ¾ÆµÄÄØ£¡\n");
                        return 0;
                }
        return 0;
} 
