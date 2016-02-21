//m_weapon .....tianjianshi.c
//xuanbing.c

inherit ROOM;

void create()
{
	set("short", "玄兵古洞");
	set("long",
		"这里是玄兵古洞，四面洞壁之上结满了石英的柱状结晶体，显得\n"
		"十分漂亮。前方一个巨大的炉子前站着一位长髯老者正看着炉火想着\n"
		"什么心事，旁边几个彪形大汉正挥舞着锤头敲打着一块似乎总也烧不\n"
		"红的什么金属。旁边仔细的放着几把刚刚出炉的兵器。那种骇人的杀\n"
		"气竟是从这些兵器上散发出来的。\n"

	);
	set("exits", ([
		"out" : __DIR__"xuanbing",
	]));
        set("objects" , ([
               __DIR__"npc/tianjianshi" : 1,

             ]) );
	setup();
	replace_program(ROOM);
}
