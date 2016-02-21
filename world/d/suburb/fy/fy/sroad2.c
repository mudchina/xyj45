// 
// 


inherit ROOM;
void create()
{
        set("short", "小山坡顶");
        set("long", @LONG
山坡虽不高，但也可以把南面的岱庙镇和北面的风云城尽收眼底。占
地几百顷的风云城一眼望不到边际，整个城都向远方铺展，隐于大地的交
界处。东面的岱庙镇相比之下则显得荒漠的可怜。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"sroad1",
]));
        set("objects", ([
        __DIR__"npc/shiren": 1,
                        ]) );
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
