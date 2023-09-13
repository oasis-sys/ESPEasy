#include "../DataStructs/DeviceStruct.h"



DeviceStruct::DeviceStruct() :
  Number(0), Type(0), VType(Sensor_VType::SENSOR_TYPE_NONE), Ports(0), ValueCount(0),
  OutputDataType(Output_Data_type_t::Default),
  PullUpOption(false), InverseLogicOption(false), FormulaOption(false),
  Custom(false), SendDataOption(false), GlobalSyncOption(false),
  TimerOption(false), TimerOptional(false), DecimalsOnly(false),
  DuplicateDetection(false), ExitTaskBeforeSave(true), ErrorStateValues(false), 
  PluginStats(false), PluginLogsPeaks(false), PowerManager(false),
  TaskLogsOwnPeaks(false), I2CNoDeviceCheck(false) {}

bool DeviceStruct::connectedToGPIOpins() const {
  switch(Type) {
    case DEVICE_TYPE_SINGLE:  // Single GPIO
    case DEVICE_TYPE_SPI:
    case DEVICE_TYPE_CUSTOM1:

    case DEVICE_TYPE_DUAL:    // Dual GPIOs
    case DEVICE_TYPE_SERIAL:
    case DEVICE_TYPE_SPI2:
    case DEVICE_TYPE_CUSTOM2:

    case DEVICE_TYPE_TRIPLE:  // Triple GPIOs
    case DEVICE_TYPE_SERIAL_PLUS1:
    case DEVICE_TYPE_SPI3:
    case DEVICE_TYPE_CUSTOM3:    
      return true;
    default:
      return false;
  }
}

bool DeviceStruct::usesTaskDevicePin(int pin) const {
  if (pin == 1)
      return connectedToGPIOpins();
  if (pin == 2)
      return connectedToGPIOpins() && 
            !(Type == DEVICE_TYPE_SINGLE  ||
              Type == DEVICE_TYPE_SPI ||
              Type == DEVICE_TYPE_CUSTOM1);
  if (pin == 3)
      return Type == DEVICE_TYPE_TRIPLE || 
             Type == DEVICE_TYPE_SERIAL_PLUS1 || 
             Type == DEVICE_TYPE_SPI3 ||
             Type == DEVICE_TYPE_CUSTOM3;
  return false;
}


bool DeviceStruct::configurableDecimals() const {
  return FormulaOption || DecimalsOnly;
}

bool DeviceStruct::isSerial() const {
  return (Type == DEVICE_TYPE_SERIAL) || 
         (Type == DEVICE_TYPE_SERIAL_PLUS1);
}

bool DeviceStruct::isSPI() const {
  return (Type == DEVICE_TYPE_SPI) || 
         (Type == DEVICE_TYPE_SPI2) || 
         (Type == DEVICE_TYPE_SPI3);
}

bool DeviceStruct::isCustom() const {
  return (Type == DEVICE_TYPE_CUSTOM0) || 
         (Type == DEVICE_TYPE_CUSTOM1) || 
         (Type == DEVICE_TYPE_CUSTOM2) || 
         (Type == DEVICE_TYPE_CUSTOM3);
}

pluginID_t DeviceStruct::getPluginID() const
{
  return pluginID_t::toPluginID(Number);
}


DeviceCount_t& DeviceCount_t::operator++() {
  // pre-increment, ++a
  ++value;
  return *this;
}



#ifndef ESP8266

const DeviceStruct& DeviceVector::operator[](deviceIndex_t index) const
{
  return _vector[index.value];
}

DeviceStruct& DeviceVector::operator[](DeviceCount_t index)
{
  return _vector[index.value];
}

DeviceStruct& DeviceVector::getDeviceStructForEdit(deviceIndex_t index)
{
  return _vector[index.value];
}

size_t DeviceVector::size() const
{
  return _vector.size();
}

void DeviceVector::resize(size_t newSize)
{
  _vector.resize(newSize);
}

#endif