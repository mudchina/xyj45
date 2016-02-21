
inherit ROOM;

void create()
{
        set("short", "警世书局");
        set("long", @LONG
此间书局是风云城中卖书最多，最快的地方。这里的老板大有名气，听说是当今皇
太子的老师。凡是京都出的新书，都被快马送到这里，然后刻板印刷。这里不但很多风
骚文人喜欢的诗词，还卖一些粗浅的功夫书，供城中居民练来强身健体。
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind1",
        ]));
        set("objects", ([
                __DIR__"npc/bookseller": 1,
        ]) );
        setup();
        replace_program(ROOM);

}
