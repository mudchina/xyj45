inherit ROOM;
void create()
{
        set("short", "银钩赌坊大厅");
        set("long", @LONG
一眼看过去，这大厅里真是金碧辉煌，堂皇富丽，连烛台都是纯银的，在这种
地方输了千儿八百两金子，没人会觉得冤枉。大厅里摆满了大大小小的赌桌，只要
能说出名堂的赌具，这里都有。有匾（ｓｉｇｎ）一块。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"pianting",
  "east" : __DIR__"yingou",
]));
        set("item_desc", ([
                "sign": @TEXT


骰子的赌法：

ｂｅｔ　＜种类＞　＜银量＞

种类：　０，１，２，３到１８
０：　		赌小	（３－１０）	一赔一
１：  		赌大	（１１－１８）	一赔一
２：　		赌围骰	（三粒骰子同点）一赔三十六
３－１８	赌单点  		一赔八

例子：
ｂｅｔ　０　５０
赌五十两在小上

TEXT
        ]) );

        set("objects", ([
        __DIR__"npc/dice_thrower" : 1,
	__DIR__"obj/stealingbook" : 1,
                        ]) );
	set("NONPC",1);
        setup();
}
void init()
{
object me;
me = this_player();
if( me->query("gamble/amount")) {
me->delete("gamble/amount");
me->decrease_skill("betting",1);
}
}
