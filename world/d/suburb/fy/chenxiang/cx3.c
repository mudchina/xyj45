// 
// 

inherit ROOM;
void create()
{
        set("short", "沉香镇北街");
        set("long", @LONG
街道由暗青色的石砖铺成。沉香镇的大部分房屋都是用这种石砖堆砌
的。街道不宽都刚好可以让一辆四轮马车通过。西面是一家小小的中药店。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"cx2",
  "southeast" : __DIR__"cx4",
  "west" : __DIR__"yao",
]));
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
