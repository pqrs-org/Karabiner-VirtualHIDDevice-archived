#define CATCH_CONFIG_MAIN
#include "../../vendor/catch/catch.hpp"

#include "karabiner_virtual_hid_device.hpp"

TEST_CASE("modifiers") {
  {
    pqrs::karabiner_virtual_hid_device::hid_report::modifiers modifiers;
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));

    modifiers.insert(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));

    modifiers.insert(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));

    modifiers.erase(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift);
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));

    modifiers.erase(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control);
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));

    modifiers.clear();
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::left_command));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_control));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_shift));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_option));
    REQUIRE(!modifiers.exists(pqrs::karabiner_virtual_hid_device::hid_report::modifier::right_command));
  }
}

TEST_CASE("keys") {
  {
    pqrs::karabiner_virtual_hid_device::hid_report::keys keys;
    REQUIRE(keys.count() == 0);

    keys.insert(10);
    REQUIRE(keys.count() == 1);
    REQUIRE(keys.exists(10));
    REQUIRE(!keys.exists(20));

    keys.insert(10);
    REQUIRE(keys.count() == 1);

    keys.erase(20);
    REQUIRE(keys.count() == 1);

    keys.erase(10);
    REQUIRE(keys.count() == 0);

    keys.erase(10);
    REQUIRE(keys.count() == 0);

    keys.insert(10);
    REQUIRE(keys.count() == 1);

    keys.insert(20);
    REQUIRE(keys.count() == 2);

    keys.clear();
    REQUIRE(keys.count() == 0);
  }

  {
    // Overflow

    pqrs::karabiner_virtual_hid_device::hid_report::keys keys;
    REQUIRE(keys.count() == 0);

    for (int i = 0; i < 6; ++i) {
      keys.insert(i + 1);
      REQUIRE(keys.count() == (i + 1));
    }

    keys.insert(10);
    REQUIRE(keys.count() == 6);

    keys.insert(20);
    REQUIRE(keys.count() == 6);
  }
}

TEST_CASE("buttons") {
  {
    pqrs::karabiner_virtual_hid_device::hid_report::buttons buttons;
    REQUIRE(buttons.get_raw_value() == 0);

    buttons.insert(1);
    REQUIRE(buttons.get_raw_value() == 0x1);

    buttons.insert(32);
    REQUIRE(buttons.get_raw_value() == 0x80000001);

    buttons.insert(0);
    REQUIRE(buttons.get_raw_value() == 0x80000001);

    buttons.insert(33);
    REQUIRE(buttons.get_raw_value() == 0x80000001);

    buttons.erase(1);
    REQUIRE(buttons.get_raw_value() == 0x80000000);

    buttons.clear();
    REQUIRE(buttons.get_raw_value() == 0);
  }
}
