// keeper.c

inherit NPC;

void create()
{
        set_name("教父", ({ "priest" }) );
        set("gender", "男性" );
        set("age", 74);
        set("long",
"这个老人金发碧眼，足足有七尺多高。\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
        setup();
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
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "教父说道：这位" + RANK_D->query_respect(ob)
                + "，主会保佑你的．\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = (int) ob->value();
        if( val > 100 ) {
                if( ((int)who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "教父说道：多谢这位" + RANK_D->query_respect(who)
                + "，主一定会保佑你的。\n");

        return 1;
}
 
