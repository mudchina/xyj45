// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("大胡子", ({ "butcher", "da" }) );
        set("title", "屠记肉铺");
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个满脸大胡子，和横肉的家伙。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                __DIR__"obj/yangtou": 22,
                __DIR__"obj/zhutou" : 5,
                __DIR__"obj/niutou" : 10,
        ]) );

        setup();
        add_money("silver", 2);
        add_money("coin", 500);
        carry_object("/obj/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "大胡子咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
        }
}

 
