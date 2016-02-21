// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhangchan.c 掌禅僧
// By Dream Dec. 20, 1996

inherit NPC;

string ask_staff(object who);
string ask_spear(object who);

void create()
{
   set_name("掌禅僧", ({ "zhangchan seng", "seng" }));
   set("gender", "男性");
   set("age", 35);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 250);
   set("max_gin", 250);
   set("max_sen", 250);
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 20);
   set("max_mana", 100);
   set("mana", 100);
   set("mana_factor", 20);
   set("combat_exp", 10000);
   set_skill("literate", 30);
   set_skill("spells", 10);
   set_skill("unarmed", 30);
   set_skill("jienan-zhi", 30);
   set_skill("dodge", 20);
   set_skill("parry", 30);
   set_skill("force", 30);
   set_skill("staff", 30);
   map_skill("unarmed", "jienan-zhi");

   set("inquiry", ([
     "兵器": "你想要什么兵器？",
     "铁杖": (: ask_staff :),
     "铁枪": (: ask_spear :)
   ]) );

   set("apply/staffno", 10);
   set("apply/spearno", 10);
        create_family("南海普陀山", 4, "弟子");
   
   setup();
   carry_object("/obj/money/gold");
   carry_object("/d/nanhai/obj/sengpao")->wear();
}


string ask_staff(object me)
{
   object ob, who = this_player();
   int number;


   if (who->query("family/family_name") != "南海普陀山") 
     return RANK_D->query_respect(who) +"与本门毫无渊源，为什么问起这个？\n";

   if (present("tie zhang", who)) return "你身上不是已经有铁杖了吗，怎么又来要？\n";

   if (!(number = me->query("apply/staffno"))) return "对不起，兵器已经全部发放出去了。\n";
   set("apply/staffno", --number);

   ob = new("/d/nanhai/obj/tiezhang");
   ob -> move(me);
   command("give " + who->query("id") + " staff");
   return "千万记住，兵器只可用来防身，不可滥杀无辜。";
}

string ask_spear(object me)
{
        object ob, who = this_player();
        int number;

        if (who->query("family/family_name") != "南海普陀山")
     return RANK_D->query_respect(who) +"与本门毫无渊源，为什么问起这个？\n";

   if (present("iron spear", who)) return "你身上不是已经有铁枪了吗，怎么又来要？\n";

   if (!(number = me->query("apply/spearno"))) return "对不起，兵器已经全部发放出去了。\n";
   set("apply/spearno", --number);

   ob = new("/d/nanhai/obj/tieqiang");
   ob -> move(me);
   command("give " + who->query("id") + " spear");
   return "千万记住，兵器只可用来防身，不可滥杀无辜。";
}

