inherit ROOM;
void create()
{
        set("short", "土嫖馆");
        set("long", @LONG
一间简陋的，用泥坯砌起来的低矮小房。东面的墙上有条裂缝，从右上角一直裂到左
边的墙角里。西边有一张和泥屋连为一体的土炕。炕下有灶，冬天可以生火取暖，炕头
挂着厚布蚊帐，帐上贴纸一张：价格最平，男女老少皆宜，恕不找钱。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud3",
]));
        set("objects", ([
        __DIR__"npc/chick" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
