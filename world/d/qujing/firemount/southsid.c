// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/wuliao/firemount/nonameroad

inherit ROOM;

void create ()
{
  set ("short", "山脚");
  set ("long", @LONG
南面是翠云山，往北翻过一座小山丘便是火焰山。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xiaomiao",
  "south" : __DIR__"cuiyunshan4",
  "northup" : __DIR__"southside2",
]));
  set("outdoors", "/u/wuliao");

  setup();
}
