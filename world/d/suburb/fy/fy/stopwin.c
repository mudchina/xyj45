
inherit ROOM;

void create()
{
        set("short", "镇风兵器铺");
        set("long", @LONG
此铺的大老板乃是金狮镖局的总镖头，大掌柜则是大镖头诸葛雷。十八般外门
兵器，这里应有尽有。四周的墙上还陈列着百晓生兵器谱上赫赫有名的人物赖以成
名的奇门兵器。
LONG
        );
        set("exits", ([
		"east" : __DIR__"nwind4",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer": 1,
        ]) );
        setup();
        replace_program(ROOM);

}

