#include "TalentRequirer.h"

#include "Buff.h"
#include "Proc.h"
#include "Spell.h"
#include "Utils/Check.h"

TalentRequirer::TalentRequirer(const QVector<TalentRequirerInfo*>& talent_info) {
    check(!talent_info.empty(), "talent_info empty");

    for (const auto& info : talent_info) {
        check(!this->talent_info.contains(info->name), "talent_info does not contain name");
        this->talent_info[info->name] = info;
    }
}

TalentRequirer::~TalentRequirer() {
    for (const auto& info : this->talent_info)
        delete info;
}

void TalentRequirer::increase_talent_rank(Buff* buff, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    ++talent_info[talent]->curr;
    check((talent_info[talent]->curr <= talent_info[talent]->max), "Cannot increment talent above its max");

    increase_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 1 && talent_info[talent]->disabled_at_zero)
        buff->enable_buff();
}

void TalentRequirer::decrease_talent_rank(Buff* buff, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    --talent_info[talent]->curr;
    check((talent_info[talent]->curr >= 0), "Cannot decrement talent below 0");

    decrease_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 0 && talent_info[talent]->disabled_at_zero)
        buff->disable_buff();
}

void TalentRequirer::increase_talent_rank(Spell* spell, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    ++talent_info[talent]->curr;
    check((talent_info[talent]->curr <= talent_info[talent]->max), "Cannot increment talent above its max");

    increase_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 1 && talent_info[talent]->disabled_at_zero)
        spell->enable();
}

void TalentRequirer::decrease_talent_rank(Spell* spell, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    --talent_info[talent]->curr;
    check((talent_info[talent]->curr >= 0), "Cannot decrement talent below 0");

    decrease_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 0 && talent_info[talent]->disabled_at_zero)
        spell->disable();
}

void TalentRequirer::increase_talent_rank(Proc* proc, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    ++talent_info[talent]->curr;
    check((talent_info[talent]->curr <= talent_info[talent]->max), "Cannot increment talent above its max");

    increase_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 1 && talent_info[talent]->disabled_at_zero) {
        proc->enable();
        proc->enable_proc();
    }
}

void TalentRequirer::decrease_talent_rank(Proc* proc, const QString& talent) {
    check(talent_info.contains(talent), "talent_info does not contain talent");

    --talent_info[talent]->curr;
    check((talent_info[talent]->curr >= 0), "Cannot decrement talent below 0");

    decrease_talent_rank_effect(talent, talent_info[talent]->curr);

    if (talent_info[talent]->curr == 0 && talent_info[talent]->disabled_at_zero) {
        proc->disable_proc();
        proc->disable();
    }
}
