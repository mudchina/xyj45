// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// bboard.c

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void setup()
{
   string loc;

   if( stringp(loc = query("location")) )
     move(loc);
   set("no_get", 1);
   seteuid(getuid());
   restore();
}

void init()
{
    if(this_player()->visible(this_object())) {
   add_action("do_post", "post");
   add_action("do_read", "read");
   add_action("do_discard", "discard");
   add_action("do_document", "document");
    }
}

string query_save_file()
{
   string id;

   if( !stringp(id = query("board_id")) ) return 0;
   return DATA_DIR + "board/" + id;
}

string short()
{
   mapping *notes;
   int i, unread, last_read_time;

   notes = query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
     return ::short() + " [ 没有任何留言 ]";

   if( this_player() ) {
     last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
     for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
        if( notes[i]["time"] <= last_read_time ) break;
   }
   if( unread )
     return sprintf("%s [ %d 张留言，%d 张未读 ]", ::short(), sizeof(notes), unread);
   else
     return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
   mapping *notes;
   int i, last_time_read;
   string msg, myid;

   notes = query("notes");
   msg = query("long");
   msg = msg + "留言版的使用方法请见 help board。\n";
   if( !pointerp(notes) || !sizeof(notes) ) return query("long");

   last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
   for(i=sizeof(notes)-1; i>=0; i--)
     msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
        ( notes[i]["time"] > last_time_read ? HIY: ""),
        i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
   return msg;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
   mapping *notes;

   note["msg"] = text;
   note["time"] = time();
   notes = query("notes");
   if( !pointerp(notes) || !sizeof(notes) )
     notes = ({ note });
   else
     notes += ({ note });

   // Truncate the notes if maximum capacity exceeded.
   if( sizeof(notes) > BOARD_CAPACITY )
     notes = notes[BOARD_CAPACITY / 5 .. BOARD_CAPACITY];

   set("notes", notes);
   tell_object(me, "留言完毕。\n");

   save();
   return;
}

int do_post(string arg)
{
   mapping note;
    object me;

   me = this_player();
   if(!wizardp(me) && environment(me)->query("post_limit"))
      return notify_fail("只有巫师才可以在这里留言。\n");

   if(!arg) return notify_fail("留言请指定一个标题。\n");
   
   note = allocate_mapping(4);
   note["title"] = arg;
   note["author"] = this_player()->query("name")+
    "("+capitalize(this_player()->query("id"))+")";
//   note["time"] = time();
   this_player()->edit( (: done_post, this_player(), note :) );
   return 1;
}

int do_read(string arg)
{
   int num;
   mapping *notes, last_read_time;
   string myid;

   last_read_time = this_player()->query("board_last_read");
   myid = query("board_id");
   notes = query("notes");

   if( !pointerp(notes) || !sizeof(notes) )
     return notify_fail("留言板上目前没有任何留言。\n");

   if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
   if( arg=="new" || arg=="next" ) {
     if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
        num = 1;
     else
        for(num = 1; num<=sizeof(notes); num++)
          if( notes[num-1]["time"] > last_read_time[myid] ) break;
        
   } else if( !sscanf(arg, "%d", num) )
     return notify_fail("你要读第几张留言？\n");

   if( num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;
   this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
     num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
     + notes[num]["msg"] );

   // Keep track which post we were reading last time.
   if( !mapp(last_read_time) )
     this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
   else 
     if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
        last_read_time[myid] = notes[num]["time"];

   return 1;
}


int do_discard(string arg)
{
   mapping *notes;
   int num;

   if( !arg || sscanf(arg, "%d", num)!=1 )
     return notify_fail("指令格式：discard <留言编号>\n");
   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;
   if( notes[num]["author"] != 
     (string) this_player(1)->query("name")+
     "("+capitalize(this_player(1)->query("id"))+")"
&& (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
   &&   (string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
     return notify_fail("这个留言不是你写的。\n");

   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
   set("notes", notes);
   save();
   write("删除第 " + (num+1) + " 号留言....Ok。\n");
   return 1;
}


int do_document(string arg)
{
        object document, content, cont_num;
   string mon, dirname="/data/";
   int month, num, nummonth, defmon, defyear, argn;
        mapping *notes;
   string *strmon=({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

   if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
    && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" 
    && (string)SECURITY_D->get_status(this_player(1)) !="(wizard)" )
     return notify_fail("你没有存档的权力！\n");

//by mon. 9/6/97
        if(environment(this_player())->query("wiz_board"))
     dirname+="wiz_doc/";
        else
     dirname+="doc/";

   argn=sscanf(arg, "%d %d %d", num, defmon, defyear);

        if(!arg || argn >3)
                return notify_fail("指令格式：document <留言编号>\n");

   if (argn==3) {
     dirname = dirname + sprintf("%d",defyear)+"/";
     month=defmon;
     mon="Null";
     }
   if (argn==2) {
     if (defmon>1995) {
        dirname = dirname + sprintf("%d",defmon)+"/";    
        mon=ctime(time())[4..6];
        }
     else {
        dirname = dirname + ctime(time())[20..23] + "/";
        month=defmon;
        mon="Null";
        }
     }
   if (argn==1) {
     dirname = dirname + ctime(time())[20..23] + "/";
     mon=ctime(time())[4..6];
     }
   if ( mon=="Null" ) {
     if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");
     mon=strmon[month-1];
     }
   else switch (mon) {
     case "Jan": month=1; break;
                case "Feb": month=2; break;
                case "Mar": month=3; break;
                case "Apr": month=4; break;
                case "May": month=5; break;
                case "Jun": month=6; break;
                case "Jul": month=7; break;
                case "Aug": month=8; break;
                case "Sep": month=9; break;
                case "Oct": month=10; break;
                case "Nov": month=11; break;
                case "Dec": month=12; break;
     }

   if (month>12 || month<1) return notify_fail("要存的月份不存在！\n");


   notes = query("notes");
   if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
     return notify_fail("没有这张留言。\n");
   num--;

   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
        cont_num->restore();

   if (!objectp(cont_num) )
                return notify_fail("文档读取失败！\n");
   nummonth=cont_num->query(mon);
   nummonth++;
   cont_num->set(mon, nummonth);
   if (!cont_num->save())
     return notify_fail("存档失败！\n");

   content=new("/obj/not.c");
   content->set("file_name", dirname+"content."+mon);
   content->restore();
   if ( !objectp(content) )
     return notify_fail("文档读取失败！\n");
   if (content->query("msg")) content->set("msg", content->query("msg")+ 
sprintf("[%3d] %-40s %12s (%s)\n",
nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
);
   else content->set("msg", sprintf("[%3d] %-40s %12s (%s)\n",nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9]));

   if (!content->save())
                return notify_fail("存档失败！\n");

   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon,month, nummonth) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("文档读取失败！");
   document->set("msg",
sprintf("[%3d] %-40s %12s (%s)\n--------------------------------------------------------------------------------\n", nummonth, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
+ notes[num]["msg"]
);
   if (!document->save())
     return notify_fail("存档失败！\n");
   write("OK.\n");
   
/*
   if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
        set("notes", notes);
        save();
*/
   return 1;
}   
