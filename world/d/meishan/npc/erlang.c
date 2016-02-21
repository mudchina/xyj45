// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("二郎真君", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "他是赤城昭惠英灵圣，显化无边号二郎。
力伏八怪声名远，义结梅山七圣行。\n");
   set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "男性");
        set("title", "昭惠灵显王");
        set("str", 40);
        set("int", 40);
        set("per", 30);
   set("con", 30);
        set("max_kee",2000);
        set("max_sen", 2000);
        set("combat_exp", 1500000);
        set("force", 4000);
        set("max_force", 2000);
        set("mana", 4000);
        set("max_mana", 2000);
        set("force_factor", 150);
        set("mana_factor", 120);

        set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 200);
   set_skill("force", 180);
   set_skill("spells", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("spear", 180);
   set_skill("moyun-shou", 200);
   set_skill("moshenbu", 200);
        set_skill("bawang-qiang", 200);
   map_skill("unarmed", "moyun-shou");
   map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();

}

void die()
{

        if( environment() ) {
        message("sound", "\n\n二郎神怒道：你莫要猖狂，待我上天告御状去！\n\n", environment());
        message("sound", "\n二郎神搭上白云，径往南天门飞去。。。\n\n", environment());
        }

        destruct(this_object());
}

