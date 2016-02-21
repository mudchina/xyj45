inherit ROOM;
void create()
{
        set("short", "红屋");
        set("long", @LONG
这是西城区唯一比较像样的建筑，但颜色很怪，一种血色干凝的暗红色。屋里更是
鬼气森森。房子无窗，一盏油灯忽明忽暗。以太极八卦图为底的招牌上用篆体刻着四
个字“生死已卜”，也是黯淡无光的红色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud3",
]));
        set("objects", ([
        __DIR__"npc/dashi" : 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
