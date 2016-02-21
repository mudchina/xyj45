
inherit ROOM;

void create()
{
        set("short", "冰上之镇");
        set("long", @LONG
在封江的前几天，老屋的居民把早已准备好的木架抛入松花江中，用绳子牢牢系住，
封江后，浮在江面上的木架冻得生了根。再上梁加橼，铺砖盖瓦，于是一幢幢大大小小，
各式各样的房子，就在江上盖了起来。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"town",
]));
        set("outdoors", "laowu");
       set("objects", ([
        __DIR__"npc/guan" : 1,
                        ]) );


        setup();
        replace_program(ROOM);

}

