// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
string clean_tower();
inherit NPC;
void create()
{
       set_name("苦宿禅师", ({"kusu chanshi", "chanshi"}));
       set("gender", "男性");
       set("age", 80);
        set("long", "一个身材瘦小的老和尚，一脸苦相。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 18);
   set("str", 25);
       set("combat_exp", 150000);
        set_skill("unarmed", 95);
        set_skill("dodge", 95);
        set_skill("parry", 95);
   set_skill("force", 95);
   set_skill("spells", 80);
   set_skill("buddhism", 80);
   set_skill("jienan-zhi", 80);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 40);
        set("mana", 30);
set("inquiry", ([
"here" : "此地乃是祭赛国赦建金光寺。\n",
"冤枉": "佛宝失窃，我等遭国王训斥，苦不堪言那！\n",
"佛宝": "佛宝原放在琉璃塔上。\n",
"琉璃塔" : "琉璃塔便在寺中后院。\n",     
"扫塔" : (: clean_tower :),
]));

setup();
   carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}

string clean_tower()
{
   object me,obj,env;
   me=this_object();
   obj=this_player();
   env=environment(this_object());

   if( (string)env->query("short")!="大雄宝殿") {
     command("say " + RANK_D->query_respect(obj) + "的这番好意，老衲心领了，可老衲现也无能为力！\n");
     return "抱歉。\n";
   }
   if( env->query("exits/enter") ) {
     command("say 有劳"  + RANK_D->query_respect(obj) + "了，里面请。\n");
     return "真是好人呐。\n";
   }
   command("touchy " + obj->query("id"));
   env->open_down();
   return"真是好人呐。\n";
}
