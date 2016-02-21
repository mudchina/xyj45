inherit ROOM;
void create()
{
        set("short", "恩怨堂");
        set("long", @LONG
堂正中檀木香案，案上燃着几炷香，整间屋檀香袅袅。凡是入此堂的人，都愿把
以往恩怨一笔勾消。如果你有愧你的所作所为，想从新作人，忘记已往的恩恩怨怨，
只需在这里跪下（ＫＮＥＥＬ）。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jhuang",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        setup();
}

void init()
{
	add_action("do_kneel", "kneel");
}

int do_kneel()
{
	this_player()->remove_all_killer();
	message_vision("$N跪倒在地，决定忘记以前所有的仇家．\n",this_player());
	return 1;

}
