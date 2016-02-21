// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

//inherit NPC;
//inherit F_VENDOR;
inherit F_VENDOR_SALE;

void create()
{
   reload("teawaiter");
       set_name("茶博士", ({"cha boshi","waiter"}));
   set("shop_id", ({"boshi", "waiter"}));
       set("gender", "男性");
       set("class", "scholar");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiudai": "/d/moon/obj/jiudai",
                "huasheng": "/d/ourhome/obj/huasheng",
        ]) );

       setup();
}
void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");
}
