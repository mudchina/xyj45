// 
// 


inherit ROOM;
void create()
{
        set("short", "小山坡西面");
        set("long", @LONG
北面是风云城，天气好时隐隐约约地还可以看到风云城的黑色纶廓。
再向东则是一个光秃秃的小山坡，坡上已被路过的行人踏出了一条黄土
路。路的两边还长了一些半人高的焦黄茅草。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"sroad2",
  "north" : __DIR__"road0",
  "south" : "/d/suburb/fy/manglin/edge2",
]));
        set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        setup();
}

void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
	{
	item = new(__DIR__"obj/9whip");
	item->move(con);
	}	
}

