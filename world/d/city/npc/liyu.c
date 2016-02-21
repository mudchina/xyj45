// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string fan_me(object me);

void create()
{
        set_name("李玉娘", ({"li yuniang", "li"}));
        set("age", 28);
        set("gender", "女性");
        set("long",
"李玉娘是袁天罡的老婆，正在洗菜做饭。\n");
        set("attitude", "friendly");
   set("per", 25);
        set("combat_exp", 4000);
        set("shen_type", 1);
        set_skill("unarmed", 20);
   set_skill("parry", 20);
        set_skill("dodge", 40);
        set("inquiry", ([
"袁天罡": "气死人了，这么晚了也不回家吃饭！也找不到个人把饭送去！\n",
"送饭": (: fan_me :),
]));

   setup();

        carry_object("/d/obj/cloth/pink_cloth")->wear();
   carry_object("/d/city/obj/fanhe");
}
string fan_me(object me)
{   object who;
   who=this_player();
   
   if(!present("fan he", me)){
   return "这天黑路远的，算了吧，多谢了！\n";
   }
   if(present("fan he", me)){
   command("give fan to " + who->query("id"));
   return "多谢了，快去吧！";
   }
}
