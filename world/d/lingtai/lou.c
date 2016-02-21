// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// jingge.c

inherit ROOM;

void create()
{
  set ("short", "小室");
  set ("long", @LONG

这里是经阁中的一间小室，为弟子们研读经书提供了一个安静个
地方．墙上挂着一个条幅，写着＂潜思入定＂四个龙飞凤舞的大字．
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"jingge",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}



