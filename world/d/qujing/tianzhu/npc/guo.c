// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_guo_sanniang");
  set_name("郭三娘", ({"guo sanniang", "guo", "sanniang", "niang"}));
  set("shop_id", ({"sanniang", "niang"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "toujin": "/d/qujing/tianzhu/obj/toujin",
        "pitan": "/d/qujing/tianzhu/obj/pitan",
        "huabu": "/d/qujing/tianzhu/obj/huabu",
        "baibu": "/d/qujing/tianzhu/obj/baibu",
      ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/tianzhu/obj/yinjie")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

