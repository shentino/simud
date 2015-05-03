inherit "/econ/trees/fruittrees";

TASTE( "It tastes like a one-dollar bill." )

string query_name() {
  return "cherry";
}

string query_wood_type() {
  return "/econ/raw/"+query_name()+"wood";
}

string query_fruit_type() {
  return "/econ/seed/"+query_name();
}
