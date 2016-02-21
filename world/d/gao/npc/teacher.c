// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
       set_name("匡文正", ({ "kuang wenzheng", "kuang", "teacher"}));
       set("title", "教书先生");
       set("long","村里的老教书先生，孩子们的扫盲全靠他了．\n");
       set("gender", "男性");
       set("age", 66);
   set("int", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("literate",60);
   set_skill("sword", 40);
   set_skill("dodge", 40);
   set_skill("parry", 40);
   set("combat_exp", 10000);
set("inquiry", ([
"name"  : "老夫姓匡，字文正．阁下是．．．",
"here"  : "这儿是老夫办的学堂，教孩子们一些知识．",

]) );
set("chat_chance", 5);
set("chat_msg", ({
"匡文正说道：『小心天下去得，莽撞寸步难行』。你要牢牢记得．\n",
"匡文正摇头晃脑的念道：子曰：有朋自远方来，不亦乐乎．．无须备饭．\n",
"匡文正笑盈盈地跟你打招呼：吃了？！\n",
}) );

setup();
carry_object("/d/gao/obj/ruler")->wield();
carry_object("/d/gao/obj/changpao")->wear();
add_money("silver", 5);
}


