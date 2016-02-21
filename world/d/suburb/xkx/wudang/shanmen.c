// shanmen.c 武当山门
// by Xiang

inherit ROOM;

void create()
{
	set("short", "武当山门");
	set("long", @LONG
	你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条石
阶向山上延伸，走着几个进香客。石壁上写着“武当山”三个大字，原来这就是
天下闻名的武当山。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad8",
		"westup" : __DIR__"shijie1",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));
	setup();
	replace_program(ROOM);
}

