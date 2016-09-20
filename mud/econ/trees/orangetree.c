inherit "/econ/trees/fruittrees";

TASTE( "It's been pasteurized." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "orange";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}
