// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "山洞内");
  set ("long", @LONG

山洞里黑乎乎的，到处都发出股腥臭味。北边山洞弯弯地通向
深处。洞深处传出几丝铉乐，似乎在开大宴。
LONG);

  set("exits", ([
        "south" : __DIR__"lu1",
        "north"      : __DIR__"lu3",
      ]));
//  set("outdoors", __DIR__);

  setup();
}





