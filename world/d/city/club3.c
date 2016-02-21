// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/city/club3
inherit ROOM;

void create ()
{
  set ("short", "聚义厅");
  set ("long", @LONG

这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱子上贴
满了各种广告：有换房的，有卖家具的，但其中最多的还是找打牌搭
档的广告。厅的东南西北各有个门，里面传出“拱啊！”“毙了！”
等的叫声。
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"clubpoem",
  "north": __DIR__"piggy",
]));

  setup();
  call_other("/obj/board/zhuzi_b", "???");

}
