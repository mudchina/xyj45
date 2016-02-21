// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  reload("zhuzi_hefa_laotong");
  set_name("鹤发老童", ({"hefa laotong", "laotong"}));
  set("shop_id", ({"laotong"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 60);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "yao": "/d/qujing/zhuzi/obj/yao",
        "yaozhan": "/d/qujing/zhuzi/obj/yaozhan",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  add_money("silver", 10);
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

