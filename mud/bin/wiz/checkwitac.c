#include <const.h>
/**This verb is used to check a player's status in the Witac quests/description
 * settings. The usage is "checkwitac <player-name>" and the player must be
 * online when it is used. */


main( string str ) {
   string target;
   string toprint = "";
   string items = "";
   string missing = "";
   int changed = 0;
/**Add or remove items that are required to leave Witac here*/
   mapping needed_items = ([
      "knife" : -1,
      "hatchet" : -1,
      "shirt" : -1,
      "pants" : -1
   ]);

   if( this_player()->query_level() < WIZLEVEL ) {
      notify_fail( "Nice try.\n" );
   }

   if( !str ) {
      notify_fail( "Check the status of whom?\n" );
      return 0;
   }

   target = find_player( str );

   if( !target )
      return notify_fail("Could not find " + str + "!\n");

   msg_object( this_player(), "~CTITChecking status of ~CBRT" + target->query_cap_name()
 + "~CTIT.~CDEF");

/**Set Desc*/
   mapping desc = target->query_env_var( "desc" );
   if( !desc ) {
      target->setup_desc_var();
      desc = target->query_env_var( "desc" );
      msg_object( this_player(), "~CWRNDidn't have description, creating.~CDEF" );
      changed = 1;
   }
/**Set/Check Hair*/
   if( !desc["hair"] ) {
      desc["hair"] = ({ "bland", "bland", "bland" });
      msg_object( this_player(), "Didn't have hair, creating." );
      changed = 1;
   }
   toprint += "Hair: ";
   toprint += check(desc["hair"][HAIR_COLOR] + " color") + ", ";
   toprint += check(desc["hair"][HAIR_STYLE] + " style") + ", ";
   toprint += check(desc["hair"][HAIR_LENGTH] + " length") + "\n";
/**Set Adjective*/
   if( !desc["adj"] ) {
      desc["adj"] = ({ "bland", "" });
      msg_object( this_player(), "Didn't have adjectives, creating." );
      changed = 1;
   }
   toprint += "Adjectives: ";
   toprint += check(desc["adj"][ADJ_PRIMARY] + " primary") + ", ";
   toprint += check(desc["adj"][ADJ_SECONDARY]) + "\n";
/**Set Eyes*/
   if( !desc["eyes"] ) {
      desc["eyes"] = ({ "bland", "", 2 });
      msg_object( this_player(), "Didn't have eyes, creating." );
      changed = 1;
   }
   toprint += "Eyes: ";
   toprint += check(desc["eyes"][EYE_COLOR] + " color") + ", ";
   toprint += check(desc["eyes"][EYE_ADJ] + " adjective") + ", ";
   toprint += check(desc["eyes"][EYE_COUNT] + " count") + "\n";
/**Set Skin*/
   if( !desc["skin"] ) {
      desc["skin"] = ({ "bland", "" });
      msg_object( this_player(), "Didn't have skin, creating." );
      changed = 1;
   }
   toprint += "Skin: ";
   toprint += check(desc["skin"][SKIN_COLOR] + " color") + ", ";
   toprint += check(desc["skin"][SKIN_ADJ] + " adjective") + "\n";
/**Save the new description*/
   if( changed ) {
      target->set_env_var( "desc", desc );
      msg_object( this_player(), "Saving new description." );
   } else {
      msg_object( this_player(), check( "Description mapping in place" ) );
   }
/**Check for items*/
   foreach( object ob : all_inventory(target) ) {
      if( needed_items[ob->query_name()] == -1 ) {
         needed_items[ob->query_name()] = 1;
      }
   }
   toprint += "Items: ";
   foreach( string name : needed_items ) {
      if( needed_items[name] == 1 ) {
         toprint += pass(name) + " ";
      }
      else {
         toprint += fail(name) + " ";
      }
   }
/**Display the check*/
   msg_object( this_player(), toprint );
   return 1;
}

string pass( string str ) {
   return "~CREF+" + str + "~CDEF";
}

string fail( string str ) {
   return "~CWRN-" + str + "~CDEF";
}

string check( string tocheck ) {
   if( tocheck[0..4] == "bland" ) {
      return fail(tocheck);
   }
   else if( tocheck == "" || trim(tocheck) == "adjective" ) {
      return pass("not needed");
   }
   else {
      return pass(tocheck);
   }
}

string checkint( int tocheck ) {
   if( tocheck <= 0) {
      return "~CWRN" + tocheck + "~CDEF";
   }
   else {
      return "~CREF" + tocheck + "~CDEF";
   }
}
