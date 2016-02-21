
inherit ROOM;

void create()
{
        set("short", "拉哈苏");
        set("long", @LONG
“拉哈苏”就在松花江之南，这三个字的意思就是“老屋”，它的名字虽然充满
了甜蜜和亲切，其实却是个荒僻而寒冷的地方，每到重阳前后，就开始封江，直到第
二年的清明才解冻。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"town",
  "south" : __DIR__"road5",
]));
        set("outdoors", "laowu");

        setup();
        replace_program(ROOM);

}

