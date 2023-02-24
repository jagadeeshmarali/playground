#include <iostream>
#include <string>

class Zone
{
public:
  virtual ~Zone() {}

  virtual std::string getTime() = 0;
};

class EasternTime : public Zone
{
public:
  ~EasternTime() {}

  std::string getTime()
  {
    return "EasternTime + offset";
  }
};

class CentralTime : public Zone
{
public:
  ~CentralTime() {}

  std::string getTime()
  {
    return "Central Time + offset";
  }
};

class IZoneFactory
{
public:
  virtual ~IZoneFactory() {}

  virtual Zone *createEasternTime() = 0;
  virtual Zone *createCentralTime() = 0;

  virtual void removeZone(Zone *zone) = 0;
};

class ZoneFactory : public IZoneFactory
{
public:
  ~ZoneFactory() {}

  Zone *createCentralTime()
  {
    return new CentralTime();
  }

  Zone *createEasternTime()
  {
    return new EasternTime();
  }

  void removeZone(Zone *zone)
  {
    delete zone;
  }
};

int main()
{
  IZoneFactory *zfactory = new ZoneFactory();

  Zone *z1 = zfactory->createCentralTime();
  std::cout << "Zone: " << z1->getTime() << std::endl;
  zfactory->removeZone(z1);

  Zone *z2 = zfactory->createEasternTime();
  std::cout << "Zone: " << z2->getTime() << std::endl;
  zfactory->removeZone(z2);

  delete zfactory;
  return 0;
}
