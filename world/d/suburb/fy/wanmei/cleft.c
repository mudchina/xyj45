// 
// 

inherit ROOM;
void create()
{
        set("short", "左偏院");
        set("long", @LONG
院中种满了梅树幼苗。每棵都在茁壮成长，显然有人精心照顾。梅苗
之间还有人工开垦的小河沟，半尺深的渠水绕树而淌，灌溉着每一棵幼苗。
土壤黑而酥松，显然是饱含营养的肥土。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "梅树": "
你似乎可以砍（ｃｈｏｐ）几根下来。
                        \n",

        ]) );
        setup();
}
void init()
{
	add_action("do_chop","chop");
}
int do_chop()
{
object vege;
if((int) query("pulled") <= 10)
{
write("你砍了一棵梅树幼苗放在怀里。\n");
vege = new(__DIR__"obj/tree");
vege->move(this_player());
add("pulled",1);
}
else
        write("都被人砍光了！！\n");
return 1;
}

void reset()
{
:: reset();
delete("pulled");
}
