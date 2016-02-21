// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//changan city

inherit ROOM;

void create ()
{
        set ("short", "长安武馆");
        set ("long", @LONG

你现在正站在一个长安武馆的教练场中，地上铺着黄色的细砂，一群
二十来岁的年轻人正在这里努力地操练着, 还有一个中年汉子在不停
的喊着号子，让人振奋。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"xuanwu-n2",
     "east" : __DIR__"wuguanzhong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/dizi" : 4,
     __DIR__"npc/jiaotou" : 1,
        ]));


        set("outdoors", "changan");
   set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_skills", "skills");
}

int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
        if(!(ob = present("fan luping", environment(me))))
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        if ( (arg != "fan") )
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        else
write("
范芦平目前所学过的技能：

  基本轻功 (dodge)                         - 驾轻就熟  30/    0
  内功心法 (force)                         - 驾轻就熟  30/    0
  拆招卸力之法 (parry)                     - 驾轻就熟  30/    0
  扑击格斗之技 (unarmed)                   - 马马虎虎  30/    0

\n");
                return 1;
}

