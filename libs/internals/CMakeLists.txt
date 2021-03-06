include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${CMAKE_CURRENT_BINARY_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}/../libs/client
   ${CMAKE_CURRENT_SOURCE_DIR}/../../backends/NetworkManager
   ${CMAKE_CURRENT_SOURCE_DIR}/../../libs
)

set(knminternals_PUB_HDRS
    activatable.h
    environment.h
)

set(knminternals_HEADERS
   activatable.h
   interfaceconnection.h
   hiddenwirelessinterfaceconnection.h
   wirelessinterfaceconnection.h
   wirelessnetwork.h
   unconfiguredinterface.h
   vpninterfaceconnection.h
   gsminterfaceconnection.h
)

set(knminternals_SOURCES
   connection.cpp

   environment.cpp
   setting.cpp

   settings/802-11-wireless-security.cpp
   settings/802-11-wireless.cpp
   settings/802-3-ethernet.cpp
   settings/802-1x.cpp
   settings/gsm.cpp
   settings/cdma.cpp
   settings/ipv4.cpp
   settings/ipv6.cpp
   settings/ppp.cpp
   settings/pppoe.cpp
   settings/serial.cpp
   settings/vpn.cpp
   settings/bluetooth.cpp

   activatable.cpp
   interfaceconnection.cpp
   interfaceconnectionhelpers.cpp
   hiddenwirelessinterfaceconnection.cpp
   wirelessinterfaceconnection.cpp
   wirelessinterfaceconnectionhelpers.cpp
   wirelessobject.cpp
   wirelessnetwork.cpp
   unconfiguredinterface.cpp
   vpninterfaceconnection.cpp
   vpninterfaceconnectionhelpers.cpp
   gsminterfaceconnection.cpp
   gsminterfaceconnectionhelpers.cpp

   # helper class for recognising the type of WPA secrets
   wpasecretidentifier.cpp

   # helper class for identifying wireless security
   wirelesssecurityidentifier.cpp

   # helper functions for storing tooltip keys and UI strings
   tooltips.cpp
   # helper functions to obtain UI strings for various enums
   uiutils.cpp
)

qt4_wrap_cpp(HEADERS_MOC 
    ${knminternals_HEADERS}
)
   
add_library(knminternals SHARED ${HEADERS_MOC} ${knminternals_SOURCES})

target_link_libraries(knminternals 
    knmclient 
    ModemManagerQt 
    NetworkManagerQt 
    ${QT_QTXML_LIBRARY}  
    ${QT_QTCORE_LIBRARY} 
    ${QT_QTDBUS_LIBRARY} 
    ${QT_QTNETWORK_LIBRARY}
)

set_target_properties(knminternals PROPERTIES
   VERSION ${GENERIC_LIB_VERSION}
   SOVERSION ${GENERIC_LIB_SOVERSION}
   )

install(TARGETS knminternals DESTINATION lib${LIB_SUFFIX})
install(FILES ${knminternals_PUB_HDRS} DESTINATION include/${PROJECT_NAME})
