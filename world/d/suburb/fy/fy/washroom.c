
// 
// 


inherit ROOM;

void create()
{
        set("short", "洗衣店");
        set("long", @LONG
这是一间洗衣店，这里是有钱人将衣服拿来浆洗的地方。这里的老板是一
个上了年纪的老太婆，孤身一人，无儿无女，仅靠这洗衣店微薄的收入维持生
活。门口有一个大木牌（ｓｉｇｎ）。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ecloud3",
]));

        set("item_desc", ([
                "sign": @TEXT

现在正紧缺人手，急需雇佣一批短工来干活。
ｗｏｒｋ　开始工作。
TEXT
        ]) );
        set("objects", ([
        __DIR__"npc/taipo" : 1,
                        ]) );
    set("no_fight", 1);
    set("no_magic", 1);
    set("NONPC",1);
        setup();
        replace_program(ROOM);
}

