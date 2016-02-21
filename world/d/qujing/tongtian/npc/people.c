// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat  11/22/1997

inherit NPC;

string *mnames = ({
  "陈康",
  "陈禄",
  "陈溯",
  "陈鸠",
  "陈蜀",
  "陈焘",
  "陈戛",
  "陈笮",
  "陈子虬",
  "陈龙大",
  "陈大头",
  "陈小个",
  "陈老大",
  "陈老二",
  "陈老三",
  "陈老四",
  "陈大伯",
  "陈大叔",
  "陈大舅",
  "陈大哥",
  "陈大爷",
  "陈二伯",
  "陈二叔",
  "陈二舅",
  "陈二哥",
  "陈二爷",
  "陈三伯",
  "陈三叔",
  "陈三舅",
  "陈三哥",
  "陈三爷",
  "陈四伯",
  "陈四叔",
  "陈四舅",
  "陈四哥",
  "陈四爷",
});

string *fnames = ({
  "陈娘",
  "陈氏",
  "陈婆",
  "陈妈",
  "陈嫂",
  "陈婶",
  "陈大娘",
  "陈大婆",
  "陈大妈",
  "陈大嫂",
  "陈大婶",
  "陈二娘",
  "陈二婆",
  "陈二妈",
  "陈二嫂",
  "陈二婶",
  "陈三娘",
  "陈三婆",
  "陈三妈",
  "陈三嫂",
  "陈三婶",
  "陈四娘",
  "陈四婆",
  "陈四妈",
  "陈四嫂",
  "陈四婶",
});

void create()
{
  string cloth;

  if (random(2))
  {
    int i = random(sizeof(mnames));
    set_name(mnames[i], ({"chen"}));
    set("gender", "男性");
    cloth = "/d/qujing/tongtian/obj/cloth";
  }
  else
  {
    int i = random(sizeof(fnames));
    set_name(fnames[i], ({"chen"}));
    set("gender", "女性");
    cloth = "/d/qujing/tongtian/obj/skirt";
  }
  set("combat_exp", 1000+random(20000));
  set("age", 40+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  setup();
  carry_object(cloth)->wear();
}


