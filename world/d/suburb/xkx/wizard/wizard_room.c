// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
	set("short", "巫师休息室");
	set("long", @LONG
这里就是「侠客行」巫师的休息所在，刚粉刷过的四周墙壁上光
秃秃的什么都没有，屋子的正中央放着一张楠木桌，上面摆着一本
巫师留言簿(board)。
LONG );

	set("exits", ([ /* sizeof() == 1 */
  	"down" : __DIR__"guest_room" ]));

	set("valid_startroom", 1);
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();

	call_other("/d/obj/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
