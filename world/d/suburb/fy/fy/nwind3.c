inherit ROOM;
void create()
{
        set("short", "北风大街");
        set("long", @LONG
风街是风云城最热闹的两条街道之一。街道上人来人往，络绎不绝。街道两旁店
铺众多，生意兴隆。叫卖声、喝采声、和女人们的娇笑声，声声入耳。糕点的甜味儿，
酒菜的香味儿，和女人身上的花粉味儿，不时的穿鼻入脑，给人以目眩头晕的感觉。
大街西侧是浸龙澡堂，大街的东侧则是专门为千金小姐准备的浣凰堂。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind2",
  "north" : __DIR__"nwind4",
  "east" : __DIR__"hfeng",
  "west" : __DIR__"jlong",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
