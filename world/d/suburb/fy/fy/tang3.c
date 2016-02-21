inherit ROOM;
void create()
{
        set("short", "化尸堂");
        set("long", @LONG
金钱帮已经买通官府，官府对金钱帮的所作所为大都视而不见。但金钱帮仇家众多，
为铲除异己而双手血腥。此处正是焚烧罪状和尸体的大堂。两人高的青铜炉火焰正盛。
一股焦尸的恶臭弥漫了整个大厅（ｂｕｒｎ）。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jhuang",
]));
        setup();
}

void init()
{

	add_action("do_burn","burn");

}

int do_burn(string arg)
{
	object me;
	object tar;
	int score, pot;
	me = this_player();
	score = (int) me->query("combat_exp");
	pot = (int) me->query("potential");
	if( !arg || arg == "") 
                return notify_fail("你烧啥东西．\n");
	tar = present(arg, me);
	if( !tar) 
		return notify_fail("你身上没有这东西．\n");
	if( userp(tar))
		return notify_fail("你不可烧活的东西．\n");
	if( tar->query("owner"))
		return notify_fail("你不可烧订的东西．\n");
	if( tar->is_corpse())		
	{
		me->set("combat_exp", (int) score + 1);
		me->set("potential", (int) pot + 1);
	}
	message_vision("$N将$n投入了青铜炉，$n转眼化为灰烬．\n", me, tar);
	tar->move(environment(me));
	destruct(tar);
	return 1;
}
