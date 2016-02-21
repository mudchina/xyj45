// Room: /city/shuyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
	这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师
椅上讲学，那就是当今大儒朱先生了。在他的两侧坐满了求学的学生。一张古意盎
然的书案放在朱先生的前面，案上摆着几本翻开了的线装书籍。朱先生的身后是一
个书架(shujia)讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在
讲堂前左壁的学规(xuegui)。
LONG
	);

	set("exits", ([
		"south" : __DIR__"dongdajie1",
	]));

	set("item_desc", ([
		"xuegui" : "日讲经书三起，日看纲目数页。"  
			"\n通晓时务物理，参读古文诗赋。" 
			"\n读书必须过笔，会课按时蚤完。"
			"\n夜读仍戒晏起，疑误定要力争。\n\n"
			"求学需缴学费十两\n",
	]));
	
	set("objects", ([
		__DIR__"npc/zhu": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/朱", 0);
	return 1;
}

