//GEANT4 main����
//���ռ���ģ��
//G4������ͷ�ļ�
#ifdef G4MULTITHREADED      
#include "G4MTRunManager.hh"      // ���̹߳���
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh" //UI��������࣬���ڽ���ʽ
#include "G4RunManagerFactory.hh" //һ��ģʽ���й�����
#include "G4VisExecutive.hh"//���ӻ�����ͷ�ļ�
#include "G4UIExecutive.hh"//UI����ͷ�ļ�
#include "Randomize.hh"//�����������
#include "QGSP_BERT_HP.hh"//����
#include "ADPhysicsList.hh"
#include "G4Timer.hh"
//#include "G4MTRunManager.hh"
//�Զ���ͷ�ļ�
#include "ADActionInitialization.hh"
#include "ADDetectorConstruction.hh"

int main(int argc,char** argv)
{
	//��⻥��ģʽ�����û�в�����������UI�Ự
	G4UIExecutive* ui = 0;
	if (argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}
	G4Random::setTheEngine(new CLHEP::MTwistEngine);

#ifdef G4MULTITHREADED
	G4MTRunManager* runManager = new G4MTRunManager;
	G4int nThreads = G4Threading::G4GetNumberOfCores(); //�鿴����������߳���
	G4cout << " Total Threads is " << nThreads << G4endl;
	
	if (nThreads) {
		runManager->SetNumberOfThreads(1);
	}
#else
	G4RunManager* runManager = new G4RunManager;
#endif

	/*auto* runManager = 
		G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);*/
	//̽��������
	runManager->SetUserInitialization(new ADDetectorConstruction());
	//����ģ�͹���
	//G4VModularPhysicsList* physicsList = new QGSP_BERT_HP;
	//physicsList->SetVerboseLevel(4);
	runManager->SetUserInitialization(/*physicsList*/new ADPhysicsList);
	//�û���Ϊ��ʼ��
	runManager->SetUserInitialization(new ADActionInitialization());

	//���ӻ���ʼ��
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();
	// ��ȡ�û������������ָ��
	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	
	//�������
	/*CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine());
	G4long seed = time(NULL);
	CLHEP::HepRandom::setTheSeed(seed);*/

	G4String command = "/control/execute ";
	G4String fileName =  "init_vis.mac";
	UImanager->ApplyCommand(command + fileName);

	if (fileName == "init_vis.mac")
	{
		ui->SessionStart();
		delete ui;
	}
	//if (!ui)//û��ͼ�ν�������
	//{
	//	G4String command = "/control/execute ";
	//	G4String fileName = argv[1];
	//	UImanager->ApplyCommand(command + fileName);
	//}
	//else//��ͼ�ν�������
	//{
	//	UImanager->ApplyCommand("/control/execute init_vis.mac");
	//	ui->SessionStart();
	//	delete ui;
	//}
	delete visManager;
	delete runManager;

}