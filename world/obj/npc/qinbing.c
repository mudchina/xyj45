// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// qinbing.c
//亲兵, used for jjf people.

#include <ansi.h>

inherit NPC;

void create()
{
   set_name("亲兵", ({ "qinbing" }) );
   set("long", "这些亲兵都是久经战阵的好手，跟着将军们出生入死，极得信任。\n");
   set("attitude", "friendly");
   set("class", "fighter");

   set("max_gin", 200);
   set("max_kee", 500);
   set("max_sen", 300);
   set("max_force", 300);
   
   set("str", 40);
   set("cor", 30);
   set("cps", 25);
   set("per", 10+random(15));

   set("combat_exp", 40000);
   set_skill("parry", 50);
   set_skill("dodge", 40);
   set_skill("unarmed", 50);
   set_skill("changquan", 50);
   set_skill("spear", 50);
   set_skill("bawang-qiang", 50);
   map_skill("unarmed", "changquan");
   map_skill("spear", "bawang-qiang");

   setup();

   carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

void leave()
{
   message("vision", name() + "四周张望了一下，一溜烟地跑了。\n", environment(), this_object() );
   destruct(this_object());
}

void show(object who)
{
   string *cname = ({"亲兵甲", "亲兵乙", "亲兵丙", "亲兵丁"});
   string *ename = ({"-jia", "-yi", "-bing", "-ding"});

   int current = 0;
   current = (int)who->query_temp("jjf_current_bing");

   if(current < 1 || current > 4 )
   {
     destruct(this_object());
     return;
   }

   this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );   

   message_vision("随着一阵跑步声，一位身披铠甲，手执长枪的兵丁冲到$N面前行了个礼，大声说道：在下随时听调！\n", who);

    //set the leader of this bing.
   set("owner_id", (string)who->query("id")); 
   set_leader(who);
}

void relay_whisper(object me, string msg)
{
   if (query("owner_id") != me->query("id"))
   {
     message_vision((string)this_object()->query("name") 
        + "对着$N冷哼了一声。\n", me);
     return;
   }
   
   //note, do not allow the order contain "chat", "tell"...
   //may need disable more later...
   if( strsrch(msg, "chat") != -1 ||
       strsrch(msg, "tell") != -1 ||
       strsrch(msg, "apprentice") != -1 ||
       strsrch(msg, "recruit") != -1 ) 
     return;

   message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
   if (msg)
   {
     remove_call_out ("relaying");
     call_out ("relaying", 1+random(3), msg);
   }
}

void relaying (string msg)
{//execute the order.
   command (msg);
}

void init()
{       
   object me=this_player();
   object owner;

   ::init();

   //make sure this bing always follow his owner.
   if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
   {
     this_object()->set_leader(me);
   }

   //if owner leaves, let this bing have chance to disappear.
   if( this_object()->query("owner_id") != 0 )
   {
     owner = find_player( (string)this_object()->query("owner_id") );
     if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
     if( !owner )
     {
        remove_call_out ("leave");
        call_out ("leave", 1);
     }
   }
     
}

