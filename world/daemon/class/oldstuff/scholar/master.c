// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
   set_name("骆云舟", ({ "master scholar", "master", "scholar" }) );

   set("gender", "男性");
   set("age", 32);
   set("long",
     "骆云舟生于京城有名的武林世家，他的本名是骆建炎，但是因为生性喜爱\n"
     "四处游荡，遂自号「云舟」，四处游山玩水，结交豪杰异人。数年前继承\n"
     "其父骆易而成为步玄派的新任掌门，但是喜爱飘泊的个性仍然不改，令门\n"
     "中耆宿头痛不已。\n" );

   set("attitude", "peaceful");
   create_family("步玄派", 7, "掌门人");

   set("str", 26);
   set("cor", 30);
   set("int", 24);
   set("cps", 30);

   set("force", 3000);
   set("max_force", 1600);
   set("force_factor", 20);

   set("combat_exp", 1000000);
   set("score", 200000);
/*
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: consider :),
     (: exert_function, "powerup" :),
     (: exert_function, "recover" :)
   }) );
*/
   set_skill("unarmed", 60);
   set_skill("sword", 90);
   set_skill("force", 80);
   set_skill("parry", 90);
   set_skill("dodge", 100);
   set_skill("literate", 150);
   set_skill("perception", 80);

   setup();
}

/*
void init()
{
   add_action("do_swear", "swear");
}

void attempt_apprentice(object me)
{
   if( me->query_temp("pending/celestial_swear") ) {
     command("say 多说无益，若不发誓恪守门规，便是跪着求我也没用。");
     return;
   } else {
     command("say 我天邪派门规甚严，" + RANK_D->query_respect(me)
        + "如果真的有心，且发个誓(swear)来。");
     me->set_temp("pending/celestial_swear", 1);
   }
}

int do_swear(string arg)
{
   if( !this_player()->query_temp("pending/celestial_swear") )
     return 0;
   if( !arg ) return notify_fail("你要发什么誓？\n");
   this_player()->set_temp("pending/celestial_swear", 0);
   message_vision("$N发誓道：" + arg + "\n", this_player());
   if( strsrch(arg, "守") >=0 && strsrch(arg, "门规") >=0 ) {
     command("smile");
     command("say 这就是了。\n");
     command("recruit " + this_player()->query("id"));
   } else {
     command("say 你发的是什么鬼誓，别以为我没听到！");
   }
   return 1;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     add("apprentice_availavble", -1);
}
*/
void consider()
{
   int i, flag = 0;
   object *enemy;

   enemy = query_enemy() - ({ 0 });
   for(i=0; i<sizeof(enemy); i++) {
     if( !living(enemy[i]) ) continue;
     if( enemy[i]->query_temp("weapon") ) {
        flag++;
        if(   !query_temp("weapon") ) {
          command("say " + RANK_D->query_respect(enemy[i]) + "既然使兵刃，在下空手接招未免不敬。");
          command("wield sword");
          command("say 进招吧！");
          break;
        }
     }
   }
   if( !flag && query_temp("weapon") ) {
     if( sizeof(enemy) > 1 )
        command("say 嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手，在下理当奉陪！");
     else
        command("say 既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃，在下自然奉陪！\n");
     command("unwield sword");
   }
}
