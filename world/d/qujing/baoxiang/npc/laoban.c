// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("baoxiang_lao_ban");
  set_name("老板", ({"laoban"}));
  set("shop_id", ({"laoban"}));
  set("shop_title", "老板");
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "yangtou": "/d/qujing/baoxiang/obj/yangtou",
        "paomo": "/d/qujing/baoxiang/obj/paomo",
        "zasui": "/d/qujing/baoxiang/obj/zasui",
      ]) );

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 10);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

