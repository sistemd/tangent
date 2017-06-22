#define BOOST_TEST_MODULE functions_tests
#include "boost/test/unit_test.hpp"

#include "../include/functions.hpp"

BOOST_AUTO_TEST_CASE(function_defintion_test)
{
  namespace Mira = Tangent::Mira;
  
  constexpr auto function_name = "f1";

  Mira::Function_table tbl;
  tbl.add_function({
    function_name, 
    {}, 
    [](auto _) -> Mira::Number {
      return 0;
    }
  });

  auto thunk = tbl.thunk_for_function(function_name, {});
  BOOST_CHECK(thunk != boost::none);
  BOOST_CHECK_EQUAL(thunk->execute(), 0);
}
