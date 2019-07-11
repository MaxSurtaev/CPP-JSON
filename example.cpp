#include "json.hpp"
#include <iostream>

using json::JSON;
int main() {

  JSON a = JSON::Load("{ \"Key\" : \"Value\" }");
  std::cout << a << std::endl;
  // Output:
  // {
  //   "Key" : "Value"
  // }

  JSON b = {"a", 1, "b", true, "c", json::Array(1.2, 1, 3)};
  std::cout << b << std::endl;
  // Output:
  // {
  //   "a" : 1,
  //   "b" : true,
  //   "c" : [1.200000, 1, 3]
  // }

  a["b"] = b;
  std::cout << a << std::endl;
  // Output:
  // {
  //   "Key" : "Value",
  //   "b" : {
  //     "a" : 1,
  //     "b" : true,
  //     "c" : [1.200000, 1, 3]
  //   }
  // }

  a["b"]["c"].append(2.2);
  std::cout << a << std::endl;
  // Output:
  // {
  //   "Key" : "Value",
  //   "b" : {
  //     "a" : 1,
  //     "b" : true,
  //     "c" : [1.200000, 1, 3, 2.200000]
  //   }
  // }

  a.remove("b");
  std::cout << a << std::endl;
  // Output:
  // {
  //   "Key" : "Value"
  // }

  std::string c = a.dump();
  std::cout << c << std::endl;
  // Output as in <<:
  // {
  //   "Key" : "Value"
  // }

  JSON d = {"Key1", "Value1", "Key2", "Value2", "Key3", "Value3"};
  for (auto &i : d.ObjectRange()) {
    std::cout << i.first << "=>" << i.second << std::endl;
  }
  // Output:
  // Key1=>"Value1"
  // Key2=>"Value2"
  // Key3=>"Value3"

  JSON e = json::Array("a", "b", "c");
  for (auto &i : e.ArrayRange()) {
    std::cout << i << std::endl;
  }
  // Output:
  // "a"
  // "b"
  // "c"

  return 0;
}