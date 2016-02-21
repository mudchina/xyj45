// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("qinfa_li_guafu");
  set_name("李寡妇", ({"li guafu", "li", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
    "choupao" : "/d/obj/cloth/choupao",
    "magua" : "/d/obj/cloth/magua",
    "ziyi" : "/d/obj/cloth/ziyi",
    "hat" : "/d/obj/cloth/hat",
    "buxie" : "/d/obj/cloth/buxie",
  ]));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
  add_action ("do_vendor_list", "list");
}
