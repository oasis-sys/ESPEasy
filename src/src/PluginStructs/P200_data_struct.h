#ifndef PLUGINSTRUCTS_P200_DATA_STRUCT_H
#define PLUGINSTRUCTS_P200_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"

#ifdef USES_P200

# include <ESPeasySerial.h>

# ifndef PLUGIN_200_DEBUG
  #  define PLUGIN_200_DEBUG                 false // extra logging in serial out
# endif // ifndef PLUGIN_200_DEBUG

# define P200_STATUS_LED                    12
# define P200_DATAGRAM_MAX_SIZE             256
struct P200_Task : public PluginTaskData_base {
  P200_Task(taskIndex_t taskIndex);
  P200_Task() = delete;
  virtual ~P200_Task();

  inline static bool serverActive(WiFiServer *server);


  void               startServer(uint16_t portnumber);

  void               checkServer();

  void               stopServer();

  bool               hasClientConnected();

  void               discardClientIn();

  void               clearBuffer();

  void               serialBegin(const ESPEasySerialPort port,
                                 int16_t                 rxPin,
                                 int16_t                 txPin,
                                 unsigned long           baud,
                                 uint8_t                 config);

  void serialEnd();

  void handleSerialIn(struct EventStruct *event);
  void handleClientIn(struct EventStruct *event);
  void rulesEngine(const String& message);

  void discardSerialIn();

  bool isInit() const;

  void sendConnectedEvent(bool connected);

  WiFiServer    *ser2netServer = nullptr;
  uint16_t       gatewayPort   = 0;
  WiFiClient     ser2netClient;
  bool           clientConnected = false;
  String         serial_buffer;
  String         net_buffer;
  int            checkI            = 0;
  ESPeasySerial *ser2netSerial     = nullptr;
  uint8_t        serial_processing = 0;
  taskIndex_t    _taskIndex        = INVALID_TASK_INDEX;
  bool           handleMultiLine   = false;
};

#endif // ifdef USES_P200
#endif // ifndef PLUGINSTRUCTS_P200_DATA_STRUCT_H
