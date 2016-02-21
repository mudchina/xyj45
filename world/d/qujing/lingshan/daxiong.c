// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG

大雄宝殿里金碧辉煌紫气瑞瑞，根根玉柱雕麒麟，殿窗是金钉
银檐，殿顶亦上是金银鸳鸯双双对对，正中有一白玉玛瑙莲花
台。南边有一殿门通往后殿，东西边各有一偏门。

LONG);

  set("exits", ([
        "north"   : __DIR__"sanmen",
        "south"   : __DIR__"houdian",
        "west"   : __DIR__"zhenlou1",
        "east"   : __DIR__"baoge1",
      ]));
  set("objects", ([
        __DIR__"npc/rulai" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}

