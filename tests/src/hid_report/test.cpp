#define CATCH_CONFIG_MAIN
#include "../../vendor/catch/catch.hpp"

#include "karabiner_virtual_hid_device.hpp"

TEST_CASE("modifiers") {
  {
    pqrs::karabiner_virtual_hid_device::hid_report::modifiers modifiers;
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));

    modifiers.add_modifier(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));

    modifiers.add_modifier(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));

    modifiers.erase_modifier(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));

    modifiers.erase_modifier(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control);
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));

    modifiers.clear();
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifiers::modifier::right_command));
  }
}

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
