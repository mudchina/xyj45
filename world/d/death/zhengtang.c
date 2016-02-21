// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "阎罗宝殿");
  set ("long", @LONG

这里便是名闻天下，令人提起心惊胆寒的阎罗地府。人死后都会
在这里受到应有的处置。正前一张大桌，后面坐着阎罗王，旁边
立着崔判官。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"new-walk5",
  "north": __DIR__"walk1",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
//  __DIR__"npc/panguan" : 1,
]));
  setup();
  call_other("/obj/board/shengsi_b", "???");
}
