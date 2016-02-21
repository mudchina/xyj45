// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// gao.c

inherit NPC;
void create()
{
       set_name("高员外", ({"gao yuanwai", "gao"}));

set("long","高家庄的主人，吃的胖乎乎的．\n按说大财主应该乐呵呵地，他却愁眉苦脸，象是遇到了什么难事．\n");
       set("gender", "男性");
       set("age", 46);
       set("title", "庄主");
       set("attitude", "peaceful");
       set("shen_type", 1);
   set("combat_exp", 5000);
        set_skill("unarmed", 15);
   set_skill("dodge", 30);
   set_skill("parry", 15);
set("inquiry", ([
"name": "老夫姓高，乃是家中的主人．\n",
"here": "高老庄是也．\n",
]) );

   setup();
       add_money("silver", 3+random(5));
   carry_object("/d/ourhome/obj/choupao")->wear();
}
int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="mmmmmm") {
                say("高庄主笑道：多谢"  + RANK_D->query_respect(who) +
"，老夫这厢有礼了．\n高庄主说道：这是以前一名高士留下的，也许对您有用．\n");
   m=new("/d/gao/obj/pa_book");
        m->move(who);
   call_out("destroy", 1, ob);
   return 1;
        }
   else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

