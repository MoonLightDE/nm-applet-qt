// This file is generated by kconfig_compiler from 802-11-wireless-security.kcfg.
// All changes you do to this file will be lost.

#include "802-11-wireless-securitypersistence.h"

using namespace Knm;

WirelessSecurityPersistence::WirelessSecurityPersistence(WirelessSecuritySetting * setting, KSharedConfig::Ptr config, SettingPersistence::SecretStorageMode mode) : SettingPersistence(setting, config, mode)
{
}

WirelessSecurityPersistence::~WirelessSecurityPersistence()
{
}

void WirelessSecurityPersistence::load()
{
    WirelessSecuritySetting * setting = static_cast<WirelessSecuritySetting *>(m_setting);
    if (m_config->exists()) { // this persistence saves nothing if there is no security, so the 
      // group won't exist.  not indenting the code inside this test to keep the diff clean ;)
    QString contents = m_config->readEntry("securityType", "None");
    if (contents == "None")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::None);
    else     if (contents == "StaticWep")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::StaticWep);
    else     if (contents == "Leap")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::Leap);
    else     if (contents == "DynamicWep")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::DynamicWep);
    else     if (contents == "WpaPsk")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::WpaPsk);
    else     if (contents == "WpaEap")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::WpaEap);
    else     if (contents == "Wpa2Psk")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::Wpa2Psk);
    else     if (contents == "Wpa2Eap")
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::Wpa2Eap);

  {
    QString contents = m_config->readEntry("keymgmt", "None");
    if (contents == "None")
      setting->setKeymgmt(WirelessSecuritySetting::EnumKeymgmt::None);
    else     if (contents == "Ieee8021x")
      setting->setKeymgmt(WirelessSecuritySetting::EnumKeymgmt::Ieee8021x);
    else     if (contents == "WPANone")
      setting->setKeymgmt(WirelessSecuritySetting::EnumKeymgmt::WPANone);
    else     if (contents == "WPAPSK")
      setting->setKeymgmt(WirelessSecuritySetting::EnumKeymgmt::WPAPSK);
    else     if (contents == "WPAEAP")
      setting->setKeymgmt(WirelessSecuritySetting::EnumKeymgmt::WPAEAP);

  }
  setting->setWeptxkeyindex(m_config->readEntry("weptxkeyindex", 0));
  {
    QString contents = m_config->readEntry("authalg", "none");
    if (contents == "none")
      setting->setAuthalg(WirelessSecuritySetting::EnumAuthalg::none);
    else     if (contents == "open")
      setting->setAuthalg(WirelessSecuritySetting::EnumAuthalg::open);
    else     if (contents == "shared")
      setting->setAuthalg(WirelessSecuritySetting::EnumAuthalg::shared);
    else     if (contents == "leap")
      setting->setAuthalg(WirelessSecuritySetting::EnumAuthalg::leap);

  }
  setting->setProto(m_config->readEntry("proto", QStringList()));
  setting->setPairwise(m_config->readEntry("pairwise", QStringList()));
  setting->setGroup(m_config->readEntry("group", QStringList()));
  setting->setLeapusername(m_config->readEntry("leapusername", ""));

  QString wepKeyType = m_config->readEntry("wepkeytype", "key");
  if (wepKeyType == "passphrase") {
      setting->setWepKeyType(Knm::WirelessSecuritySetting::Passphrase);
  } else if (wepKeyType == "hex") {
      setting->setWepKeyType(Knm::WirelessSecuritySetting::Hex);
  }

  // SECRETS
  if (m_storageMode == SettingPersistence::PlainText) {
    setting->setWepkey0(m_config->readEntry("wepkey0", ""));
    setting->setWepkey1(m_config->readEntry("wepkey1", ""));
    setting->setWepkey2(m_config->readEntry("wepkey2", ""));
    setting->setWepkey3(m_config->readEntry("wepkey3", ""));
    setting->setPsk(m_config->readEntry("psk", ""));
    setting->setLeappassword(m_config->readEntry("leappassword", ""));
    QString weppassphrase = m_config->readEntry("weppassphrase", "");
    if (setting->wepkey0().isEmpty()) {
        setting->setWepkey0(weppassphrase);
    } else if (setting->wepkey1().isEmpty()) {
        setting->setWepkey1(weppassphrase);
    } else if (setting->wepkey2().isEmpty()) {
        setting->setWepkey2(weppassphrase);
    } else if (setting->wepkey3().isEmpty()) {
        setting->setWepkey3(weppassphrase);
    }
    setting->setSecretsAvailable(true);
  }
    setting->setWepkeyflags(Setting::AgentOwned);
    setting->setPskflags(Setting::AgentOwned);
    setting->setLeappasswordflags(Setting::AgentOwned);
  } else {
      setting->setSecurityType(WirelessSecuritySetting::EnumSecurityType::None);
  }
}