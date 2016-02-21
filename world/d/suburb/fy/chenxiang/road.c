
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，山势到了这里突然间变的叠叠起起。
再往西北方向则是去大沙漠的小路，往东北方向则是去泰山的必
经之路岱庙坊。岱庙坊现由西方神教所控。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"roadp",
  "southup" : __DIR__"chenxiang3",
  "northeast" : "/d/suburb/fy/daimiao/yaocan",
]));
        set("outdoors", "chenxiang");

        setup();
        replace_program(ROOM);
}

