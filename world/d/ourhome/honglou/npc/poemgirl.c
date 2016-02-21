// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// poemgirl.c

inherit NPC;

#include <ansi.h>

int send_back(object me);

void create()
{
   set_name("探春", ({ "tan chun", "chun", "girl" }) );
   set("gender", "女性" );
   set("age", 16);
   set("combat_exp", 200000);
   set("attitude", "friendly");
   set_skill("literate", 100);
   set_skill("dodge", 100);
   setup();
   carry_object("/d/obj/cloth/skirt")->wear();
   carry_object("/d/obj/cloth/shoes")->wear();
}
