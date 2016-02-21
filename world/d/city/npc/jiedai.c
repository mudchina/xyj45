// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;

void create()
{
        set_name("陆九渊", ({"lu jiuyuan", "lu"}));
        set("gender", "男性");
   set("title", "礼部侍郎");
        set("age", 55);
        set("str", 25);
        set("long", "陆九渊是朝廷礼部侍郎，专管外宾接待。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
   set("force_factor", 10);
        set_skill("unarmed", 80);
        set_skill("dodge",80);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);

        setup();
        carry_object(__DIR__"obj/choupao")->wear();
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
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "陆九渊笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，欢迎到我大唐！\n");
break;
        }
}

