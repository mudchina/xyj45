// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/jjf/sleep-2
inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG

漫步过来，没想道这里居然有间小茅屋。屋子里空空的，没什么摆设，
只是不知哪里传来阵阵幽香，令人精神为之一爽。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sleep",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baifalaoren.c" : 1,
]));

  setup();
}
