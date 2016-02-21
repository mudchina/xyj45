inherit ROOM;
void create()
{
        set("short", "南风大街");
        set("long", @LONG
再往北走，就是风云城的中心广场。这里刚好是住在城南的大富人家去集市的
必经之路，豪富的行人导致这里崎形的繁荣。大街西侧的玉龙珠宝店人进人出，拥
挤不堪。东侧则是专门为有钱人的远方朋友到风云城来玩时所准备的凤求凰客栈。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind2",
  "north" : __DIR__"fysquare",
  "east" : __DIR__"fqkhotel",
  "west" : __DIR__"yuljade",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/mei": 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
