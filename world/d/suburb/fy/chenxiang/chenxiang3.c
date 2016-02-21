// 
// 


inherit ROOM;
void create()
{
        set("short", "绿山坡");
        set("long", @LONG
在这里似乎可以闻到烟雨江南的味道。不远处的沉香镇就和江南的
大部分东西一样，小而精致可爱。在破晓前后，天空是灰色的，云层也
是灰色的，把整个沉香小镇全部溶入了这一片灰潆。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"road",
  "southwest" : __DIR__"cx1",
]));
        set("outdoors", "chenxiang");
        setup();
        replace_program(ROOM);
}
