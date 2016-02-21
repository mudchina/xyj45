// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "白石溪");
  set ("long", @LONG

潺潺流水向山下流去，溪水清彻见底。水底布满了大小不一，洁
白如玉的鹅卵石，溪中的小鱼游来游去。溪边的草从中不时传出
蛙鸣。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"baixi2",
"southeast": __DIR__"uphill3",
]));

        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


