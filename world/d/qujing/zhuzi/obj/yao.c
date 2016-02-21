// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "大黄",
  "巴豆",
  "白芷",
  "雄黄",
  "雌黄",
  "陈皮",
  "龙骨",
  "川贝",
  "紫荆",
  "车前",
  "羊须",
  "狗尾草",
  "蚶壳",
  "莞根",
  "乌竹花",
  "牛黄",
});

void create()
{
  set_name("各类药草药品", ({"yao", "drug"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一小包药。\n");
    set("unit", "包");
    set("value", 300);
 //   set("no_sell", 1);
    set("food_remaining", 2);
    set("food_supply", 2);
  }
}

void init()
{
  add_action ("do_eat", "eat");
  if (query("name")=="各类药草药品")
  {
    set_name(names[random(sizeof(names))], ({"yao", "drug"}));
    call_out ("become_bad",600,this_object());
  }
  ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg)
    return ::do_eat(arg);

  if (present(arg,who) == me)
  {
    if (! me->query_temp("is_ready"))
      call_out ("uncomfortable",4,who);  
  }
  return ::do_eat(arg);
}

void uncomfortable (object who)
{
  message_vision ("$N肚子里一阵绞痛，汗如雨下，禁不住呻吟了一声。\n",who);
}

varargs int move (mixed dest, int silently)
{
  mixed status;
  object where;

  status = ::move(dest,silently);
  where = environment(this_object());
  if (where && where->query("id")=="yin yaozhan")
    where->make_drug();

  return status;
}

void become_bad (object me)
{
  set_name("变质的坏药", ({"huai yao"}));
  me->set_temp("is_ready",0);
  me->set("value", 0);
}
