// 
// 

inherit ROOM;
void create()
{
        set("short", "小河流上游");
        set("long", @LONG
这里的河床较宽，水流缓慢。河边的芦苇随风起伏荡漾，发出沙沙的声音，
偶尔还夹杂着野鸭的嘎嘎声。河边有几条依稀的小径蜿蜒地伸向远方，几块嶙
峋的怪石耸立在小径旁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle",
  "south" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        setup();
        replace_program(ROOM);
}
