
inherit ROOM;

void create()
{
        set("short", "闹市街");
        set("long", @LONG
街道并不宽，两边有各式各样的店铺，车马行人熙熙攘攘，茶楼酒店里笑语喧哗，
看看这些人，再看看这一片水晶玻璃世界，你几乎分不出这究竟是人间，还是天上？
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"street2",
  "west" : __DIR__"street",
  "north" : __DIR__"bar",
   "south" : __DIR__"shop",
]));
        set("outdoors", "laowu");

        setup();
        replace_program(ROOM);

}

