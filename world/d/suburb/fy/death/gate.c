// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIW "鬼门关" NOR);
        set("long", 
                "这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
                
"黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
                "回阳间了。\n");
        set("exits", ([
                "north" : "/d/suburb/fy/death/gateway",
        ]) );
        set("objects", ([
                __DIR__"npc/wgargoyle":1
        ]) );
        setup();
        replace_program(ROOM);
}
 
