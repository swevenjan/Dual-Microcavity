#ifndef ADRunAction_h
#define ADRunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4Accumulable.hh"
#include "ADConstants.hh"
#include <array>
#include <vector>
class G4Run;

class ADRunAction : public G4UserRunAction
{
public:
	ADRunAction();
	virtual ~ADRunAction();

	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
	
	//run方法：将event的edep进行统计10个
	void AddEdep(G4double edep, int i) { fEdep[i] += edep; };

	void AddEdeair(G4double edep) { fEdepair += edep; };
	//run方法：SD专属

	//将对应栅元的edep添加至对应数组
	void AddMeaBoxEdep( G4double edep,G4int i);//将对应栅元的edep添加至对应数组
	// 将1000个栅元剂量求总和
	void AddTotalEdep(G4double edep);//将1000个栅元剂量求总和
	//整体盒子剂量求和
	void AddTotalEdep_meabox(G4double edep);
	//囊容器剂量求和
	void AddTotalEdep_nangbox(G4double edep);
	//囊剂量求和
	void AddTotalEdep_nang(G4double edep);
	//外腔剂量求和
	void AddTotalEdep_waiqiang(G4double edep);
	//内腔剂量求和
	void AddTotalEdep_neiqiang(G4double edep);

private:
	
	//统计step方式的run edep容器 对应40jx个统计网格

	std::array <G4double, 40> fEdep;
	G4double fEdepair;

	//G4Accumulable<G4double>
	/*std::vector<G4Accumulable<G4double>> fEdep;*/


    ////G4Accumulable<G4double>  删除
	//std::vector<G4Accumulable<G4double>> MeaBoxTotalEdep;//1000个hits的能量沉积记录

	//统计SD方式的run edep容器 对应1000个统计网格

	std::array<G4double, kNofEmCells> MeaBoxTotalEdep;//1000个hits的能量沉积记录
	G4double TotalEdep;//1000个小栅元总的沉积能量

	G4Accumulable<G4double> Edep_shanyuan;//G4Accumulable  栅元总的沉积能量
	G4Accumulable<G4double> Edep_meabox;//G4Accumulable  整体盒子总的沉积能量
	G4Accumulable<G4double> Edep_nangbox;//G4Accumulable  囊容器总的沉积能量
	G4Accumulable<G4double> Edep_nang;//G4Accumulable  囊总的沉积能量
	G4Accumulable<G4double> Edep_waiqiang;//G4Accumulable  外腔总的沉积能量
	G4Accumulable<G4double> Edep_neiqiang;//G4Accumulable  内腔总的沉积能量

	G4double TotalEdep_meabox;//整体盒子总的沉积能量
	G4double TotalEdep_nangbox;//囊容器总的沉积能量
	G4double TotalEdep_nang;//囊总的沉积能量
	G4double TotalEdep_waiqiang;//外腔总的沉积能量
    G4double TotalEdep_neiqiang;//内腔总的沉积能量

	G4double fMeaBoxMass;//小栅元体的质量
};

inline void ADRunAction::AddMeaBoxEdep( G4double edep,G4int i)
{
	MeaBoxTotalEdep[i] += edep;
}

inline void ADRunAction::AddTotalEdep(G4double edep)
{

	TotalEdep += edep;
	Edep_shanyuan += edep;
}

//整体盒子剂量求和
inline void ADRunAction::AddTotalEdep_meabox(G4double edep)
{
	TotalEdep_meabox += edep;
	Edep_meabox += edep;
}
//囊容器剂量求和
inline void ADRunAction::AddTotalEdep_nangbox(G4double edep)
{
	TotalEdep_nangbox += edep;
	Edep_nangbox += edep;
}
//囊剂量求和
inline void ADRunAction::AddTotalEdep_nang(G4double edep)
{
	TotalEdep_nang += edep;
	Edep_nang += edep;
}
//外腔剂量求和
inline void ADRunAction::AddTotalEdep_waiqiang(G4double edep)
{
	TotalEdep_waiqiang += edep;
	Edep_waiqiang += edep;
}
//内腔剂量求和
inline void ADRunAction::AddTotalEdep_neiqiang(G4double edep)
{
	TotalEdep_neiqiang += edep;
	Edep_neiqiang += edep;
}
#endif // !ADRunAction_h
