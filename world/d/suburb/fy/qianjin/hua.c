inherit ROOM;
void create()
{
        set("short", "湖上花");
        set("long", @LONG
湖上花，天水浸灵芽。
浅蕊水边匀玉粉，浓苞天外剪明霞，日在列仙家。
开烂熳，插鬓若相遮。
水殿春寒幽冷艳，玉轩晴照暖添华，清赏思何赊。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cao",
  "east" : __DIR__"jiu",
]));
        set("objects", ([
        __DIR__"npc/hua" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
