// ษ๑ปฐสภฝ็กคฮ๗ำฮผวกคฐๆฑพฃดฃฎฃตฃฐ
/* <SecCrypt CPL V3R05> */
 
// shami.c ะกษณรึบ
// By Dream Dec. 20, 1996

inherit NPC;

void create()
{
   set_name("ะกษณรึ", ({ "shami", "bonze" }));
   set("gender", "ฤะะิ");
   set("age", 10);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 100);
   set("max_gin", 100);
   set("max_sen", 100);
   set("combat_exp", 1000);
   set_skill("literate", 20);
   set_skill("unarmed", 20);
   set_skill("dodge", 25);
   set_skill("parry", 20);
   set_skill("force", 10);
   
   setup();
   carry_object("/d/nanhai/obj/sengpao")->wear();
}

