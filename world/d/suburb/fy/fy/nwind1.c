inherit ROOM;
void create()
{
        set("short", "北风大街");
        set("long", @LONG
风街是风云城最热闹的两条街道之一。街道上人来人往，络绎不绝。街道两旁店
铺众多，生意兴隆。叫卖声、喝采声、和女人们的娇笑声，声声入耳。糕点的甜味儿，
酒菜的香味儿，和女人身上的花粉味儿，不时的穿鼻入脑，给人以目眩头晕的感觉。
大街的东侧是风云城中最贵的酒楼—风云阁，大街的西侧则是警世书局。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fysquare",
  "north" : __DIR__"nwind2",
  "east" : __DIR__"fyge",
  "west" : __DIR__"jssju",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/zhu": 1,
                        ]) );

        setup();
        replace_program(ROOM);
}
