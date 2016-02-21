// Room: "/d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "茅山道观");
        set("long", @LONG
这是一间阴森的道观，在你面前的神桌上供奉著三清的塑像,一位貌似仙人
的道士正在练功。门是朝北开的。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"eroad3",
]));
        set("objects", ([ /* sizeof() == 2 */
                CLASS_D("taoist") + "/taolord":1,      
                __DIR__"npc/tao_first" : 1,
               __DIR__"npc/tao_2" : 1        
         ]));
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
