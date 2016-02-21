#include <room.h>
inherit ROOM;
void create()
{
  set("short","耶丈室");
  set("long",@LONG
簇拥在禅房之间的为历代方丈的居所，兴国禅寺是南宗的嫡传寺
庙，始祖神会是六祖慧能晚年的得意弟子，此后人才辈出，向北有一
个小门，没有方丈的允许任何人不得擅入。
LONG
  );
  set("exits",([
         "south":__DIR__"houyuan.c",
         "north":__DIR__"mishi1.c",
         "east" :__DIR__"chanfang2.c",
         "west" :__DIR__"chanfang.c"
               ]));
          set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
 set("valid_startroom", 1);
  create_door("north","石门","south",DOOR_CLOSED);
  setup();
}
