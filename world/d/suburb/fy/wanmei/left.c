// 
// 

inherit ROOM;
void create()
{
        set("short", "左弄堂");
        set("long", @LONG
一边的墙上布满了蔓藤，点缀着小花，密而不高。刚好使阳光
透过窗口射入枯梅堂。地下铺的是上好的红砖，被砖缝里一丝丝青
苔衬托着分外好看。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"frontyard",
  "southeast" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/cat": 1,
	__DIR__"npc/ass": 2,
                        ]) );

        setup();
        replace_program(ROOM);
}
