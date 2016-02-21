// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("武当弟子留言板", ({ "board" }) );
	set("location", "/d/suburb/xkx/wudang/sanqingdian");
	set("board_id", "wudang_b");
	set("long", "这是一个供武当门下交留的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

