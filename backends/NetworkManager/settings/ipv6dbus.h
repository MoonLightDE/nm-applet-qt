// This file is generated by kconfig_compiler from ipv6.kcfg.
// All changes you do to this file will be lost.
#ifndef IPV6DBUS_H
#define IPV6DBUS_H

#include <nm-setting-ip6-config.h>

#include <QHostAddress>
#include <QDBusArgument>

#include "settingdbus.h"
#include "nm09dbus_export.h"

#include "settings/ipv6.h"
#include <NetworkManagerQt/ipconfig.h>

typedef struct
{
    QList<quint8> address;
    uint netMask;
    QList<quint8> gateway;
} IpV6AddressMap;

Q_DECLARE_METATYPE(IpV6AddressMap)
Q_DECLARE_METATYPE(QList<IpV6AddressMap>)

QDBusArgument &operator<<(QDBusArgument &argument, const IpV6AddressMap &map);
const QDBusArgument &operator>>(const QDBusArgument &argument, IpV6AddressMap &map);

typedef struct
{
    QList<quint8> route;
    uint prefix;
    QList<quint8> nextHop;
    uint metric;
} IpV6RouteMap;

Q_DECLARE_METATYPE(IpV6RouteMap)
Q_DECLARE_METATYPE(QList<IpV6RouteMap>)

QDBusArgument &operator<<(QDBusArgument &argument, const IpV6RouteMap &map);
const QDBusArgument &operator>>(const QDBusArgument &argument, IpV6RouteMap &map);

class NM09DBUS_EXPORT Ipv6Dbus : public SettingDbus
{
    public:
        Ipv6Dbus(Knm::Ipv6Setting *setting);
        ~Ipv6Dbus();
        void fromMap(const QVariantMap &);
        QVariantMap toMap();
        QVariantMap toSecretsMap();

        Knm::Ipv6Setting::EnumMethod::type methodStringToEnum(QString method);
};
#endif

