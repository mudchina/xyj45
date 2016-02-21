// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/guest_bedroom.c

#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "客房");
  set ("long", @LONG

将军府把他们的来客招待的周到无比，把款待客人的房间布置的非常
舒适。红木桌上沏了一壶好茶，摆着几盘点心。屋角香炉里传来一
阵阵清香。一张宽大柔软的床上铺着被褥，让人不觉昏昏欲睡。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "红木桌" : "
桌子上摆着丰盛的菜肴和碧绿的茶水。你不由得想坐下去吃(chi)一顿。
",
  "table" : "
桌子上摆着丰盛的菜肴和碧绿的茶水。你不由得想坐下去吃(chi)一顿。
",
]));
  set("resource", ([
   "water": 1
   ]) );
  set("if_bed", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaotong" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
      "northeast" : __DIR__"front_yard.c",
      "east" : __DIR__"front_yard2.c",
      ]));
  set("sleep_room", 1);
  set("no_get", 1);

  setup();
}

void init()
{
  add_action("do_chi", "chi");
  add_action("do_sleep", "sleep");
  add_action("do_get", "get");
}

int do_get(string arg)
{
    object ob;
    string thing, person;

    if(!arg) return notify_fail("你要拿什么？\n");
    sscanf(arg, "%s from %s", thing, person);
    if (!person) person=arg;
    if( present("xiao tong", this_object())
    &&  ob=present(person, this_object()))
    {
   if(userp(ob))
   {
       message_vision(CYN"小童对$N喝道：不得无理！$n乃本府贵客！\n"NOR, this_player(), ob);
       return 1;
   }
    }
    return 0;
}

int do_sleep(string arg)
{
  object me=this_player();
  int mypot, mylearned;
  int pot;

  if (me->query("family/family_name") != "将军府"
  &&  present("xiao tong", this_object()))
  {
   tell_object(me, CYN"小童喝道：你是这里的客人嘛？\n"NOR);
   return 1;
  }
  if (me->query("family/master_id") == "cheng yaojin"
   || me->query("family/master_id") == "lao ren")
  {
    mypot=me->query("potential");
    mylearned=me->query("learned_points");
    pot=mypot-mylearned;
    if (random(pot+me->query_kar()) > 50)
    {
   tell_object(me, "你往被中一钻，开始睡觉。\n");
        tell_object(me, "恍惚地，你似乎觉得自己到了另一个地方。\n");
   me->set("kee", me->query("eff_kee"));
   me->set("sen", me->query("eff_sen"));
   me->set("force", me->query("max_force"));
   me->set("mana", me->query("max_mana"));
   me->move(__DIR__"sleep");
   return 1;
    }
  }
  return 0;
}
int do_chi(string arg)
{
  object me=this_player(), ob;
  int kar=me->query_kar(me);

  if(me->query("family/family_name") != "将军府"
  && present("xiao tong", this_object()))
   return notify_fail(CYN"小童喝道：你是将军府的客人嘛？\n"NOR);
  message_vision( "$N坐了下来，一口菜一口茶，没多会儿就吃得心满意足了。\n", me);
  me->set("water", me->max_water_capacity());
  me->set("food", me->max_food_capacity());
  me->start_busy(random(31-kar));
  return 1;
}
