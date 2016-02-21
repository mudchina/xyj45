
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地气极干燥，
连风都是暖的。地上的石砾发出一种暗红的颜色，就象是被鲜血染红的一样。
一条布满车痕的官道向西方和东方伸展。
LONG
        );
        set("exits", ([ 
  "northwest" : "/u/quicksand/desert2",
  "southeast" : __DIR__"road",
]));
        set("outdoors", "chenxiang");

        setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(5)){
this_player()->move(this_object());
return 1;
}
}


