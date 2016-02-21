// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gargoyle.c

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黑无常", ({ "hei wuchang","wuchang", "gargoyle" }));
        set("long","一个黑衣漆黑面皮的使者，黝黑的脸上看不出任何喜怒哀乐。\n");
        set("attitude", "peaceful");
   set("per", 10);
   set("str", 25);
   set("int", 25);
        set("age", 30);
   set("title", "引魄司主");
        set("combat_exp", 150000);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
   set("class", "youling");
   set("force", 1500);
   set("max_force", 800);
   set("force_factor", 50);
   set("max_mana", 600);
   set("mana", 1000);
   set("mana_factor", 40);
   set_skill("ghost-steps", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
   set_skill("parry", 70);
   set_skill("spells", 70);
   set_skill("gouhunshu", 60);
   set_skill("jinghun-zhang", 70);
   set_skill("force", 70);
   set_skill("tonsillit", 60);
/*
   set_skill("stick", 100);
   set_skill("kusang-bang", 100);
   map_skill("stick", "kusang-bang");
   map_skill("parry", "kusang-bang");
*/
   map_skill("spells", "gouhunshu");
   map_skill("dodge", "ghost-steps");
   map_skill("force", "tonsillit");
   map_skill("unarmed", "jinghun-zhang");
create_family("阎罗地府", 3, "你好");

        setup();
   carry_object("/d/obj/cloth/hei")->wear();
}


void attempt_apprentice()
{
   object me;
   me = this_player();
        command("grin");

        command("say 很好，" + RANK_D->query_respect(me) +
"多加努力，他日必定有成。\n");
       command("recruit " + me->query("id") );
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
//     ob->set("title", "地府引魄司阴兵");
}

