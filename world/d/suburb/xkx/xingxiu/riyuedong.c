// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "日月洞");
        set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上端坐着
星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。
洞两侧竖立兵器架，上面排列的大多是各种棍棒。
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
"
        ]) );

        set("objects", ([
                "/daemon/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiegun" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);

}

