// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zombie.c

#include <ansi.h>

inherit NPC;

void do_bite();

void create()
{
   set_name("僵尸", ({ "zombie" }) );
   set("long",
     "这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
   set("max_kee", 500);
   set("max_sen", 500);
   set("max_mana", 200);
   set("mana", 200);
        set("max_force", 200); 
        set("force", 200);
   set("age", 50);
   set("str", 25);
   set("cor", 30);
   set("chat_chance", 15);
   set("chat_msg_combat", ({
     "僵尸口中发出荷荷的叫声。\n",
     "僵尸的脸上开始痉挛，一阵抽搐，发狂似地大叫。\n",
     "僵尸五指箕张，咬牙切齿，露出狰狞的笑容。\n",
     (: do_bite :),
   }) );
   set_skill("unarmed", 30);
   set_skill("dodge", 30);

   set_temp("apply/damage", 15);

   setup();
}

int is_zombie() { return 1; }

void animate(object who, int time)
{
   set("possessed", who);
   set_leader(who);
}

void die()
{
   object corpse;
        if( environment() ) {
                message("sound", "僵尸慢慢地倒了下去，化为一滩血水。\n", environment());
        }

   destruct(this_object());
}

int heal_up()
{
   object master;

   if( objectp(master = query("possessed")) 
   &&   (int)master->query("mana") > 100 
   &&   (int)master->query("kee") > 100) {
     message("tell",
        HIR + name() + "告诉你：我...需...要...你...的...力...量...\n" NOR,
        master );
     master->add("mana", -50);
     master->receive_damage("sen", 50);
     ::heal_up();
     return 1;     // Always acquire power from master.
   } else {
     call_out("die", 1);
     return ::heal_up();
   } 
}

void do_bite()
{
   object *enemy;

   say( name() + "口中喷出一股中人欲呕的臭气，使你觉得头晕脑胀。\n" );
   enemy = query_enemy();
   for(int i=0; i<sizeof(enemy); i++) {
     if( !enemy[i] ) continue;
     enemy[i]->receive_damage("sen", 30);
     COMBAT_D->report_status(enemy[i], "sen");
   }
}
void init()
{
        add_action("do_attack", "attack");
}

int do_attack(string arg)
{
   object obj, master;
   objectp(master = query("possessed"));
   if( wizardp(this_player()) )
     master = this_player();
   if( (string)this_player()->query("name")!=(string)master->query("name") ) 
   return notify_fail("僵尸口中呜呜两声，好像不愿理你！\n");

   if(!arg || !objectp(obj=present(arg,environment(this_player()))))
           return notify_fail("你想让僵尸攻击谁？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");
   message_vision("$N附耳对$n说了些什么。\n", master, this_object());
   message_vision("$N对$n喊道：去死吧!\n", this_object(), obj);
   this_object()->set("combat_exp", (int)this_player()->query("combat_exp")*2);
   this_object()->set_skill("unarmed", (int)this_player()->query_skill("unarmed")+(int)this_player()->query("kar"));
        this_object()->set_skill("parry", (int)this_player()->query_skill("parry")+(int)this_player()->query("kar"));
        this_object()->set_skill("dodge", (int)this_player()->query_skill("dodge")+(int)this_player()->query("kar"));
   message_vision("\n$N大喝一声，挥拳就向$n打去！\n\n", this_object(), obj);
   // fixed by snowcat: don't use kill_ob (too easy to cause bugs!)
   command("kill "+obj->query("id"));
   return 1;
}
