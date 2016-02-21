inherit ROOM;
void create()
{
  set("short","阳关大道");
  set("long",@LONG
这是一条东西大道，笔直宽阔，道旁是绿油油的麦田，向南可以隐
约看到风云城的城门，向北是济河渡口，西边有一片果林，东边是一座
山。这已是山东地界。
LONG
  );
  set("exits",([
         "west" :"/d/suburb/fy/laowu/road1",
         "east" :__DIR__"shanjiao",
               ]));

        set("outdoors", "qianfo");
  setup();
  replace_program(ROOM);
}

