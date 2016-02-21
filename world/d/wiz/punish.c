// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /d/wiz/punish.c

inherit ROOM;

void create()
{
   set("short", "死牢");
   set("long", @LONG

进了这里，你活下来的希望已经很小了。
LONG
   );
   
   set("valid_startroom", 1);

   setup();
   
}

void init()
{   
   if (!wizardp(this_player())) {
          this_player()->set("startroom","/d/wiz/punish");
     this_player()->save();
     add_action("block_cmd","",1);      
   }
   call_out("hehe", 2, this_player());
}

int block_cmd()
{
        string verb = query_verb();
   
        if (verb=="say") return 0; //allow say
   if (verb=="help") return 0;
   if (verb=="look") return 0;
   return 1;
}
/*
// added by bula, just for fun.

void hehe()
{
        tell_room(environment(this_player()), "\n"+
     "隔壁的牢房里传来阵阵惨叫声！\n"+
     "你隐隐约约听到隔壁牢房里有人大喊：你招还是不招！\n"+
     "隔壁的牢房里传来阵阵皮鞭声！\n"+
     "你隐隐约约听到隔壁牢房里有人喊到：我们的政策是坦白从宽，抗拒从严！\n"+
     "你隐隐约约听到有人说话，可又听不大清楚！\n"+
     "隔壁的牢房里有人笑道：你早些招了，就不必吃这顿鞭子了！\n");
        return;
}

*/
