// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/nbridge.c
//cglaem...12/12/96.

inherit ROOM;

#define FILE __DIR__"npc/qianmian"

void create ()
{
  set ("short", "泾水桥北");
  set ("long", @LONG

往北穿过城门即可入城，跨过泾水桥往南有一条大官道离城。
顺着泾水之滨东西望去，在河边信步闲游的人着实不少。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wside1",
  "south" : __DIR__"bridge",
  "north" : __DIR__"nanchengkou",
  "east" : __DIR__"eside1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
   if(sizeof(children(FILE))<2)
     new(FILE)->move(this_object());
}





