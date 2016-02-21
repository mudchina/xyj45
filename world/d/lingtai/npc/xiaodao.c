// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

void create()
{
        set_name("扫地小童", ({"xiao tong"}));
        set("gender", "男性" );
        set("age", 13);
        set("long", "一个小童，正在轻轻的扫地");
        set("combat_exp", 1000);
   set_skill("stick", 20);
   set_skill("dodge", 40);
        set("attitude", "friendly");
        set("chat_chance_combat", 50 );
        setup();
   carry_object("/d/lingtai/obj/shaoba")->wield();
}
