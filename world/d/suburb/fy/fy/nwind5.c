inherit ROOM;
void create()
{
        set("short", "北风大街");
        set("long", @LONG
风街在这里渐渐变窄，街道两旁的店铺群立而又参差不齐。街的东边是一所小
小的城隍庙，庙门破旧不堪。门上依稀的用木炭涂着一支手，这只手里似乎抓着十
三支短箭。据说这里晚上常有鬼魂的出现。街的西边则是一家包子店。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nwind4",
  "north" : __DIR__"ngate",
  "east" : __DIR__"hiretem",
  "west" : __DIR__"baozipu",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
