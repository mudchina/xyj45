// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/fengc.c

inherit ROOM;

void create ()
{
  set ("short", "金龙厅");
  set ("long", @LONG

封神台东侧为金龙厅。厅内明霞幌幌，缠绕着金鳞耀日赤须龙。
两边天将仙卿紫绶金章芙蓉冠，如金璧辉煌。厅外长满万万载
常青的绣草。

LONG);

  set("exits", ([
        "north" : __DIR__"pan3e",
        "west"  : __DIR__"fengb",
      ]));

  set("objects", ([
        __DIR__"npc/male"   : 1,
      ]));

  setup();
}

