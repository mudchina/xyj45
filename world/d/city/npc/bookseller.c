// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// 孔方兄, bookseller.
// 5-3-97, pickle

inherit F_VENDOR_SALE;

void create()
{
    reload("city_kongfang");
  set_name("孔方兄", ({ "kong fang", "kongfang", "kong", "fang", "bookseller", "seller", "vendor" }) );
  set("shop_id",({"kongfang","kong","fang","bookseller","seller"}));
  set("gender", "男性" );
  set("age", 37);
  set("title", "书店老板");
  set("long","孔秀才入京赶考落第，盘缠用尽，无法还乡，\n不得已在长安开一家书店。传说他曾遇异人，\n学得一些防身之术。\n");
  set("combat_exp", 40000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("unarmed", 50);
  set_skill("literate", 70);
  set("attitude", "friendly");
  set("rank_info/respect", "孔秀才");
  set("per",25);
  set("vendor_goods", ([
//    "xiji": "/d/obj/books-nonskill/xiji",
//    "fuji": "/d/obj/books-nonskill/fuji",
//    "kunlun": "/d/obj/books-nonskill/kunlun",
    "san": "/d/obj/book/san",
    "blade-book" : "/d/obj/book/basic_blade",
    "unarmed-book": "/d/obj/book/basic_unarmed",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say 这位" + RANK_D->query_respect(ob) +"请进请进。");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
   if (npc->query_temp(st)<10)
     {
     //  npc->add_temp(st,1);
         // limit needed only for non-skills books
         return ::buy_object(who,item);
     }
   else
     {
       return notify_fail(name()+"说道：对不起，您老要的书卖完了！您等下一批进货吧。\n");
     }
   //npc->add_temp("total_books", 1);
      }
      else
      {
   return notify_fail(name()+"说道：小店本小，今日以将存货卖完了。您老等下一批吧。\n");
      }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

