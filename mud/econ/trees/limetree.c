inherit "/econ/trees/fruittrees";

TASTE( "The weed of crime bears bitter fruit, you old hag!" )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "lime";
}

string query_wood_type() {
  return "/econ/raw/wood/limewood";
}

string query_fruit_type() {
  return "/econ/seed/lime";
}
