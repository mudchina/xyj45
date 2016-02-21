// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "三心宫");
  set ("long", @LONG

三心宫里面供着一个青玉大案，上面有青铜香炉，里面插着香正冒着
袅袅的青烟。宫的东西两边都绘着各种神像，北边通向三个不同的宫
殿，南边是出口。

LONG);

  set("exits", ([
        "south" : __DIR__"wanshou",
        "north" : __DIR__"ningxin",
      ]));

  setup();
}

void init ()
{
  object who = this_player();


  if (who->query_temp("kaifeng_qingxin") &&
      who->query_temp("kaifeng_ningxin") &&
      who->query_temp("kaifeng_jingxin"))
  {
    who->start_busy (1,1);
    who->delete("quest/pending");
    who->delete_temp("kaifeng_qingxin");
    who->delete_temp("kaifeng_ningxin");
    who->delete_temp("kaifeng_jingxin");

    who->set_temp("kaifeng_donate_silver",0);
    // delete temp after finish san-xin.

    call_out ("feeling",1,who);
  }
}

void feeling (object who)
{
  who->interrupt_me();
  message_vision ("$N走进三心宫，呼出一口气，顿时心境明朗如镜。\n",who);
}

