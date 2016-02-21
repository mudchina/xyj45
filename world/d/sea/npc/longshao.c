// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Changed by sjmao  09-11-97
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("龙少爷", ({"long shaoye","shaoye","taizi","long","prince"}));

set("long","龙王的大少爷．\n");
       set("gender", "男性");
   set("int", 25);
       set("age", 26);
       set("title", "龙宫太子");
       set("attitude", "peaceful");
       set("combat_exp", 450000);
       set("rank_info/respect", "殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set_skill("literate", 50);
       set_skill("unarmed", 120);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("fork", 80);
       set_skill("spells", 80);
        set_skill("seashentong", 80);
        set_skill("dragonfight", 120);
        set_skill("dragonforce", 80);
        set_skill("fengbo-cha", 80);
        set_skill("dragonstep", 80);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "离宫": (: expell_me :),
                "leave": (: expell_me :), ]) );


      create_family("东海龙宫", 2, "水族");
   setup();

        carry_object("/d/ourhome/obj/choupao")->wear();
}

void attempt_apprentice(object ob)
{
        command("look " + ob->query("id"));
        if ( (string)ob->query("gender")=="男性"){
           command("kick " + ob->query("id"));
           command("say 我没功夫教你！\n");
           return;
        }

        command("sister " + ob->query("id"));
        command("recruit " + ob->query("id") );
        command("say 嘿嘿，只要" + RANK_D->query_respect(ob) +
"把师父我弄高兴了，保你荣华富贵享受不尽。\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="东海龙宫")
    {
        if ( (string)me->query("gender")=="男性"){
           command("slap " + me->query("id"));
           return("嚷什么嚷！要滚蛋去问我们家老头子！\n");
        }

      message_vision("龙少爷眼泪汪汪地望着$N，伸出手想拉住$N，但又缩了回来。\n", me);
      return ("你去问我父王吧。。。我怎么知道？\n");
    }
  return ("不知道！\n");
}
