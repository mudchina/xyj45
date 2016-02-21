// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/eside5.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eside4",
]));
  set("outdoors", 1);

  setup();
}






