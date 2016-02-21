inherit ROOM;
void create()
{
        set("short", "断桥踏板");
        set("long", @LONG
在你面前是一条巨大的双层木船。船上有桅无帆，显然是长年停泊在这里。船
上灯火通明，人生鼎沸。微风吹过，细滔拍舷，发出有节奏的“啪啪”声。船身也
随之微起微伏。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lastbridge",
  "west" : __DIR__"boat",
]));
	set("outdoors","fengyun");
        setup();
        replace_program(ROOM);
}
