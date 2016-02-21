// 
// 

inherit ROOM;
void create()
{
        set("short", "小面馆");
        set("long", @LONG
面馆的阵设当然很简陋，除了中午和晚上卖面之外也卖一些很简单的
旱点。有一种很油腻的韭菜合子，不是肠胃特别好的人，很难消化得了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx1",
]));
        set("objects", ([
        __DIR__"npc/oldman": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
