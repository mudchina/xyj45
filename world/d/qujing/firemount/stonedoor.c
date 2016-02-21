// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /u/wuliao/firemount/stonedoor.c
inherit ROOM;

void create ()
{
  set ("short", "石洞门");
  set ("long", @LONG
洞门由两块大石板依山势修葺而成。旁有一堆乱石，似是为封严
洞门时准备的。
LONG);

  set("light_up", 1);
  set("outdoors", "firemount");
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongkou",
]));

  setup();
}
