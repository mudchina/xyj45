// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /4world/flowerfruit
inherit ROOM;

void create ()
{
  set ("short", "花果山");
  set ("long", @LONG

此山乃十洲之祖脉，三岛之来龙，自开清浊而立，鸿蒙判后
而成。真个好山！有词赋为证。赋曰：

　　　　势镇汪洋，潮涌银山鱼入穴；
　　　　威宁瑶海，波翻雪浪蜃离渊。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aolai",
  "northup" : __DIR__"up1",
]));
  set("outdoors", 1);

  setup();
}
