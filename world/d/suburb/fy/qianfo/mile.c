// 
// 

#include <room.h>
inherit ROOM;
void create()
{
  set("short","弥勒殿");
  set("long",@LONG
弥勒佛为五代僧，名契此，体躯肥满，言语无恒，以杖负布袋立
于莲花座上，面现喜悦之相。无著，天亲二菩萨随伺左右。
LONG
  );
  set("exits",([
            "south":__DIR__"tianwang.c",
//            "north":__DIR__"weituo.c",
            "west" :__DIR__"fatang.c",
            "east" :__DIR__"chantang.c"
               ]));
        set("item_desc", ([
                "弥勒佛": "
                        弥勒佛看起来一直在笑，笑，笑．．．\n",
                "milefe": "
                        弥勒佛看起来一直在笑，笑，笑．．．\n"

        ]) );
  setup();
}
void init()
{
add_action("do_smile","smile");

}
int closepath()
{
        if( !query("exits/north") ) return 1;
        message("vision",
"北面墙上的暗门又无声无息的合上了。\n",
                this_object());
             delete("exits/north");
	return 1;
}
int do_smile()
{
	add("num",1);
	if(!((int) query("num") % 5))
		if( !query("exits/north"))
		{
			set("exits/north",__DIR__"weituo");
			message("vision",
"弥勒佛似乎也和你一起笑了起来．．＂嗑碴＂一声，北面的墙上裂出了一个暗门。\n",
			this_object());
			call_out("closepath",4);
			return 1;
		}
		return 0;
		
}
void reset()
{
::reset();
delete("num");
}
