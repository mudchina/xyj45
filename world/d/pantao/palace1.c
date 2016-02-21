// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 5/23/1997
// room: /d/pantao/palace1.c

inherit ROOM;

void create ()
{
  set ("short", "天乾殿");
  set ("long", @LONG

                      ◇天乾殿◇

大殿金光万道红霓朦胧，瑞气千条紫雾缭绕。复道回廊，处处
玲珑剔透，三檐四簇，层层龙凤翱翔。两边镇天元帅，员员顶
梁靠柱，四下金甲神人，个个执戟悬鞭。殿中碧色琉璃台阶上
一座洁琼宝座玉光耀目，天神怡然高坐。

LONG);

  set("exits", ([
        "north"      : __DIR__"yaob",
        "south"      : __DIR__"palace2",
        "southwest"  : __DIR__"pan1c",  
        "southeast"  : __DIR__"pan1d",  
      ]));

  set("objects", ([
         __DIR__"npc/tian1"  : 1,
     ]));

  setup();
}

