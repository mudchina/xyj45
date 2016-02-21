inherit ROOM;
void create()
{
        set("short", "考场");
        set("long", @LONG
凡是有志于宦途的风云年青人都要在这里通过第一次考试。文武双全的前三名会被
送入京都再试。每到一年一度的考季，这里就会人山人海，看热闹的比参考的还多。风
云的老一辈大多是望子成龙，所以风云城每年都是人才辈出。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/kaoguan" : 1,
	__DIR__"npc/student" : 3,
                        ]) );

        setup();
}
