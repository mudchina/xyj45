
inherit ROOM;

void create()
{
        set("short", "闹市");
        set("long", @LONG
市镇在冰上，在辉煌的灯火间，屋里的灯火和冰上的灯火交相辉映，一盏灯变成两
盏灯，两盏灯变成四盏灯，如满天星光闪烁，就算是京城里最热闹的街道也比不上。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"street",
  "southeast" : __DIR__"daroad",
]));
        set("outdoors", "laowu");
        set("objects", ([
        __DIR__"npc/beggar" : 2,
        __DIR__"npc/farmer" : 2,
        __DIR__"npc/drunk" : 2,
        __DIR__"npc/scavenger" : 2,
                        ]) );


        setup();
        replace_program(ROOM);

}

