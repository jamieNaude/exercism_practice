namespace hellmath {

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll && viewer == AccountStatus::troll) {
        return true; // troll posts seen by trolls 
    }
    if (poster == AccountStatus::troll) {
        return false; // troll posts not seen by non-trolls
    }
    return true; // non troll posts seen by all
}

bool permission_check(Action action, AccountStatus account) {
    if (account == AccountStatus::guest) {
        if (action == Action::read) {
            return true;
        }
        return false;
    }
    if (account == AccountStatus::user || account == AccountStatus::troll) {
        if (action == Action::remove) {
            return false;
        }       
        return true;
    }
    return true; // mod
}

bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
    if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
        return false;
    }
    if (player1 == AccountStatus::troll || player2 == AccountStatus::troll) {
        if (player1 == AccountStatus::troll && player2 == AccountStatus::troll) {
            return true;
        }
        return false;
    }
    return true; // both players users or mods
}

bool has_priority(AccountStatus account1, AccountStatus account2) {
    if (static_cast<int>(account1) > static_cast<int>(account2)) {
        return true;
    }
    return false;
}

}  // namespace hellmath
