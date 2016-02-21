// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
       set_name("龙婆", ({"long po"}));

set("long","龙王的老婆，东海的太后．\n");
       set("gender", "女性");
       set("age", 26);
   set("per", 30);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 126000);
   set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 60);
   set_skill("dragonstep", 40);
   map_skill("dodge", "dragonstep");
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 3);
        setup();
        add_money("gold", 1);
        carry_object("/d/obj/cloth/jinpao")->wear();

}

