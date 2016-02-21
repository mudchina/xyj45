inherit ROOM;
void create()
{
        set("short", "镂金扶梯");
        set("long", @LONG
扶梯宽一丈，大红金毯铺开，左右扶手镶金镂银，盘旋而上。细观铺梯红毯，金
丝纵横，隐约钩出一幅云雨交欢图。阵阵娇笑之声从楼上传来，不时还加杂着一两声
令人血脉偾张的呻吟。你不由自主的加快了步伐。。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"stairs",
  "southup" : __DIR__"secfloor",
]));

        setup();
        replace_program(ROOM);
}
