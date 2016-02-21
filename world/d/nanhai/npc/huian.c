// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guanyin.c 惠岸行者
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

string ask_for_partner();

void create()
{
   set_name("惠岸行者", ({ "huian xingzhe", "huian", "xingzhe" }));
   set("title", "观音首徒");   
   set("long", @LONG
李天王二太子木叉，南海观音大徒弟惠岸行者。
LONG);
   set("gender", "男性");
   set("age", 25);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("class", "bonze");
   set("max_kee", 1000);
   set("max_gin", 600);
   set("max_sen", 1000);
   set("force", 2000);
   set("max_force", 1000);
   set("force_factor", 75);
   set("max_mana", 1000);
   set("mana", 2000);
   set("mana_factor", 55);
   set("combat_exp", 750000);

        set("eff_dx", 150000);
        set("nkgain", 300);

   set_skill("literate", 100);
   set_skill("spells", 120);
   set_skill("buddhism", 120);
   set_skill("unarmed", 100);
   set_skill("jienan-zhi", 100);
   set_skill("dodge", 100);
   set_skill("lotusmove", 100);
   set_skill("parry", 100);
   set_skill("force", 100);
   set_skill("lotusforce", 100);
   set_skill("staff", 110);
   set_skill("lunhui-zhang", 110);
   set_skill("spear", 80);
   set_skill("huoyun-qiang", 60);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 40);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :)
   }) );

   set("inquiry", ([
     "dadang" : (: ask_for_partner :),
     "partner" : (: ask_for_partner :),
     "搭档": (: ask_for_partner :),
     ]) );

   create_family("南海普陀山", 2, "弟子");

   setup();
//    carry_object("/obj/money/thousand-cash");
    carry_object("/obj/money/gold");
   carry_object("/d/nanhai/obj/sengpao")->wear();
   carry_object("/d/nanhai/obj/budd_staff")->wield();
}

void attempt_apprentice(object ob)
{
   if (!((string)ob->query("bonze/class") =="bonze" )) {
     command("say " + RANK_D->query_respect(ob) + "未入佛门，恕贫僧不能接纳。\n");
     return;
   }   
   if (((int)ob->query_skill("buddhism", 1) < 50 )) {
     command("say " + RANK_D->query_respect(ob) + "若欲深修，需得熟读佛法。\n");
     return;
   }
   command("nod");
   command("say 很好，贫僧就收下你，希望你多加努力，早成正果。\n");

   command("recruit " + ob->query("id") );
   return;   
}

string ask_for_partner()
{

   object me = this_player();
   string dadang;

   if ( (string)me->query("family/family_name")!="南海普陀山")
     return "只有南海普陀山弟子才能寻找搭档。\n";
   if( (string)me->query("bonze/class")!="bonze" )
     return "施主既非佛门中人，何必多问？\n";
   if( (dadang=(string)me->query("bonze/dadang")) !=0 )
     return "你的搭档是"+dadang+"。\n";

   me -> set_temp("pending/dadang_inquiry", 1);

   return RANK_D->query_respect(me)+"请用 \"dadang <id>\" 来选择你的搭档。\n";
}

int do_dadang(string arg)
{
object obj, me=this_player();
string dadang;

   if ( (string)me->query("family/family_name")!="南海普陀山")
     return notify_fail("只有南海普陀山弟子才能寻找搭档。\n");
   if( (string)me->query("bonze/class")!="bonze" )
     return notify_fail("施主既非佛门中人，何必多问？\n");
   if( (dadang=(string)me->query("bonze/dadang")) !=0 )
     return notify_fail("你的搭档是"+dadang+"。\n");
   if( !me->query_temp("pending/dadang_inquiry") ) 
     return notify_fail("你还没问过"+this_object()->query("name")+"呢！\n");
   me->delete("pending/dadang_inquiry");

   if (!arg) 
     return notify_fail("你要和谁做搭档？\n");

   obj = present(arg, environment(me));
   if (!userp(obj)) return notify_fail("\n");

   if (me->query("gender") == obj->query("gender") )
     return notify_fail("你只能与异性同门做搭档。\n");

   if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

   if( obj->query_temp("pending/dadang") != me) {
     message_vision("\n$N当着"+this_object()->query("name")+"的面，对$n说道："
        + RANK_D->query_self(me)+ me->name() 
        + "，欲与" + RANK_D->query_respect(obj)
        + "做一对搭档，日后一起行走江湖，同生死，共患难，"
        + RANK_D->query_respect(obj) + "意下如何？\n\n", me, obj);
     me->set_temp("pending/dadang", obj);
     return 1;
   }

   obj->delete_temp("pending/jiebai");
   message_vision("\n$N当着"+this_object()->query("name")+"的面，对$n说道："
     + RANK_D->query_self(me)+ me->name() 
     + "，愿与" + RANK_D->query_respect(obj)
     + "做一对搭档！\n\n", me, obj);

   obj->set("bonze/dadang", me->query("name"));
   obj->set("bonze/dadangid", me->query("id"));
   me->set("bonze/dadang", obj->query("name"));
   me->set("bonze/dadangid", obj->query("id"));
   return 1;

}

void init()
{
   add_action("do_dadang", "dadang");
}


