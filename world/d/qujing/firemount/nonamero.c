// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/wuliao/firemount/nonameroad

inherit ROOM;

void create ()
{
  set ("short", "无名小路");
  set ("long", @LONG
前面就是山顶了，隐约可见山那边是一座高山。山上白云如烟，别是
一番天地。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"nonamemount",
  "northdown" : __DIR__"nonameroad3",
]));
  set("outdoors", "/u/wuliao");

  setup();
}
