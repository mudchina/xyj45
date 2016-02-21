// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hill.c

inherit ROOM;

void create ()
{
  set ("short", "练功堂");
  set ("long", @LONG

屋里十分宽敞，墙上画的是一些叉术分解，靠墙的架子上放了十
余把长枪。地下铺的是裁剪整齐的木块，踩在上面吱吱做响。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"boy2",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long3.c" : 1,
//  "/d/obj/armor/tenjia" : 1,
  __DIR__"obj/mucha" : 1,
]));

  setup();
}
