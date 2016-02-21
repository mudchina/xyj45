
inherit ROOM;

void create()
{
        set("short", "不醉无归小酒家");
        set("long", @LONG
小酒家几乎从不打烊，酒铺看起来不差，老板娘长得很不错，但不知为什么，里边冷
冷清清，看不见一个客人。一块“太白遗风”的木板招牌孤零零的在寒风中摇曳。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"street1",
]));

        set("objects", ([
        __DIR__"npc/dang" : 1,
                        ]) );
        setup();
        replace_program(ROOM);

}

