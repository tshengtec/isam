#include "AccountService.h"

AccountService * AccountService::_instance = NULL;


AccountService::AccountService()
{
}

AccountService *AccountService::instance()
{
    if (_instance == NULL) {
        _instance = new AccountService();
    }
    return _instance;
}
