// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// /u/wuliao/firemount/longzhuang

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "红色庄院");
  set ("long", @LONG
红瓦盖的房舍，红砖砌的垣墙，红油门扇，红漆板榻，一片都是红的
。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhou2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));

  setup();
}
