// /clone/board/towiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���������԰�", ({ "board" }) );
	set("location", "/d/suburb/xkx/wizard/guest_room");
	set("board_id", "towiz_b");
	set("long", "����һ������Һ���ʦ���������԰塣\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
