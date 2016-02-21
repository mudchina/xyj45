
inherit ROOM;

void create()
{
        set("short", "冰下水缸");
        set("long", @LONG
水缸冻在冰河里。两丈多高的水缸分成两层，下面一层铺满了柔软的皮毛，正是个
极舒服的床铺，从一个小小的梯子走到上面一层，就是饮食起居的地方了，里面居然有
桌有椅，四面都挂着厚厚的乱毡，还有个极精致的黄铜火炉。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"xiao",
]));
        set("objects", ([
        __DIR__"npc/lixia" : 1,
                        ]) );


        setup();
}

