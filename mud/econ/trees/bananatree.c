inherit "/econ/trees/fruittrees";

TASTE( "It tastes doomed." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "banana";
}

string query_wood_type() {
  return "/econ/raw/wood/bananawood";
}

string query_fruit_type() {
  return "/econ/seed/banana";
}
