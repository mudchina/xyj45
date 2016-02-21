// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/mimi/zhuziguo/street1  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "山脚");
  set ("long", @LONG

两旁林木茂盛，遮天蔽日。满径落叶，柔软稀松。虫鸟啾啾。
凉风习习。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "northeast" : __DIR__"shandao2",
    "west" : __DIR__"street2",
    "eastup" : __DIR__"road7",
    "southwest" : __DIR__"shandao3",
  ]));
  set("outdoors", __DIR__"");                   

  setup();
}
