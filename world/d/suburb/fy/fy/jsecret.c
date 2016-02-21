inherit ROOM;
void create()
{
        set("short", "水牢");
        set("long", @LONG
肮脏恶臭的污水齐胸深，污水中钉着几根铁桩，桩上有精钢环，想必是来绑压犯人
的。偶尔几个水泡冒上水面，混杂着血沫和已泡得发白发臭的断肢。还有几个桩上用生
锈的铁链绑着几个面目狰狞的骷髅。一堆白白胖胖的蛆在欢快的爬进爬出。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"tang3",
]));
        set("objects", ([
        __DIR__"npc/xongyang": 1,
                        ]) );
        setup();
        replace_program(ROOM);
}
