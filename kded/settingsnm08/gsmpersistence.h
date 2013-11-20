// This file is generated by kconfig_compiler from gsm.kcfg.
// All changes you do to this file will be lost.
#ifndef KNM_GSMPERSISTENCE_H
#define KNM_GSMPERSISTENCE_H

#include <kdebug.h>
#include "settingpersistence.h"
#include "internals/settings/gsm.h"

namespace Knm {

class GsmSetting;

class GsmPersistence : public SettingPersistence
{
  public:
    GsmPersistence( GsmSetting * setting, KSharedConfig::Ptr config, SettingPersistence::SecretStorageMode mode = SettingPersistence::Secure);
    ~GsmPersistence();
    void load();
};
}

#endif
