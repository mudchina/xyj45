// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_dai_jie");
  set_name("黛姐", ({"dai jie", "dai", "jie"}));
  set("shop_id", ({"daijie", "dai", "jie"}));
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 20);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "huaping": "/d/qujing/tianzhu/obj/vase",
        "huapen": "/d/qujing/tianzhu/obj/pen",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixie")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

