// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/nanhai/guangchan
inherit ROOM;

void create ()
{
  set ("short", "洞前广场");
  set ("long", @LONG

这是南海普陀山上一快比较平整的土地，普陀山门人弟子们经
常在这里切磋武艺，宣讲佛法，交流心得。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huian" : 1,
  __DIR__"npc/zhangmen" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaoyuan",
  "west" : __DIR__"zoulang",
  "east" : __DIR__"road1.c",
  "enter" : __DIR__"chaoyindong",
]));

  setup();
}

//object zhangmen = 0;
/*
void init ()
{

  if (! zhangmen)
  {
// zhangmen = present("zhang men",this_object());

zhangmen = new ("/d/npc/zhangmen");

    zhangmen->create_identity(__DIR__"npc/guanyin",this_object());
  }
}
*/
