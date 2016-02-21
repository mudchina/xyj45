// 
// 

inherit ROOM;
void create()
{
        set("short", "万梅瀑布");
        set("long", @LONG
瀑布从百丈悬崖直泻而下，如万马齐奔，带着千斤之力坠入湖中，激起千层
巨浪。白色的泡沫被冲入湖底，久久不起。瀑布边的岩石被冲得光洁如镜，滑不
留手。瀑布直泻入湖处有一巨石，石形似有一人正在打坐。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lake",
]));
        set("item_desc", ([
                "巨石": "
这巨石上似乎又个脚印，你也需可以借一踏之力（ｃｈａｒｇｅ）冲向瀑布．\n",
        ]) );
	set("outdoors","wanmei");
        setup();
}
void init()
{
	add_action("do_charge","charge");
}

int do_charge()
{
	object me,room;
	me = this_player();
	message_vision("$N集起全身力量，向瀑布冲去．．．\n",me);
	if((int) me->query("max_force") < 300 )
	{
	message_vision("万马齐奔，带着千斤之力的瀑布将$N砸入湖底，转眼就被冲走了．．\n",me);
	room = load_object(__DIR__"river");
        me->move(room);
	return 1;
	}
	message_vision("$N身形居然穿过了急流！\n",me);
	room = load_object(__DIR__"outcave");
	me->move(room);
	return 1;
}
