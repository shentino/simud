inherit "/econ/trees/fruittrees";

TASTE( "Fine and dandy." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "plum";
}

string query_wood_type() {
  return "/econ/raw/"+query_name()+"wood";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}
