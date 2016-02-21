// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yashi.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "雅室");
  set ("long", @LONG

高小姐的卧房便是这里．卧房吗．．当然是休息的地方了．．
靠内有一张素净的床铺(bed)，但空荡荡地不见一个人影．．．
LONG);

set("item_desc",(["bed":"睡觉用的床铺(gosleep,gobed,bed)。 \n", ]));
set("exits", ([ /* sizeof() == 4 */
"down" : __DIR__"guige",
]));

create_door("down", "雕花竹门", "up", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
   add_action("do_bed", "gosleep");
   add_action("do_bed", "gobed" );
   add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
         message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
     me->move("/d/gao/bed_yashi");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
            return 1;
}
