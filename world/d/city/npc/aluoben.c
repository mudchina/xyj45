// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// keeper.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("阿罗本", ({ "a luoben", "monk", "luoben" }) );
        set("gender", "男性" );
        set("age", 54);
   set("str", 25);
   set("per", 25);
   set("title", "波斯僧人");
   set("long",
   "这是一位来自西域的景教僧人，鹰鼻深目，须发皆白。\n"
   "象有满腹的学问，正坐在那里闭目沉思。\n");
        set("combat_exp", 100000);
        set("attitude", "peaceful");

   set_skill("dodge", 80);
   set_skill("force", 80);
   set_skill("parry", 80);
   set_skill("unarmed", 80);
        set_skill("literate", 80);

   set("max_kee", 800);
        set("max_gin", 300);
   set("max_sen", 400);
   set("max_force", 300);
   set("force", 300);
   set("force_factor", 10);
   set("max_mana", 200);
   set("mana", 200);
   set("mana_factor", 10);

   set("inquiry", ([
     "here": "大唐景教寺\n",
     "name": "阿罗本\n",
   ]) );

        setup();

   carry_object(__DIR__"obj/sengpao")->wear();
   carry_object(__DIR__"obj/sengxie")->wear();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || !present(ob, environment(this_object())) ) return;
        say( "阿罗本说道：这位" + RANK_D->query_respect(ob)
     + "，用你的真心向天父祈祷吧。\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("阿罗本不收物品的捐献。\n");
   else if( val > 100 )
   {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
                if(who->query("bellicosity")<0)
        who->set("bellicosity",0);
        }
        say( "阿罗本说道：多谢这位" + RANK_D->query_respect(who)
                + "，天父一定会保佑你的。\n");

        return 1;
}

