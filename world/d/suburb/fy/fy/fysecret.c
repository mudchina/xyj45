
inherit ROOM;

void create()
{
        set("short", "风云雅阁密室");
        set("long", @LONG
密室虽小，布置得很精致。四周陈列很是简单，只是一个个巴掌大的木像。每个木
像似乎都是同一个女人的样子，但是木像的面部全是空白，根本看不出木像是谁。房间
的左侧放着一张小床，床上躺着一个不断咳嗖，面目苍白的中年人。
LONG
        );
        set("exits", ([
                "south" : __DIR__"fyyage",
        ]));
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        set("objects", ([
                __DIR__"npc/lixunhuan": 1,
		__DIR__"obj/muou": 1,
        ]) );
        setup();
        replace_program(ROOM);
}
