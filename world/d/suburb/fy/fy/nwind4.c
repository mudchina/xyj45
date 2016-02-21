inherit ROOM;
void create()
{
        set("short", "北风大街");
        set("long", @LONG
风街是风云城最热闹的两条街道之一。街道上人来人往，络绎不绝。街道两旁店
铺众多，生意兴隆。叫卖声、喝采声、和女人们的娇笑声，声声入耳。糕点的甜味儿，
酒菜的香味儿，和女人身上的花粉味儿，不时的穿鼻入脑，给人以目眩头晕的感觉。
在西侧的镇风兵器铺和东边的金狮镖局遥遥相望。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind3",
  "north" : __DIR__"nwind5",
  "east" : __DIR__"goldlion",
  "west" : __DIR__"stopwin",
]));
        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/dtz": 5,
                        ]) );
        setup();
        replace_program(ROOM);
}
