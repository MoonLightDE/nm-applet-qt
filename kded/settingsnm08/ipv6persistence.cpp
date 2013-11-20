// This file is generated by kconfig_compiler from ipv6.kcfg.
// All changes you do to this file will be lost.

#include "ipv6persistence.h"

using namespace Knm;

Ipv6Persistence::Ipv6Persistence(Ipv6Setting * setting, KSharedConfig::Ptr config, SettingPersistence::SecretStorageMode mode) : SettingPersistence(setting, config, mode)
{
}

Ipv6Persistence::~Ipv6Persistence()
{
}

void Ipv6Persistence::load()
{
  Ipv6Setting * setting = static_cast<Ipv6Setting *>(m_setting);
  {
    QString contents = m_config->readEntry("method", "Ignore");
    if (contents == "Automatic")
      setting->setMethod(Ipv6Setting::EnumMethod::Automatic);
    else     if (contents == "LinkLocal")
      setting->setMethod(Ipv6Setting::EnumMethod::LinkLocal);
    else     if (contents == "Manual")
      setting->setMethod(Ipv6Setting::EnumMethod::Manual);
    else     if (contents == "Shared")
      setting->setMethod(Ipv6Setting::EnumMethod::Shared);
    else     if (contents == "Ignore")
      setting->setMethod(Ipv6Setting::EnumMethod::Ignore);
  }

  // dns
  QList<QHostAddress> dnsServers;
  QStringList rawDnsServers = m_config->readEntry("dns", QStringList());
  foreach (const QString &server, rawDnsServers) {
      dnsServers.append(QHostAddress(server));
  }
  setting->setDns(dnsServers);

  setting->setDnssearch(m_config->readEntry("dnssearch", QStringList()));

  // addresses
  QList<NetworkManager::IpAddress> addresses;
  QStringList rawAddresses = m_config->readEntry("addresses", QStringList());
  foreach (const QString &rawAddress, rawAddresses) {
      QStringList parts = rawAddress.split(QLatin1Char(';'));
      if (parts.count() != 3) { // sanity check
          continue;
      }

      NetworkManager::IpAddress address;
      address.setIp(QHostAddress(parts[0]));
      address.setPrefixLength(parts[1].toInt());
      address.setGateway(QHostAddress(parts[2]));

      addresses << address;
  }
  setting->setAddresses(addresses);

  // routes
  QList<NetworkManager::IpRoute> routes;
  QStringList rawRoutes = m_config->readEntry("routes", QStringList());
  foreach (const QString &rawRoute, rawRoutes) {
      QStringList parts = rawRoute.split(QLatin1Char(';'));
      if (parts.count() != 4) { // sanity check
          continue;
      }

      NetworkManager::IpRoute route;
      route.setIp(QHostAddress(parts[0]));
      route.setPrefixLength(parts[1].toInt());
      route.setNextHop(QHostAddress(parts[2]));
      route.setMetric(parts[3].toUInt());

      routes << route;
  }
  setting->setRoutes(routes);
  setting->setIgnoredhcpdns(m_config->readEntry("ignoredhcpdns", false));
  setting->setIgnoreautoroute(m_config->readEntry("ignoreautoroute", false));
  setting->setNeverdefault(m_config->readEntry("neverdefault", false));
  setting->setMayfail(m_config->readEntry("mayfail", true));
}
