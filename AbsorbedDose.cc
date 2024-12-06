//GEANT4 main函数
//吸收剂量模拟
//G4公共类头文件
#ifdef G4MULTITHREADED      
#include "G4MTRunManager.hh"      // 多线程管理
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh" //UI界面管理类，用于交互式
#include "G4RunManagerFactory.hh" //一般模式运行管理类
#include "G4VisExecutive.hh"//可视化操作头文件
#include "G4UIExecutive.hh"//UI操作头文件
#include "Randomize.hh"//随机函数调用
#include "QGSP_BERT_HP.hh"//初步
#include "ADPhysicsList.hh"
#include "G4Timer.hh"
//#include "G4MTRunManager.hh"
//自定义头文件
#include "ADActionInitialization.hh"
#include "ADDetectorConstruction.hh"

int main(int argc,char** argv)
{
	//检测互动模式（如果没有参数）并定义UI会话
	G4UIExecutive* ui = 0;
	if (argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}
	G4Random::setTheEngine(new CLHEP::MTwistEngine);

#ifdef G4MULTITHREADED
	G4MTRunManager* runManager = new G4MTRunManager;
	G4int nThreads = G4Threading::G4GetNumberOfCores(); //查看计算机所有线程数
	G4cout << " Total Threads is " << nThreads << G4endl;
	
	if (nThreads) {
		runManager->SetNumberOfThreads(1);
	}
#else
	G4RunManager* runManager = new G4RunManager;
#endif

	/*auto* runManager = 
		G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);*/
	//探测器构建
	runManager->SetUserInitialization(new ADDetectorConstruction());
	//物理模型构建
	//G4VModularPhysicsList* physicsList = new QGSP_BERT_HP;
	//physicsList->SetVerboseLevel(4);
	runManager->SetUserInitialization(/*physicsList*/new ADPhysicsList);
	//用户行为初始化
	runManager->SetUserInitialization(new ADActionInitialization());

	//可视化初始化
	G4VisManager* visManager = new G4VisExecutive;
	visManager->Initialize();
	// 获取用户界面管理器的指针
	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	
	//随机种子
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
	//if (!ui)//没有图形界面运行
	//{
	//	G4String command = "/control/execute ";
	//	G4String fileName = argv[1];
	//	UImanager->ApplyCommand(command + fileName);
	//}
	//else//有图形界面运行
	//{
	//	UImanager->ApplyCommand("/control/execute init_vis.mac");
	//	ui->SessionStart();
	//	delete ui;
	//}
	delete visManager;
	delete runManager;

}