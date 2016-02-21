// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan4.c

inherit ROOM;

void create ()
{
  set ("short", "碗子山");
  set ("long", @LONG

山上黄土龟裂岩石层层，参差不奇地长着一些树林灌木。路从岩
石周围绕道铺设盘山而行，迂回曲折。四处风吹草动，空谷回音。
令人恍然不知所处。

LONG);

  set("exits", ([
        "northdown"  : __DIR__"shanwan2",
        "northeast"  : __DIR__"shan3",
        "southeast"  : __DIR__"shan6",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

