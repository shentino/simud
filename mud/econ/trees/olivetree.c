inherit "/econ/trees/fruittrees";

TASTE( "Estoy una zapateria." )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}

string query_name() {
  return "olive";
}

string query_wood_type() {
  return "/econ/raw/wood/"+query_name()+"wood";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}
