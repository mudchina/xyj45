inherit ROOM;
// 
// 


void create()
{
        set("short", "万梅山庄");
        set("long", @LONG
在你面前是枝桠交叉的梅林，每当白雪皑皑之冬，遍山梅花
竟相开放。北风之中，雪花与红梅相映成辉，美不胜收。梅枝掩
映之中，风铃叮咚，忽隐忽现。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road2",
  "east" : __DIR__"gate",
]));
        set("outdoors", "wanmei");
        setup();
        replace_program(ROOM);
}
