// This file is generated by kconfig_compiler from 802-1x.kcfg.
// All changes you do to this file will be lost.
#ifndef SECURITY8021XDBUS_H
#define SECURITY8021XDBUS_H

#include <nm-setting-8021x.h>

#include "settingdbus.h"
#include "nm09dbus_export.h"
namespace Knm
{
    class Security8021xSetting;
}

class NM09DBUS_EXPORT Security8021xDbus : public SettingDbus
{
    public:
        Security8021xDbus(Knm::Security8021xSetting *setting);
        ~Security8021xDbus();
        void fromMap(const QVariantMap &);
        QVariantMap toMap();
        QVariantMap toSecretsMap();
};
#endif

