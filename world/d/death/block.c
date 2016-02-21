// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/death/block.c
inherit ROOM;


void create ()
{
  set ("short", "死囚室"); 
  set ("long", @LONG
这是一间专门关闭被判处死刑或终身监禁者的房间。四周
墙壁皆由钢铁铸成，只有南边才有一个碗口大的小窗口。
LONG);

  set("valid_startroom",1);

  setup();
}

void init()
{
   if(!wizardp(this_player()))   {
      this_player()->set("startroom", "/d/death/block");
      add_action("block_cmd", "", 1);
   }   
}

int block_cmd(string args)
{
   string verb;
   string chat_msg;
   
   //chat_msg = "huogai " + this_player()->query("id");

   verb = query_verb();
   if(verb == "quit" || verb == "look") return 0;
   //if(verb == "chat*" && args == chat_msg) return 0;
   
   return 1;
}


