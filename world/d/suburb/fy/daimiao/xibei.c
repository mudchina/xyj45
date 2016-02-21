//mac's xibei.c
// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","西碑廊");
  set("long",@LONG
此为历代皇帝举行封禅大典时的碑刻，最引人注目的是秦二世泰
山刻石，为公元前２０９年秦二世胡亥东封泰山时，令丞相李斯书刻
的，可惜仅存十个残字：臣斯去疾昧死臣请矣臣。
LONG
  );
  set("exits",([
         "east":__DIR__"zhengyuan.c",
               ]));
   
  setup();
  replace_program(ROOM);
}
