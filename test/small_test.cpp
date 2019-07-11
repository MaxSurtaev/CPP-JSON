#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <json.hpp>

TEST_CASE("constructor object") {
  json::JSON a = json::Object();
  REQUIRE(a.JSONType() == json::JSON::Class::Object);
  REQUIRE(a.size() == 0);
}

TEST_CASE("constructor array") {
  json::JSON a = json::Array();
  REQUIRE(a.JSONType() == json::JSON::Class::Array);
  REQUIRE(a.size() == 0);
}

TEST_CASE("load") {
  auto a = "{\"a\": \"b\",\"c\":1}";
  json::JSON b = json::JSON::Load(a);
  REQUIRE(b["a"].ToString() == "b");
  REQUIRE(b["c"].ToInt() == 1);
}

TEST_CASE("dump") {
  json::JSON a = {"a", 1};
  REQUIRE(a["a"].ToInt() == 1);
  INFO(a.dump());
}

TEST_CASE("remove object") {
  json::JSON a = {"a", {"b", 1}, "c", {"d", 2}};
  a.remove("a");
  REQUIRE(a.size() == 1);
  REQUIRE(a.hasKey("c"));
  REQUIRE(a.hasKey("a") == false);
}

TEST_CASE("remove array") {
  json::JSON a = json::Array(1, 2);
  a.remove(0);
  INFO(a.dump());
  REQUIRE(a.size() == 1);
  REQUIRE(a[0].ToInt() == 2);
}

TEST_CASE("push_front") {
  auto a = "[1,2,3]";
  json::JSON b = json::JSON::Load(a);
  b.push_front(0);
  REQUIRE(b[0].ToInt() == 0);
  REQUIRE(b[1].ToInt() == 1);
  REQUIRE(b[2].ToInt() == 2);
  REQUIRE(b[3].ToInt() == 3);
}