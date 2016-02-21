// inn.c

inherit ROOM;


void create()
{
	set("short", "千银当铺");
	set("long", @LONG
此当铺是南风大街对面的千金楼所设。以方便手头不宽的嫖客。千金楼的姑娘们
也经常光顾这里，典当或是卖掉客人们高兴之余所赏赐的小玩意儿。此当铺虽然是千
金楼所属，但却是童叟无欺。当铺挂有牌（ｓｉｇｎ）一块。
LONG
	);
	
	set("exits", ([
		"west"    	: __DIR__"swind4",
	]) );
        set("item_desc", ([
                "sign": @TEXT
这里是钱庄，目前我们提供的服务有：

pawn	    典当货物。
value       估价货物。
sell        卖断货物。
redeem      赎回货物。

TEXT
        ]) );


	set("objects", ([
		__DIR__"npc/hockowner" : 1,

			]) );


	setup();
}
