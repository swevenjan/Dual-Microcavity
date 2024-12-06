/*
B1ActionInitialization类继承于G4VUserActionInitialization基类
包括构造、析构函数，以及BuildForMaster()函数和Build()函数
分别对应多线程模式下用户行为初始化和单线程模式用户行为初始化
*/
#ifndef ADActionInitialization_h
#define ADActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
class ADDetectorConstruction;


class ADActionInitialization : public G4VUserActionInitialization
{
public:
	ADActionInitialization();
	virtual ~ADActionInitialization();

	virtual void BuildForMaster() const;
	virtual void Build() const;

private:
	ADDetectorConstruction* fDetConstruction;
};


#endif // !ADActionInitialization_h
