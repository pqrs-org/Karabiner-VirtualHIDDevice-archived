#define CATCH_CONFIG_MAIN
#include "../../vendor/catch/catch.hpp"

#include "karabiner_virtual_hid_device.hpp"

TEST_CASE("keys") {
  {
    pqrs::karabiner_virtual_hid_device::hid_report::keys keys;
    REQUIRE(keys.count() == 0);

    keys.add_key(10);
    REQUIRE(keys.count() == 1);

    keys.add_key(10);
    REQUIRE(keys.count() == 1);

    keys.erase_key(20);
    REQUIRE(keys.count() == 1);

    keys.erase_key(10);
    REQUIRE(keys.count() == 0);

    keys.erase_key(10);
    REQUIRE(keys.count() == 0);

    keys.add_key(10);
    REQUIRE(keys.count() == 1);

    keys.add_key(20);
    REQUIRE(keys.count() == 2);

    keys.clear();
    REQUIRE(keys.count() == 0);
  }
}
