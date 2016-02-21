inherit ROOM;
void create()
{
        set("short", "湖上女");
        set("long", @LONG
湖上女，精选正轻盈。
犹恨乍离金殿侣，相将尽是采莲人，清唱谩频频。
轩内好，嬉戏下龙津。
玉管朱弦闻尽夜，踏青斗草争青春，玉辇从群真。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"xue",
  "south" : __DIR__"lastbridge",
]));
        set("objects", ([
        __DIR__"npc/nu" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
