/*
B1ActionInitialization��̳���G4VUserActionInitialization����
�������졢�����������Լ�BuildForMaster()������Build()����
�ֱ��Ӧ���߳�ģʽ���û���Ϊ��ʼ���͵��߳�ģʽ�û���Ϊ��ʼ��
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
