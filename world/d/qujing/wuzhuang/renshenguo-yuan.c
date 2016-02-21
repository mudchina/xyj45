// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
   set ("short", "人参果园");
   set ("long", @LONG

好大的一遍人参果园！巨大的果树上吊着一枚枚令人垂涎欲滴的
人参果。只是不知道怎样才能弄将下来。据说这人参果娇贵无比，
要是乱摘一气什么都吃不上。
LONG);

   set("exits", 
   ([ //sizeof() == 4
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
   ]));

   set("outdoors", "wuzhuang");

   setup();
}

void init()
{
   object me, zhenyuan;

   me = this_player();

   if( me->query_temp("used_huangtong_key") == 1 )
   {
     me->delete_temp("used_huangtong_key");
     
     message_vision("只听几声哈哈大笑，镇元大仙走了出来。\n", me);
     message_vision("镇元大仙说道：居然被你发现了。那我们就开个人参果大会吧！\n\n\n", me);

     if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
     {//if zhenyuan already here, we do not need creat another one.
        zhenyuan = new(__DIR__"npc/zhenyuan");
        zhenyuan->move(environment(me));
     }
     zhenyuan->start_renshen();
   }
}

