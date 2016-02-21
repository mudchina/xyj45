inherit ROOM;
void create()
{
        set("short", "湖上水");
        set("long", @LONG
湖上水，流绕禁园中。
斜日暖摇清翠动，落花香暖众纹红，苹末起清风。
闲纵目，鱼跃小莲东。
泛泛轻摇兰棹稳，沉沉寒影上仙宫，远意更重重。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"jiu",
  "north" : __DIR__"grassroom",
]));
        set("objects", ([
        __DIR__"npc/shui" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
