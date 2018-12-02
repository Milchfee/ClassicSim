#ifndef TESTBLADEFLURRY_H
#define TESTBLADEFLURRY_H

#include "TestSpellRogue.h"

class TestBladeFlurry: public TestSpellRogue {
public:
    TestBladeFlurry(EquipmentDb *equipment_db);

    void test_all();

private:
    BladeFlurry* blade_flurry();

    void test_name_correct() override;
    void test_spell_cooldown() override;
    void test_incurs_global_cooldown() override;
    void test_obeys_global_cooldown() override;
    void test_resource_cost() override;
    void test_is_ready_conditions() override;
    void test_combo_points() override;
    void test_stealth() override;

    void test_attack_speed();

    void when_blade_flurry_is_performed();

    void given_1_of_1_blade_flurry();
};

#endif // TESTBladeFlurry_H