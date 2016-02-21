// sexliterate.c 性文学房间

string look_shelf();

#define STORY_TOC   "/doc/story/toc"
#define STORY_DIR "/doc/story/"
inherit ROOM;

void create()
{
	set("short", "性文学图书馆");
	set("long", @LONG
	这是一间极为隐蔽的图书收藏室。你可以用 read 来阅读一些书架 (shelf)
上的黄色小说。
LONG
	);
        set("item_desc", ([
                "shelf" : (: look_shelf :),
        ]));

	set("exits", ([
		"south" : __DIR__"lichunyuan",
	]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(STORY_TOC));
        return "\n";
}

int do_read(string arg)
{
        if (arg == "" || file_size(STORY_DIR + arg) <= 0)
                return notify_fail("我们没有这本书。\n");

	switch (MONEY_D->player_pay(this_player(), 20000)) {
	        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
	        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	}
	log_file("LIBRARY", sprintf("%s read %s.\n", this_player()->query("name"), arg));
	this_player()->start_more(read_file(STORY_DIR + arg));
	return 1;
}
