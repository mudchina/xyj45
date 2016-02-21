// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
int give_me(object ob);

void create()
{
       set_name("龟八斗", ({"gui badou", "gui"}));

   set("long","海底的大才子，以才智过人著称，并且会画金龙符。\n");
          set("gender", "男性");
          set("age", 56);
        set("title", "军师");
        set("per", 10);
        set("max_kee", 1000);
        set("max_sen",700);
          set("attitude", "peaceful");
          set_skill("unarmed",100);
          set_skill("dodge",100);
        set_skill("parry", 100);
          set_skill("literate",100);
   set_skill("force", 100);
   set_skill("spells", 100);
        set("combat_exp", 200000);
   set("force", 400);
   set("force_factor",20);
   set("max_force", 400);
   set("mana", 400);
   set("max_mana", 400);
   set("mana_factor", 20);
        set("inquiry", ([
                "金龙符": (: give_me :),
                "fu": (: give_me :),
        ]) );


        setup();
        add_money("gold", 1);
       carry_object("/d/gao/obj/magua")->wear();

}

int give_me(object ob)
{
        object who, me;
        who=this_player();
        me=this_object();

        if( (string)who->query("family/family_name")!="东海龙宫" ) {
                message_vision("$N斜斜地瞟了$n一眼，说：此不足为外人道也！\n", me, who);
                return 1;
        }
   if ((int)me->query("number") >= 10)
     return notify_fail("龟八斗把手一伸，今天写太多了，明儿个再说吧！\n");

                ob=new("/d/sea/obj/fu");
                ob->move(who);
     me->add("number",1);

     message_vision("$N拿出张符纸来，画出金龙，递给了$n。\n", me, who);
                return 1;
}

