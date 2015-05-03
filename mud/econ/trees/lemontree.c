inherit "/econ/trees/fruittrees";

TASTE( "The weed of crime bears bitter fruit, you old hag!" )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "lemon";
}

string query_wood_type() {
  return "/econ/raw/lemonwood";
}

string query_fruit_type() {
  return "/econ/seed/lemon";
}
