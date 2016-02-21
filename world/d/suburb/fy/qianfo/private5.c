//mac's private.c
#include <room.h>
#define MAX_STAFF 50 

inherit ROOM;

void create()
{
  set("short","私房");
  set("long",@LONG
     这是一所属于你的私房，东面墙上挂的是一个姓齐的画家画的虾米
     西面则是一幅奔马图，据称都属孤品。仅此就已经价值连城。更不
     用说这房间的摆设了。离开请通知领班。(ring)
LONG
  );
  setup();
}

void init()
{
   add_action("do_leave","ring");
}

int do_leave() 
{
  object *inv,env,me,*inv_con,env_con,mbox; 
  string data,data_con;
  int i,staff_count,j,con_count,item_count;

  con_count=0;
  staff_count=0;
  me=this_player();
  env=environment(me);
  inv=all_inventory(env);

  if(sizeof(inv)) {
    if(sizeof(inv)>MAX_STAFF)
       return notify_fail("你在房间里放了太多的东西，连门都打不开了。"); 
    for(i=0;i<sizeof(inv);i++){
     if(inv[i]->is_character());
     else{
      if(inv[i]->is_container())
       {
         item_count=0;
         env_con=present((string)inv[i]->query("id"),environment(me));
         inv_con=all_inventory(env_con);
         for(j=0;j<sizeof(inv_con);j++){
           if(inv_con[j]->is_character());
           else{ 
            data_con = base_name(inv_con[j])+".c";
            me->set("container"+sprintf("%d/%d",con_count,item_count),data_con);
            destruct(inv_con[j]);
            item_count=item_count+1;
            }       
          }
          con_count=con_count+1;
       }
      data=base_name(inv[i])+".c"; 
      me->set("homestaff/"+sprintf("%d",staff_count),data);
      destruct(inv[i]);
      staff_count=staff_count+1;
      }
    }
   }
   if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回领班. \n");
                destruct(mbox);
        }

   tell_object(me,"你摁铃招来领班\n
   “出门哪您？”领班毕恭毕敬的接过你手中的钥匙，恭送你出了大门。\n");  
   me->save();
   me->move("/open/mac/qianfo/shungeng.c");
   return 1;
 }
