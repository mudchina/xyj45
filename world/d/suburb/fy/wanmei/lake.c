// 
// 

inherit ROOM;
void create()
{
        set("short", "山中巨湖");
        set("long", @LONG
湖水清澈见底，暗绿色的水草随波摇摆。尾尾小鱼缓缓游动，穿梭在水草
之间。一席瀑布泻入湖中，发出隆隆之声，回荡于群山，震耳欲聋。小湖又延
伸出来，形成一条小溪，流向山下。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jungle",
  "east" : __DIR__"waterfall",
]));
	set("outdoors","wanmei");
        setup();
        replace_program(ROOM);
}
