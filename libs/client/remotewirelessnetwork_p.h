/*
Copyright 2009 Will Stephenson <wstephenson@kde.org>
Copyrignt 2012 Lamarque V. Souza <lamarque@kde.org>

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) version 3, or any
later version accepted by the membership of KDE e.V. (or its
successor approved by the membership of KDE e.V.), which shall
act as a proxy defined in Section 6 of version 3 of the license.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REMOTE_WIRELESS_NETWORK_P_H
#define REMOTE_WIRELESS_NETWORK_P_H

#include "remoteactivatable_p.h"

#include "wirelessnetworkinterface.h"

class RemoteWirelessNetworkPrivate : public RemoteActivatablePrivate
{
    public:
        WirelessNetworkInterface *wirelessNetworkItemInterface;
        QString ssid;
        int signalStrength;
        NetworkManager::WirelessDevice::Capabilities interfaceCapabilities;
        NetworkManager::AccessPoint::Capabilities apCapabilities;
        NetworkManager::AccessPoint::WpaFlags wpaFlags;
        NetworkManager::AccessPoint::WpaFlags rsnFlags;
        NetworkManager::WirelessDevice::OperationMode operationMode;
};

#endif // REMOTE_WIRELESS_NETWORK_P_H
