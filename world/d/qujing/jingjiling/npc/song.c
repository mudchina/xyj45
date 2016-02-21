// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

#include <allnpc.h>

void create()
{
        set_name("十八公", ({"shiba gong", "gong"}));
        set("age", 90);
   set("attitude", "peaceful");
        set("gender", "男性");
   set("class", "yaomo");
   set("title", "深山四操");
   set("nickname", "盖张翠影");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
   set("max_gin", 1500);
        set("max_kee",2000);
        set("max_sen", 2000);
        set("combat_exp", 1100000);

        set("force", 1000);
        set("max_force", 1000);
        set("mana",1500);
        set("max_mana", 1500);
        set("mana_factor", 100);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 100);
   set_skill("parry", 100);
   set_skill("spells", 200);
   set_skill("stick", 200);
        setup();

   carry_object("/d/qujing/jingjiling/obj/zhang")->wield();
   carry_object("/d/qujing/jingjiling/obj/cloth")->wear();
}
int accept_fight(object ob)
{
   object me = this_object();
        object who=this_player();

        if(me->is_fighting() )
                return notify_fail("十八公对你说：没见老夫正忙着那么？\n");
        if( (int)me->query("kee")*100/(int)me->query("max_kee") < 30 )
                return notify_fail("十八公对你说：老夫体乏无力，比不得，比不得。\n");

        if( who->query_temp("poem_song") ) {

        command("say 好，好，你我切搓武艺，点到为止！\n");
   reset_me ();
   call_out ("check_fight",1,who);
        return 1;
        }
        command("say 且待老夫考你一考。\n");
        who->set_temp("answer_song", 1);
        call_out("ask_poem", 3, who);
        return 0;
}

void ask_poem(object who)
{
        object me=this_object();
        message_vision("$N对$n问道：“花间一壶酒”的下句是什么？\n", me, who);
        message_vision("$N说：老夫限你三十秒内回答(answer)。\n", me);
        me->set_temp("check_answer", 1);
        call_out("say_answer", 30);
        return;
}
void say_answer(object who)
{
        if(!who) return;

        command("sigh");
        command("say 连这都不知道，老夫不屑与你一斗！\n");
        this_object()->delete_temp("check_answer");
        who->delete_temp("answer_song");
        return ;
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object where=environment(this_object());

        if( !(this_object()->query_temp("check_answer") ) )
                return notify_fail("什么？\n");

        if( !arg ) return notify_fail("你说什么？\n");

        message_vision("$N答道：是“" + arg + "”。\n", this_player());

        if( this_player()->query_temp("answer_song") ) {

                if( strsrch(arg, "独酌无相亲") >=0  ) {
                command("haha");
                command("say 不错，不错！老夫就与你过两招。\n");
                this_player()->set_temp("poem_song", 1);
                this_player()->delete_temp("answer_song");
                this_object()->delete_temp("check_answer");
                if(where->query("short")!="石崖") {
                        command("say 这里不甚宽敞，你我石崖一聚。\n");
                        message_vision("$N身影一晃便不见了。\n", this_object());
                        this_object()->move("/d/qujing/jingjiling/shiya");
                        message_vision("$N走了过来。\n", this_object());
                }
        remove_call_out("say_answer");
                return 1;
                }else{
                command("sigh");
                command("say 不对，不对！\n");
                return 1;
                }
        }else{
        command("sigh " + this_player()->query("id") );
        command("say 多嘴，多嘴！");
        return 1;
        }
}

