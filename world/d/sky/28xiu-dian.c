// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "二十八宿殿");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nanmenting.c",
]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"stars/foxer" : 1,
  __DIR__"stars/acer" : 1,
  __DIR__"stars/smallfox" : 1,
]));

  setup();
}
