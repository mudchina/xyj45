// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
  set ("short", "长安府大堂");
  set ("long", @LONG

大堂之上有一种威严之势，不由让人心惊胆颤。前方一张大桌，后面
坐着知府大人。上有一幅大匾，写着＂清正廉名＂四个烫金大字。桌
旁立着一位老先生。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zhongdu",
]));

        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}

