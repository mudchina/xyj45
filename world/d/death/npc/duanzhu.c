// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
inherit NPC;

void create()
{
       set_name("断足鬼", ({"duanzu gui", "gui"}));
       set("gender", "男性");
       set("age", 60);
   set("long", "一个看起来相当可怜的老头。双足却不见了，躺在地下。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 100);
       set("combat_exp", 6000+random(1300));
   set_skill("unarmed", 15);
   set_skill("dodge", 15);
   set_skill("parry", 25);
   set_skill("stealing", 30);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: command, "surrender" :),
        }) );


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}

int accept_fight(object me)
{
        command("say 我已沦落到这个地步了，就可怜可怜我吧！\n");
        return 0;
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "断足鬼说道：这位" + RANK_D->query_respect(ob)
                + "，给点钱可怜可怜我吧。\n");
}

int accept_object(object who, object ob)
{
        int val;
        val = ob->value();

   if ( val > 0 )
     write("断足鬼笑了笑，多谢多谢！\n");
   if( val > 1000) {
   command ( "whisper " + who->query("id") + " 这崖下有个老头，一天到晚的哭，烦人的很．．．不过．．．听说．．．\n");
   }
   call_out("destroy", 1, ob);
   return 1;
   
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

