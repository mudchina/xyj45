// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "招魂司");
  set ("long", @LONG

招魂司内寒气森森，堂周是青布围幔，上面用金银丝线绣着些奇怪
的图案。堂前两侧阴兵分列，气势汹汹。堂上一张拱木案，上面摆
放了些文书。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk1",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baiwuchang" : 1,
]));


  set("hell", 1);

  setup();
}

