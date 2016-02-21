
inherit ROOM;

void create()
{
        set("short", "水晶大道");
        set("long", @LONG
封江后，河面冻成了一条又长又宽的水晶大道。当黄昏来临，光采已黯淡的大道
上一盏盏的灯火相继燃起，灯火照在冰上，冰上的灯火反照，房子看起来就象是一栋
栋水晶宫殿。无论谁第一次看到这种景象，都一定会目眩情迷，心动神驰。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"downtown",
  "south" : __DIR__"town",
]));
        set("outdoors", "laowu");

        setup();
        replace_program(ROOM);

}

