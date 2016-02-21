// иЯ╩╟йю╫Г║╓нВсн╪г║╓╟Ф╠╬ё╢ё╝ё╣ё╟
/* <SecCrypt CPL V3R05> */
 
// zhangchu.c уфЁЬи╝╨
// By Dream Dec. 20, 1996

inherit NPC;
string ask_yao(object who);
string ask_dan(object who);

void create()
{
   set_name("уфЁЬи╝", ({ "zhangchu seng", "seng" }));
   set("gender", "дппт");
   set("age", 25);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 200);
   set("max_gin", 200);
   set("max_sen", 200);
   set("force", 100);
   set("max_force", 100);
   set("force_factor", 10);
   set("max_mana", 100);
   set("mana", 100);
   set("mana_factor", 10);
   set("combat_exp", 5000);
   set_skill("literate", 20);
   set_skill("unarmed", 25);
   set_skill("dodge", 20);
   set_skill("parry", 25);
   set_skill("force", 10);
   set_skill("spells", 10);
   set_skill("buddhism", 10);
   set_skill("unarmed", 30);
   map_skill("spells", "buddhism");
//   set("chat_chance_combat", 80);
//   set("chat_msg_combat", ({
//     (: cast_spell, "thunder" :),
//   }) );

   set("inquiry", ([
     "тфдо╟вр╘": (: ask_yao :),
     "аИ╣╓": (: ask_dan :),
   ]) );
        set("apply/yaono", 10);
        set("apply/danno", 10);

        create_family("до╨ёфумси╫", 4, "╣эвс");
   
   setup();
   add_money("silver", 20);
   carry_object("/d/nanhai/obj/sengpao")->wear();
}

string ask_yao(object me)
{
   object ob, who = this_player();
   int number;

        if (who->query("family/family_name") != "до╨ёфумси╫") 
     return RANK_D->query_respect(who) +"сК╠╬це╨анчт╗т╢ё╛н╙й╡ц╢нйфПуБ╦Жё©\n";

if (present("yunnan baiyao", who)) return "дЦиМио╡╩йгря╬╜сптфдо╟вр╘акбПё╛тУц╢сжю╢р╙ё©\n";
   
   if (!(number = me->query("apply/yaono"))) return "╤т╡╩фПё╛тфдо╟вр╘ря╬╜х╚╡©╥╒╥еЁЖх╔ак║ё\n";
   set("apply/yaono", --number);

   ob = new("/d/ourhome/obj/yunnandrug");
   ob -> move(me);
   command("give " + who->query("id") + " yunnan baiyao");
   return "тфдо╟вр╘╣цж╝╡╩рвё╛р╙╫зт╪весц║ё\n";
}

string ask_dan(object me)
{
   object ob, who = this_player();
   int number;

   if (who->query("family/family_name") != "до╨ёфумси╫")
     return RANK_D->query_respect(who) +"сК╠╬це╨анчт╗т╢ё╛н╙й╡ц╢нйфПуБ╦Жё©\n";

   if (present("lingdan", who)) return "дЦиМио╡╩йгря╬╜спаИ╣╓акбПё╛тУц╢сжю╢р╙ё©\n";

   if (!(number = me->query("apply/danno"))) return "╤т╡╩фПё╛аИ╣╓ря╬╜х╚╡©╥╒╥еЁЖх╔ак║ё\n";
   set("apply/danno", --number);

   ob = new("/d/nanhai/obj/lingdan");
   ob -> move(me);
   command("give " + who->query("id") + " lingdan");
   return "аИ╣╓╣цж╝╡╩рвё╛р╙╫зт╪весц║ё\n";
}

