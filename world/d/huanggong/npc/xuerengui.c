// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

#include <greeting.h>

void create()
{
        set_name("薛仁贵", ({ "xue rengui", "xue", "rengui" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","薛仁贵是长安城九门提督，负责皇宫内外安全。\n");
        set("combat_exp", 350000);
   set("title", "九门提督");
   set("nickname", "勇冠三军");
        set("attitude", "friendly");
   set("per", 25);
        set("str", 35);
        set("max_kee", 850);
        set("max_gin", 600);
   set("max_mana", 500);
   set("mana", 500);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", 35);
        set_skill("spear", 80);
        set_skill("unarmed", 80);
   set_skill("changquan", 70);
        set_skill("parry", 80);
        set_skill("dodge", 80);
   set_skill("bawang-qiang", 70);
   set_skill("yanxing-steps", 70);
   map_skill("spear", "bawang-qiang");
   map_skill("parry", "bawang-qiang");
   map_skill("dodge", "yanxing-steps");
   map_skill("unarmed", "changquan");
        setup();

        carry_object("/d/obj/weapon/spear/tiespear")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}

void init ()
{
   greeting2(this_player());
}

int accept_fight(object me)
{
        command("say 我为殿前将军，岂能与你村野匹夫较艺！");
        return 0;
}


