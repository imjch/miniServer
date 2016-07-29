#ifndef PLATFORMPROCESSOR_INCLUDE
#define PLATFORMPROCESSOR_INCLUDE
class PlatformProcessor{
public:
    PlatformProcessor()=default;
    virtual ~PlatformProcessor()=default;
    virtual void Execute(const std::string& resourceName)=0;
private:

};

class JavaPlatformProcessor:public PlatformProcessor{
public:
    JavaPlatformProcessor()=default;
    ~JavaPlatformProcessor()=default;

    void Execute(const std::string& resourceName) override ;
private:

};

class PHPPlatformProcessor:public PlatformProcessor{
public:
    PHPPlatformProcessor()=default;
    ~PHPPlatformProcessor()=default;

    void Execute(const std::string& resourceName) override ;
private:

};
#endif