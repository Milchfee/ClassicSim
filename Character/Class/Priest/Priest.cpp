
#include "Priest.h"

QString Priest::get_name(void) const {
    return "Priest";
}

QString Priest::get_class_color() const {
    return "#FFFFFF";
}

int Priest::get_strength_modifier(void) const {
    return 0;
}

int Priest::get_agility_modifier(void) const {
    return 0;
}

int Priest::get_stamina_modifier(void) const {
    return 0;
}

int Priest::get_intellect_modifier(void) const {
    return 2;
}

int Priest::get_spirit_modifier(void) const {
    return 3;
}

int Priest::get_agi_needed_for_one_percent_phys_crit() const {
    // TODO: Placeholder value
    return 20;
}

int Priest::get_int_needed_for_one_percent_spell_crit() const {
    // TODO: Placeholder value
    return 20;
}

int Priest::get_ap_per_strength() const {
    return 1;
}

int Priest::get_ap_per_agi() const {
    return 1;
}

float Priest::global_cooldown() const {
    return 1.5;
}

void Priest::initialize_talents() {

}
