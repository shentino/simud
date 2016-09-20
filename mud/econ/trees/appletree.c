inherit "/econ/trees/fruittrees";

TASTE( "It tastes knowledgeable." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "apple";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}
